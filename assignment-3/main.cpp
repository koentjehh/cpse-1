#include <array>
#include "hwlib.hpp"

constexpr double pow( double g, int n ){
   double result = 1;
   while( n > 0 ){
       result *= g;
       --n;
   }
   return result;
}

constexpr double fac( int n ){
   double result = 1;
   while( n > 0 ){
       result *= n;
       --n;
   }
   return result;
}

// sine

constexpr double sin( double a ){
   return 
      a 
      - pow( a, 3 ) / fac( 3 )
      + pow( a, 5 ) / fac( 5 )
      - pow( a, 7 ) / fac( 7 )
      + pow( a, 9 ) / fac( 9 )
      - pow( a, 11 ) / fac( 11 )
      + pow( a, 13 ) / fac( 13 )
      - pow( a, 15 ) / fac( 15 )
      + pow( a, 17 ) / fac( 17 )
      - pow( a, 19 ) / fac( 19 )
      + pow( a, 21 ) / fac( 21 )
      - pow( a, 23 ) / fac( 23 )
      + pow( a, 25 ) / fac( 25 );
}

constexpr double radians_from_degrees( int degrees ){
   return 2 * 3.14 * ( degrees / 360.0 );
}

constexpr int scaled_sine_from_degrees( int degrees ){
   return 30 * ( 1.0 + sin( radians_from_degrees( degrees )));
}

// cosine

constexpr double cos_radians_from_degrees( double degrees ){
	return sin( (3.14/2) - degrees );
}

constexpr int scaled_cosine_from_degrees( int degrees ){
	return 30 * ( 1.0 + cos_radians_from_degrees( degrees ) );
}

template< int N, typename T >
class lookup {
private:    
	std::array< T, N > values = {};

public: 
	template< typename F >
	constexpr lookup( F function ){
		for( int i = 0; i < N; ++i ){
			values[ i ] = function( i ); //10 * i
		}
	}

	constexpr T get( int n ) const {
		return values[ n ]; //n/10
	}
};

int main( void )
{	
	// lookup table
	constexpr auto sin_table = lookup<360, int>( scaled_sine_from_degrees );
	constexpr auto cos_table = lookup<360, int>( scaled_cosine_from_degrees );
	// wait for the PC console to start
	//hwlib::wait_ms( 500 );   
	hwlib::wait_ms( 2000 );   
   
	namespace target = hwlib::target;
   
	auto scl     = target::pin_oc( target::pins::scl );
	auto sda     = target::pin_oc( target::pins::sda );
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
	auto oled    = hwlib::glcd_oled( i2c_bus, 0x3c ); 
	
	
   
	//auto font    = hwlib::font_default_8x8();
	//auto display = hwlib::terminal_from( oled, font );
   
	//OLED output
	
	for(;;)
	{	
		oled.clear();
		
		for(int l = 0; l < 360; l = l + 30){
			// idee: grote cirkels met een getallen 1-12 erin/erop
			hwlib::circle clock_hours(hwlib::xy(((cos_table.get(l) + 2 )), (sin_table.get(l) + 2 )), 4);
			clock_hours.draw( oled );
		}
		
		oled.flush(); // toon op OLED

	}
}
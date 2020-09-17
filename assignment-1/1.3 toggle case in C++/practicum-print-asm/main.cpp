#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

extern "C" void application();

extern "C" char invert_char( char s )
{
	if( s >= 97 && s <= 122 ) // kleine letters
	{
		s = s - 32;
		return s;
	}
	else if( s >= 65 && s <= 90 ) // hoofdletter
	{
		s = s + 32;
		return s;
	}
	return s;
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}
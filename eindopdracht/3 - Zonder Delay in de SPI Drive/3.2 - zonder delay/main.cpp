#include "hwlib.hpp"
#include "spi_lib.hpp"

namespace target = hwlib::target;

int main( void ){
	
	int start;
	int end;
	int time;
	
	// wait for the terminal emulator to start up
	hwlib::wait_ms( 2'000 );
	hwlib::cout << "ST7789 demo\n" << hwlib::flush;   
   
	auto _sclk = hwlib::target::pin_out{ hwlib::target::pins::d3 };
	auto sclk = hwlib::invert( _sclk );
	auto mosi = hwlib::target::pin_out{ hwlib::target::pins::d4 };
   
	auto spi  = hwlib::spi_bit_banged_new( sclk, mosi, hwlib::pin_in_dummy );
      
	auto dc    = hwlib::target::pin_out{ hwlib::target::pins::d6 };
	auto & cs  = hwlib::pin_out_dummy;
	auto blk   = hwlib::target::pin_out{ hwlib::target::pins::d7 };
	auto rst   = hwlib::target::pin_out{ hwlib::target::pins::d5 };
   
	blk.write( 1 );blk.flush();

	auto display = hwlib::st7789_spi_dc_cs_rst( spi, dc, cs, rst );   
   
	for(;;){
		
		start = hwlib::now_us();
		
		display.clear( hwlib::red ); 

		end = hwlib::now_us();
		time = end - start;
		hwlib::cout << "clear() in us: " << time <<"\n";
		
		start = hwlib::now_us();
		
		display.flush();

		end = hwlib::now_us();
		time = end - start;
		hwlib::cout << "flush() in us: " << time <<"\n";
		


		display.clear( hwlib::green );
		display.flush();

		display.clear( hwlib::blue );
		display.flush();
	}
}
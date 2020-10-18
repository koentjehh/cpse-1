#include "hwlib.hpp"
#include "spi_lib.hpp"

namespace target = hwlib::target;

int main( void ){
	
	// disabling Watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	// wait for the terminal emulator to start up
	hwlib::wait_ms( 2'000 );
	hwlib::cout << "ST7789 demo\n" << hwlib::flush;   

	auto _sclk = hwlib::target::pin_out{ hwlib::target::pins::d3 };
	auto sclk = hwlib::invert( _sclk );
	auto mosi = hwlib::target::pin_out{ hwlib::target::pins::d4 };
   
	auto spi  = hwlib::spi_bit_banged_new( sclk, mosi);
      
	auto dc    = hwlib::target::pin_out{ hwlib::target::pins::d6 };
	auto & cs  = hwlib::pin_out_dummy;
	auto blk   = hwlib::target::pin_out{ hwlib::target::pins::d7 };
	auto rst   = hwlib::target::pin_out{ hwlib::target::pins::d5 };
   
	blk.write( 1 );blk.flush();

	auto display = hwlib::st7789_spi_dc_cs_rst( spi, dc, cs, rst );   
   
	for(;;){
				
		//display.clear( hwlib::red ); 
		display.clear( hwlib::red );
		display.flush();

		//display.clear( hwlib::green );
		display.clear( hwlib::white );
		display.flush();

		//display.clear( hwlib::blue );
		display.clear( hwlib::green );
		display.flush();
	}
}
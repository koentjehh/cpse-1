#include "hwlib.hpp"
//#define register 
//#include "sam.h"
//#undef register

namespace hwlib {

class spi_bit_banged_new : public spi_bus {
private:

	pin_direct_from_out_t sclk;
	pin_direct_from_out_t mosi;

	void write_and_read( 
		const size_t n, 
		const uint8_t data_out[],
		uint8_t data_in[] 
	) override {

	uint_fast8_t d = *data_out++;
			
	for( uint_fast8_t j = 0; j < 8; ++j ){
		// mosi = D4 = C 26
		// sclk = D3 = C 28
		// inverse: CODR = aan / SORD = uit 			
		if( ( ( d & 0x80 ) != 0 ) == 1 ){
			PIOC->PIO_SODR = 0x01 << 26; 
		}
		else{
			PIOC->PIO_CODR = 0x01 << 26; 
		}
						
		PIOC->PIO_CODR = 0x01 << 28; 
		
		d = d << 1;
		
			
		PIOC->PIO_SODR = 0x01 << 28; 
		
		}
	}      
   
public:

   st7789_bw( 
      pin_out & _sclk, 
      pin_out & _mosi/*,*/ 
      //pin_in  & _miso 
   ):
      //sclk( direct( _sclk ) ), 
      //mosi( direct( _mosi ) ), 
      //miso( direct( _miso ) )
      
      sclk( _sclk ), 
      mosi( _mosi )/*,*/ 
      /*miso( _miso )*/   {
      //sclk.write( 0 );
	  PIOC->PIO_SODR = 0x01 << 28; // uit
   }
   
}; // class spi_bit_banged_new    

}; // namespace hwlib
#include "hwlib.hpp"
#define register 
#include "sam.h"
#undef register

namespace hwlib {

/// bit-banged SPI bus implementation
///
/// This class implements a bit-banged master interface to a SPI bus.
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

   /// construct a bit-banged SPI bus from the sclk, miso and mosi pins
   ///
   /// This constructor creates a simple bit-banged SPI bus master
   /// from the sclk, miso and mosi pins. 
   ///
   /// The chip select pins for the individual chips supplied to the 
   /// write_and_read() functions.
   ///
   /// When the SPI bus is used for either only writing or only reading,
   /// the unused pin argument can be specified as pin_out_dummy or
   /// pin_in_dummy.
   spi_bit_banged_new( 
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
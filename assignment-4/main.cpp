#include "hwlib.hpp"

extern "C" void print_char( char c ){
   hwlib::cout << c;
}

extern "C" void decoder( const char * s );

extern "C" void application();

int main( void ){	
   
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );
   

   application();
}
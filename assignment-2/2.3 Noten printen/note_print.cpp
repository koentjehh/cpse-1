#include "note_print.hpp"

void note_print::play( const note & n ){
	hwlib::cout << "Frequency: " << n.frequency
				<< "\t"
				<< "Duration:  " << n.duration
				<< "\n";
}
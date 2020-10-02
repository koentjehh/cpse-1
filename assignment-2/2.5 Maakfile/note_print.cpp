#include "note_print.hpp"

void note_print::play( const note & n ){
	// plaatst noten in melody.cpp volgens format fur_elise.hpp
	melody_file << "\t p.play( note{ " << n.frequency
				<< ",\t" 			   << n.duration 
				<< "\t} );\n";
}


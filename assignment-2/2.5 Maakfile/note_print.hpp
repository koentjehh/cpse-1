#ifndef _NOTE_PRINT_HPP
#define _NOTE_PRINT_HPP

#include "note_player.hpp"

#include <fstream>

extern std::ofstream melody_file; //

class note_print : public note_player {
public:
    void play( const note & n ) override;
};

#endif
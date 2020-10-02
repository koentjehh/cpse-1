#ifndef _NOTE_PRINT_HPP
#define _NOTE_PRINT_HPP

#include "hwlib.hpp"
#include "note_player.hpp"

class note_print : public note_player {
public:
    void play( const note & n ) override;
};

#endif
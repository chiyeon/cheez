#ifndef MOVEMASKS_H
#define MOVEMASKS_H

#include "bitboard.h"

class MoveMasks
{
    Bitboard rook_moves[64];
    Bitboard bishop_moves[64];

    void calculate_all_rook_moves(Bitboard * moveset);
    void calculate_all_bishop_moves(Bitboard * moveset);

public:
    MoveMasks();
    Bitboard * get_rook_moves();
    Bitboard * get_bishop_moves();
};

#endif
#ifndef MOVE_H
#define MOVE_H

#include "constants.h"

struct Move
{
    const static Flag NOTHING           =    0b0;
    const static Flag EN_PASSANT        =    0b1;
    const static Flag PROMOTION         =   0b10;
    const static Flag FIRST_MOVE        =   0b11;
    const static Flag CASTLE            =  0b100;

    int from;
    int to;
    Piece piece;
    Piece captured;
    Flag flags;

    Move(int from, int to, Piece piece)
        : from(from)
        , to(to)
        , piece(piece)
        , captured(0)
        , flags(NOTHING)
    { }

    Move(int from, int to, Piece piece, Piece captured)
        : from(from)
        , to(to)
        , piece(piece)
        , captured(captured)
        , flags(NOTHING)
    { }

    Move(int from, int to, Piece piece, Piece captured, Flag flags)
        : from(from)
        , to(to)
        , piece(piece)
        , captured(captured)
        , flags(flags)
    { }

    bool operator == (const Move & move)
    {
        return 
            move.from == from &&
            move.to == to &&
            move.piece == piece &&
            move.flags == flags;
    }
};

#endif
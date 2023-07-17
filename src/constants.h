// represent bitboards as 64 bit unsigned integers
// it appears uint64_t == unsigned long long for emcc
#include <stdint.h>

using Bitboard = uint64_t;
using Magic = uint64_t;
using Piece = short;

#ifndef CONSTANTS_H
#define CONSTANTS_H

struct Constants
{
    const static int BOARD_SIZE = 8;
    const static int MAX_CHESS_MOVES_PER_POSITION = 218;
    const static int MAX_NUM_SQUARES = 27; // maximum number of moves that can be made by one piece in one turn
};

#endif
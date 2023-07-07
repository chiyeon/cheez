#ifndef GAME_H
#define GAME_H

#include <map>
#include "piece.h"
#include "movemasks.h"

class Game
{
    Piece board[64];
    Piece turn = Pieces::WHITE;
    Bitboard game_bitboard = 0;         // updates everytime move() is used
    // TODO bitboards for pieces, ie white_pawn_bitboard

public:
    MoveMasks movemasks;

    Game(std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    void read_fen(Piece * board, std::string fen);
    void print();
    Bitboard get_game_bitboard();
    Piece get(int index);
    Piece get(int x, int y);

    bool is_blacks_turn();
    bool is_whites_turn();
    Piece get_turn();

    // get moves()

private:
    static std::map<char, Piece> fen_to_piece;
};

#endif
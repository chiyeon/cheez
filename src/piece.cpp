#include "piece.h"
#include "constants.h"
#include "game.h"

short Pieces::get_color(Piece piece)
{
    return piece & FILTER_COLOR;
}

Piece Pieces::get_piece(Piece piece)
{
    return piece & FILTER_PIECE;
}

// std::string Pieces::name_full(Piece piece)
// {

// }

char Pieces::name_short(Piece piece)
{
    return piece_to_name_short[piece];
}

Piece Pieces::piece_from_name_short(char name)
{
    return name_short_to_piece[name];
}

Bitboard Pieces::get_pawn_moves(int x, int y, Game & game)
{
    Bitboard movement = Bitboards::get(x, y);
    bool is_black = game.is_blacks_turn();
    movement = is_black ? movement << 8 : movement >> 8;
    if ((y == 6 && is_black) || (y == 1 && !is_black)) 
        movement |= is_black ? movement << 8 : movement >> 8;
    return movement;
}

Bitboard Pieces::get_bishop_moves(int x, int y, Game & game)
{
    return game.movemasks.get_bishop_moves()[x + y * 8];
}

// std::map<Piece, std::string> Pieces::piece_to_name_full = {
//     {WHITE | PAWN, 'white pawn'},
//     {WHITE | KNIGHT, 'white knight'},
//     {WHITE | BISHOP, 'white bishop'},
//     {WHITE | ROOK, 'white rook'},
//     {WHITE | QUEEN, 'white queen'},
//     {WHITE | KING, 'white king'},
//     {BLACK | PAWN, 'black pawn'},
//     {BLACK | KNIGHT, 'black knight'},
//     {BLACK | BISHOP, 'black bishop'},
//     {BLACK | ROOK, 'black rook'},
//     {BLACK | QUEEN, 'black queen'},
//     {BLACK | KING, 'black king'},
// };

std::map<Piece, char> Pieces::piece_to_name_short = {
    {WHITE | PAWN, 'P'},
    {WHITE | KNIGHT, 'N'},
    {WHITE | BISHOP, 'B'},
    {WHITE | ROOK, 'R'},
    {WHITE | QUEEN, 'Q'},
    {WHITE | KING, 'K'},
    {BLACK | PAWN, 'p'},
    {BLACK | KNIGHT, 'n'},
    {BLACK | BISHOP, 'b'},
    {BLACK | ROOK, 'r'},
    {BLACK | QUEEN, 'q'},
    {BLACK | KING, 'k'},
};

std::map<char, Piece> Pieces::name_short_to_piece = {
    {'P', WHITE | PAWN},
    {'N', WHITE | KNIGHT},
    {'B', WHITE | BISHOP},
    {'R', WHITE | ROOK},
    {'Q', WHITE | QUEEN},
    {'K', WHITE | KING},
    {'p', BLACK | PAWN},
    {'n', BLACK | KNIGHT},
    {'b', BLACK | BISHOP},
    {'r', BLACK | ROOK},
    {'q', BLACK | QUEEN},
    {'k', BLACK | KING}
};

// will eventually include get_[...]_moves definitions
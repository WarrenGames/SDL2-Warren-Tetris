#ifndef DRAW_PIECE_H
#define DRAW_PIECE_H

namespace sdl2{ class RendererWindow; }
struct ActivePiece;
class Piece;
class SquaresDrawing;

void drawPiece(sdl2::RendererWindow& rndWnd, const ActivePiece& activeP, const Piece& piece, SquaresDrawing& sqrDraw);

#endif //DRAW_PIECE_H
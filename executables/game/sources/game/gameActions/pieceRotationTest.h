#ifndef PIECE_ROTATION_TEST_H
#define PIECE_ROTATION_TEST_H

#include <cstdlib>

struct ActivePiece;
class Piece;
template<typename>class MatrixTemp2D;
struct SquareData;

bool pieceCanRotateClockwise(const ActivePiece& activeP, const Piece& piece, const MatrixTemp2D<SquareData>& matrix);

bool pieceCanRotateAntiClockwise(const ActivePiece& activeP, const Piece& piece, const MatrixTemp2D<SquareData>& matrix);

bool x_coord_correct(int x_pos, const MatrixTemp2D<SquareData>& matrix);

bool y_coord_correct(int y_pos, const MatrixTemp2D<SquareData>& matrix);

void rotateIndexClockwise(size_t& rotationIndex);

void rotateIndexAntiClockwise(size_t& rotationIndex);

#endif //PIECE_ROTATION_TEST_H
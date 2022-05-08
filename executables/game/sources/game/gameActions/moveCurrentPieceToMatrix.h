#ifndef MOVE_CURRENT_PIECE_TO_MATRIX_H
#define MOVE_CURRENT_PIECE_TO_MATRIX_H

struct ActivePiece;
class Piece;
template<typename>class MatrixTemp2D;
struct SquareData;
struct ScanLinesInfos;

void moveCurrentPieceToMatrix(const ActivePiece& pieceData, const Piece& piece, MatrixTemp2D<SquareData>& matrix, ScanLinesInfos& scanLinesInf);

#endif //MOVE_CURRENT_PIECE_TO_MATRIX_H
#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include "matrices/matrix2D.h"
#include "game/objects/squareData.h"
#include "game/consts/constexpr.h"
#include <array>

class Piece
{
private:
	unsigned colorIndex;
	std::array<MatrixTemp2D<SquareData>, ROT_IND::MAX > pieceMatrices;

public:
	explicit Piece(const MatrixTemp2D<SquareData>& northMatrix, unsigned color);
	~Piece() = default;
	Piece( const Piece& ) = default;
	Piece& operator= ( const Piece& ) = default;
	
	unsigned getColor() const;
	size_t width(size_t index) const;
	size_t height(size_t index) const;
	
	void makeMatricesRotatedChildren();
	void fillSubMatrices(const MatrixTemp2D<SquareData>& srcMatrix, MatrixTemp2D<SquareData>& destMat);
	
	void outputMatrices() const;
	
	bool getPresenceSquare(size_t matrixIndex, size_t width, size_t height) const;
};

int getReverseIndex(int size, int srcIndex);

size_t getNextMatrixClockwiseOrder(size_t currentIndex);
size_t getNextMatrixAntiClockwiseOrder(size_t currentIndex);

#endif //PIECE_CLASS_H
#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include "matrices/matrix2D.h"
#include "game/objects/squareData.h"
#include "game/consts/constexpr.h"
#include <array>

class Piece
{
private:
	std::size_t colorIndex;
	std::array<MatrixTemp2D<SquareData>, ROT_IND::MAX > pieceMatrices;

public:
	explicit Piece(const MatrixTemp2D<SquareData>& northMatrix, std::size_t color);
	~Piece() = default;
	Piece( const Piece& ) = default;
	Piece& operator= ( const Piece& ) = default;
	
	std::size_t getColor() const;
	std::size_t width(std::size_t index) const;
	std::size_t height(std::size_t index) const;
	
	void makeMatricesRotatedChildren();
	void fillSubMatrices(const MatrixTemp2D<SquareData>& srcMatrix, MatrixTemp2D<SquareData>& destMat);
	
	void outputMatrices() const;
	
	bool getPresenceSquare(std::size_t matrixIndex, std::size_t width, std::size_t height) const;
};

int getReverseIndex(int size, int srcIndex);

std::size_t getNextMatrixClockwiseOrder(std::size_t currentIndex);
std::size_t getNextMatrixAntiClockwiseOrder(std::size_t currentIndex);

#endif //PIECE_CLASS_H
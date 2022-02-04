#include "game/objects/pieceClass.h"
#include <iostream>

Piece::Piece(const MatrixTemp2D<SquareData>& northMatrix, unsigned color):
	colorIndex{color},
	pieceMatrices{northMatrix, northMatrix, northMatrix, northMatrix}
{
	makeMatricesRotatedChildren();
	fillSubMatrices(pieceMatrices[0], pieceMatrices[1]);
	fillSubMatrices(pieceMatrices[1], pieceMatrices[2]);
	fillSubMatrices(pieceMatrices[2], pieceMatrices[3]);
}

unsigned Piece::getColor() const
{
	return colorIndex;
}

int Piece::width(size_t index) const
{
	assert( index < pieceMatrices.size() );
	return static_cast<int>( pieceMatrices[index].width() );
}

int Piece::height(size_t index) const
{
	assert( index < pieceMatrices.size() );
	return static_cast<int>( pieceMatrices[index].height() );
}

void Piece::makeMatricesRotatedChildren()
{
	pieceMatrices[ROT_IND::EAST].reverseDimensions();
	pieceMatrices[ROT_IND::WEST].reverseDimensions();
}

void Piece::fillSubMatrices(const MatrixTemp2D<SquareData>& srcMatrix, MatrixTemp2D<SquareData>& destMat)
{
	for( size_t dest_x{0} ; dest_x < destMat.width() ; ++dest_x )
	{
		for( size_t dest_y{0} ; dest_y < destMat.height() ; ++dest_y )
		{
			destMat(dest_x, dest_y) = srcMatrix(dest_y, getReverseIndex(static_cast<int>(srcMatrix.height()), static_cast<int>(dest_x) ) );
		}
	}
}

void Piece::outputMatrices() const
{
	for(auto const &it : pieceMatrices )
	{
		for(size_t height{0} ; height < it.height() ; ++height )
		{
			for( size_t width{0} ; width < it.width() ; ++width )
			{
				std::cout << "[" << it(width, height).filled << "]  ";
			}
			std::cout << '\n';
		}
		std::cout << "----------" << '\n';
	}
}

bool Piece::getPresenceSquare(size_t matrixIndex, size_t width, size_t height) const
{
	assert( matrixIndex < pieceMatrices.size() );
	return pieceMatrices[matrixIndex](width, height).filled;
}

int getReverseIndex(int size, int srcIndex)
{
	return -srcIndex + size - 1;
}

size_t getNextMatrixClockwiseOrder(size_t currentIndex)
{
	if( currentIndex < ROT_IND::MAX - 1 )
		return currentIndex + 1;
	else
		return 0;
}

size_t getNextMatrixAntiClockwiseOrder(size_t currentIndex)
{
	if( currentIndex > 0 )
		return currentIndex - 1;
	else
		return ROT_IND::MAX - 1;
}

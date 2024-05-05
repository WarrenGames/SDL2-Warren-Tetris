#include "game/objects/pieceClass.h"
#include <iostream>

Piece::Piece(const MatrixTemp2D<SquareData>& northMatrix, std::size_t color):
	colorIndex{color},
	pieceMatrices{northMatrix, northMatrix, northMatrix, northMatrix}
{
	makeMatricesRotatedChildren();
	fillSubMatrices(pieceMatrices[0], pieceMatrices[1]);
	fillSubMatrices(pieceMatrices[1], pieceMatrices[2]);
	fillSubMatrices(pieceMatrices[2], pieceMatrices[3]);
}

std::size_t Piece::getColor() const
{
	return colorIndex;
}

std::size_t Piece::width(std::size_t index) const
{
	assert( index < pieceMatrices.size() );
	return static_cast<int>( pieceMatrices[index].width() );
}

std::size_t Piece::height(std::size_t index) const
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
	for( std::size_t dest_x{0} ; dest_x < destMat.width() ; ++dest_x )
	{
		for( std::size_t dest_y{0} ; dest_y < destMat.height() ; ++dest_y )
		{
			destMat(dest_x, dest_y) = srcMatrix(dest_y, getReverseIndex(static_cast<int>(srcMatrix.height()), static_cast<int>(dest_x) ) );
		}
	}
}

void Piece::outputMatrices() const
{
	for(auto const &it : pieceMatrices )
	{
		for(std::size_t height{0} ; height < it.height() ; ++height )
		{
			for( std::size_t width{0} ; width < it.width() ; ++width )
			{
				std::cout << "[" << it(width, height).filled << "]  ";
			}
			std::cout << '\n';
		}
		std::cout << "----------" << '\n';
	}
}

bool Piece::getPresenceSquare(std::size_t matrixIndex, std::size_t width, std::size_t height) const
{
	assert( matrixIndex < pieceMatrices.size() );
	return pieceMatrices[matrixIndex](width, height).filled;
}

int getReverseIndex(int size, int srcIndex)
{
	return -srcIndex + size - 1;
}

std::size_t getNextMatrixClockwiseOrder(std::size_t currentIndex)
{
	if( currentIndex < ROT_IND::MAX - 1 )
		return currentIndex + 1;
	else
		return 0;
}

std::size_t getNextMatrixAntiClockwiseOrder(std::size_t currentIndex)
{
	if( currentIndex > 0 )
		return currentIndex - 1;
	else
		return ROT_IND::MAX - 1;
}

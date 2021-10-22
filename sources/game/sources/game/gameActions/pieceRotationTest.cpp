#include <array>
#include "game/consts/constexpr.h"
#include "matrices/matrix2D.h"
#include "game/objects/randomSingleton.h"
#include "game/objects/loadedPieces.h"
#include "game/objects/activePieceThings.h"
#include "game/gameActions/pieceRotationTest.h"

bool pieceCanRotateClockwise(const ActivePiece& activeP, const Piece& piece, const MatrixTemp2D<SquareData>& matrix)
{
	for(int width{0} ; width < piece.width(getNextMatrixClockwiseOrder(activeP.rotateIndex)) ; ++width )
	{
		for(int height{0} ; height < piece.height(getNextMatrixClockwiseOrder(activeP.rotateIndex)) ; ++height )
		{
			if( piece.getPresenceSquare(getNextMatrixClockwiseOrder(activeP.rotateIndex), width, height ) > 0 )
			{
				if( ! x_coord_correct(activeP.posx + width, matrix) 
				 || ! y_coord_correct(activeP.posy + height, matrix) )
				{
					return false;
				}
				if( x_coord_correct(activeP.posx + width, matrix) && y_coord_correct(activeP.posy + height, matrix) )
				{
					if( matrix(activeP.posx + width, activeP.posy + height).filled )
						return false;
				}
			}
		}
	}
	return true;
}

bool pieceCanRotateAntiClockwise(const ActivePiece& activeP, const Piece& piece, const MatrixTemp2D<SquareData>& matrix)
{
	for(int width{0} ; width < piece.width(getNextMatrixAntiClockwiseOrder(activeP.rotateIndex)) ; ++width )
	{
		for(int height{0} ; height < piece.height(getNextMatrixAntiClockwiseOrder(activeP.rotateIndex)) ; ++height )
		{
			if( piece.getPresenceSquare(getNextMatrixAntiClockwiseOrder(activeP.rotateIndex), width, height ) > 0 )
			{
				if( ! x_coord_correct(activeP.posx + width, matrix) 
				 || ! y_coord_correct(activeP.posy + height, matrix) )
				{
					return false;
				}
				if( x_coord_correct(activeP.posx + width, matrix) && y_coord_correct(activeP.posy + height, matrix) )
				{
					if( matrix(activeP.posx + width, activeP.posy + height).filled )
						return false;
				}
			}
			
		}
	}
	return true;
}

bool x_coord_correct(int x_pos, const MatrixTemp2D<SquareData>& matrix)
{
	return x_pos >= 0 && x_pos < static_cast<int>(matrix.width());
}

bool y_coord_correct(int y_pos, const MatrixTemp2D<SquareData>& matrix)
{
	return y_pos >= 0 && y_pos < static_cast<int>(matrix.height());
}

void rotateIndexClockwise(size_t& rotationIndex)
{
	if( rotationIndex < ROT_IND::WEST )
		rotationIndex++;
	else
		rotationIndex = 0;
}

void rotateIndexAntiClockwise(size_t& rotationIndex)
{
	if( rotationIndex > 0 )
		rotationIndex--;
	else
		rotationIndex = ROT_IND::WEST;
}
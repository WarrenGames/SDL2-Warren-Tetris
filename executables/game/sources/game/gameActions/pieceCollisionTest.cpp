#include "game/gameActions/pieceCollisionTest.h"
#include "game/objects/globalGameObject.h"

bool isPieceInCollisionWithMat(const GameObject& gameObj, int xmove, int ymove)
{
	for( std::size_t height{0} ; height < gameObj.matrix.height() ; ++height )
	{
		for( std::size_t width{0} ; width < gameObj.matrix.width() ; ++width )
		{
			if( gameObj.matrix(width, height).filled )
			{
				if( isPieceInCollisionWithMatSquare(gameObj, width, height, xmove, ymove) )
					return true;
			}
		}
	}
	return false;
}

bool isPieceInCollisionWithMatSquare(const GameObject& gameObj, std::size_t x_mat_obs, std::size_t y_mat_obs, int xdecal, int ydecal)
{
	for( std::size_t piece_x{0} ; piece_x < gameObj.getCurrentPieceWidth() ; ++piece_x )
	{
		for( std::size_t piece_y{0} ; piece_y < gameObj.getCurrentPieceHeight() ; ++piece_y )
		{
			if( gameObj.isSquarePresent(piece_x, piece_y)
				&& gameObj.currentPiece.posx + static_cast<int>(piece_x) + xdecal == static_cast<int>(x_mat_obs) 
				&& gameObj.currentPiece.posy + static_cast<int>(piece_y) + ydecal == static_cast<int>(y_mat_obs) )
				return true;
		}
	}
	return false;
}

bool isPieceInCollisionWVerticalBorders(const GameObject& gameObj, int xmove)
{
	for( std::size_t piece_x{0} ; piece_x < gameObj.getCurrentPieceWidth() ; ++piece_x )
	{
		for( std::size_t piece_y{0} ; piece_y < gameObj.getCurrentPieceHeight() ; ++piece_y )
		{
			if( gameObj.isSquarePresent(piece_x, piece_y) )
			{
				if(! ( gameObj.currentPiece.posx + static_cast<int>(piece_x) + xmove >= 0 
						&& gameObj.currentPiece.posx + static_cast<int>(piece_x) + xmove < static_cast<int>(gameObj.matrix.width() ) ) )
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool hasPieceReachedBottom(const GameObject& gameObj)
{
	for( std::size_t piece_x{0} ; piece_x < gameObj.getCurrentPieceWidth() ; ++piece_x )
	{
		for( std::size_t piece_y{0} ; piece_y < gameObj.getCurrentPieceHeight() ; ++piece_y )
		{
			if( gameObj.isSquarePresent(piece_x, piece_y) )
			{
				if( gameObj.currentPiece.posy + static_cast<int>(piece_y) + 1 >= static_cast<int>( gameObj.matrix.height() ) )
				{
					return true;
				}
			}
		}
	}
	return false;
}
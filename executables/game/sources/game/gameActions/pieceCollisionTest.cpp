#include <array>
#include "game/objects/globalGameObject.h"
#include "game/gameActions/pieceCollisionTest.h"

bool isPieceInCollisionWithMat(const GameObject& gameObj, int xmove, int ymove)
{
	for( int height{0} ; height < static_cast<int>(gameObj.matrix.height()) ; ++height )
	{
		for( int width{0} ; width < static_cast<int>(gameObj.matrix.width()) ; ++width )
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

bool isPieceInCollisionWithMatSquare(const GameObject& gameObj, int x_mat_obs, int y_mat_obs, int xdecal, int ydecal)
{
	for( int piece_x{0} ; piece_x < gameObj.getCurrentPieceWidth() ; ++piece_x )
	{
		for( int piece_y{0} ; piece_y < gameObj.getCurrentPieceHeight() ; ++piece_y )
		{
			if( gameObj.isSquarePresent(piece_x, piece_y) > 0 
				&& gameObj.currentPiece.posx + piece_x + xdecal == x_mat_obs 
				&& gameObj.currentPiece.posy + piece_y + ydecal == y_mat_obs )
				return true;
		}
	}
	return false;
}

bool isPieceInCollisionWVerticalBorders(const GameObject& gameObj, int xmove)
{
	for( int piece_x{0} ; piece_x < gameObj.getCurrentPieceWidth() ; ++piece_x )
	{
		for( int piece_y{0} ; piece_y < gameObj.getCurrentPieceHeight() ; ++piece_y )
		{
			if( gameObj.isSquarePresent(piece_x, piece_y) )
			{
				if(! ( gameObj.currentPiece.posx + piece_x + xmove >= 0 
						&& gameObj.currentPiece.posx + piece_x + xmove < static_cast<int>(gameObj.matrix.width() ) ) )
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
	for( int piece_x{0} ; piece_x < gameObj.getCurrentPieceWidth() ; ++piece_x )
	{
		for( int piece_y{0} ; piece_y < gameObj.getCurrentPieceHeight() ; ++piece_y )
		{
			if( gameObj.isSquarePresent(piece_x, piece_y) )
			{
				if( gameObj.currentPiece.posy + piece_y >= static_cast<int>(gameObj.matrix.height()) - 1 )
					return true;
			}
		}
	}
	return false;
}
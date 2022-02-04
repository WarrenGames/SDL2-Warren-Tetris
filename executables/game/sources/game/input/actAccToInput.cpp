#include <array>
#include "game/objects/globalGameObject.h"
#include "game/input/userInput.h"
#include "game/gameActions/pieceRotationTest.h"
#include "game/gameActions/pieceCollisionTest.h"
#include "game/input/actAccToInput.h"

void actAccToPlayerInput(UserInput& inp, GameObject& gameObj)
{
	moveCurrentPieceToLeft(inp, gameObj);
	moveCurrentPieceToRight(inp, gameObj);
	moveCurrentPieceDowner(inp, gameObj);
	rotateClockwisePiece(inp, gameObj);
	rotateAntiClockwisePiece(inp, gameObj);
}

void moveCurrentPieceToLeft(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(KEY::MV_PIECE_LEFT) )
	{
		if( ! isPieceInCollisionWithMat(gameObj, -1, 0) && ! isPieceInCollisionWVerticalBorders(gameObj, -1))
		{
			gameObj.currentPiece.posx--;
		}
		inp.setKeyState(KEY::MV_PIECE_LEFT, false);
	}
}

void moveCurrentPieceToRight(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(KEY::MV_PIECE_RIGHT) )
	{
		if( ! isPieceInCollisionWithMat(gameObj, 1, 0) && ! isPieceInCollisionWVerticalBorders(gameObj, 1) )
		{
			gameObj.currentPiece.posx++;
		}
		inp.setKeyState(KEY::MV_PIECE_RIGHT, false);
	}
}

void moveCurrentPieceDowner(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(KEY::DOWN_FASTER) )
	{
		if( ! isPieceInCollisionWithMat(gameObj, 0, 1) && ! hasPieceReachedBottom(gameObj) )
		{
			gameObj.currentPiece.posy++;
		}
		inp.setKeyState(KEY::DOWN_FASTER, false);
	}
}

void rotateClockwisePiece(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(KEY::ROT_PIECE_CWISE) )
	{
		if( pieceCanRotateClockwise(gameObj.currentPiece, gameObj.getCurrentPiece(), gameObj.matrix) )
		{
			rotateIndexClockwise(gameObj.currentPiece.rotateIndex);
		}
		inp.setKeyState(KEY::ROT_PIECE_CWISE, false);
	}
}

void rotateAntiClockwisePiece(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(KEY::ROT_PIECE_ANTICWISE) )
	{
		if( pieceCanRotateAntiClockwise(gameObj.currentPiece, gameObj.getCurrentPiece(), gameObj.matrix) )
		{
			rotateIndexAntiClockwise(gameObj.currentPiece.rotateIndex);
		}
		inp.setKeyState(KEY::ROT_PIECE_ANTICWISE, false);
	}
}

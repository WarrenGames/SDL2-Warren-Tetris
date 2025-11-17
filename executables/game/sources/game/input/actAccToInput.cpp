#include "game/input/actAccToInput.h"
#include "game/objects/globalGameObject.h"
#include "game/input/userInput.h"
#include "game/gameActions/pieceRotationTest.h"
#include "game/gameActions/pieceCollisionTest.h"

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
	if( inp.getKeyState(Key::MovePieceLeft) )
	{
		if( ! isPieceInCollisionWithMat(gameObj, -1, 0) && ! isPieceInCollisionWVerticalBorders(gameObj, -1))
		{
			gameObj.currentPiece.posx--;
		}
		inp.setKeyState(Key::MovePieceLeft, false);
	}
}

void moveCurrentPieceToRight(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(Key::MovePieceRight) )
	{
		if( ! isPieceInCollisionWithMat(gameObj, 1, 0) && ! isPieceInCollisionWVerticalBorders(gameObj, 1) )
		{
			gameObj.currentPiece.posx++;
		}
		inp.setKeyState(Key::MovePieceRight, false);
	}
}

void moveCurrentPieceDowner(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(Key::DownFaster) )
	{
		if( ! isPieceInCollisionWithMat(gameObj, 0, 1) && ! hasPieceReachedBottom(gameObj) )
		{
			gameObj.currentPiece.posy++;
		}
		inp.setKeyState(Key::DownFaster, false);
	}
}

void rotateClockwisePiece(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(Key::RotatePieceClockwise) )
	{
		if( pieceCanRotateClockwise(gameObj.currentPiece, gameObj.getCurrentPiece(), gameObj.matrix) )
		{
			rotateIndexClockwise(gameObj.currentPiece.rotateIndex);
		}
		inp.setKeyState(Key::RotatePieceClockwise, false);
	}
}

void rotateAntiClockwisePiece(UserInput& inp, GameObject& gameObj)
{
	if( inp.getKeyState(Key::RotatePieceAntiClockWise) )
	{
		if( pieceCanRotateAntiClockwise(gameObj.currentPiece, gameObj.getCurrentPiece(), gameObj.matrix) )
		{
			rotateIndexAntiClockwise(gameObj.currentPiece.rotateIndex);
		}
		inp.setKeyState(Key::RotatePieceAntiClockWise, false);
	}
}

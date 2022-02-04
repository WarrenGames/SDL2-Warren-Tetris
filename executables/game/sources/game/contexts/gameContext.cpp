#include "game/contexts/gameContext.h"
#include "game/objects/globalGameObject.h"
#include "game/input/userInput.h"
#include "game/structs/timeOptionsStruct.h"
#include "commonFiles/types/essentials.h"
#include "game/input/actAccToInput.h"
#include "game/gameActions/pieceCollisionTest.h"
#include "game/gameActions/removeCompleteLines.h"
#include "game/gameActions/moveCurrentPieceToMatrix.h"
#include "game/gameActions/checkGameOver.h"
#include "game/scores/bestScores.h"
#include "game/consts/sdlColors.h"

void runTetrisGame(Essentials& essentials, unsigned skillLevel, TimeOptions timeOpt)
{
	GameObject gameObj{essentials, skillLevel, timeOpt};
	bool quitGame{false};
	
	gameMainLoop(essentials, timeOpt, gameObj, quitGame);
	
	bestScores::bestScoresContext(essentials, gameObj.playScore, skillLevel);
	
	essentials.inp.setEscapeKeyFalse();
	essentials.inp.setWindowCloseFalse();
}

void gameMainLoop(Essentials& essentials, TimeOptions& timeOpt, GameObject& gameObj, bool& quitGame)
{
	while( false == quitGame )
	{
		essentials.inp.updateEvents(gameObj.keycodes);
		quitGameIfWindClose(essentials, quitGame);
		actAccToPlayerInput(essentials.inp, gameObj);
		makeCurrentPieceGoDowner(gameObj, timeOpt, quitGame);
		modifyTimeData(timeOpt);
		removeCompleteLinesIfAny(essentials.logs, essentials.rndWnd, gameObj.matrix, gameObj.playScore, gameObj.scanLinesInf);
		gameObj.updateChronoTimer(essentials);
		gameObj.updateSpeedText(essentials, timeOpt);
		drawEverything(essentials, gameObj); 
	}
}

void makeCurrentPieceGoDowner(GameObject& gameObj, TimeOptions& timeOpt, bool& quitGame)
{
	if( gameObj.pieceFallTime.hasTimeElapsed(timeOpt.fallDelay) )
	{
		if( !isPieceInCollisionWithMat(gameObj, 0, 1) && !hasPieceReachedBottom(gameObj ) )
		{
			gameObj.moveCurrentPieceDowner();
		}
		else{
			gameObj.movePieceToMatrix();
			gameObj.resetCurrentPiece();
			setGameOverIfMatrixFilled(gameObj.matrix, quitGame);
		}
		gameObj.pieceFallTime.joinTimePoints();
	}
}

void drawEverything(Essentials& essentials, GameObject& gameObj)
{
	if( essentials.drawFrequency.hasTimeElapsed(10) )
	{
		essentials.rndWnd.clearScreen(BLACK_COL);
		gameObj.drawEverything(essentials);
		essentials.rndWnd.displayRenderer();
		essentials.drawFrequency.joinTimePoints();
	}
}

void quitGameIfWindClose(Essentials& essentials, bool& quitGame)
{
	if( essentials.inp.getWindowClose() || essentials.inp.getEscapeState() )
	{
		quitGame = true;
	}
}

void modifyTimeData(TimeOptions& timeOpt)
{
	timeOpt.changePiecesSpeedIfAny();
}
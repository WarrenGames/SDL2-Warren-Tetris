#ifndef GLOBAL_GAME_OBJECT_H
#define GLOBAL_GAME_OBJECT_H

#include "game/consts/constexpr.h"
#include "matrices/matrix2D.h"
#include "time/accurateTime.h"
#include "game/drawing/borderDrawing.h"
#include "game/drawing/squareTexturing.h"
#include "game/objects/randomSingleton.h"
#include "game/objects/loadedPieces.h"
#include "game/objects/activePieceThings.h"
#include "game/structs/scanLinesInfos.h"
#include "game/drawing/playerScore.h"
#include "game/objects/chronoTimer.h"
#include "runGame/menus/keycodesInfos.h"
#include "game/objects/pieceFallSpeedInterface.h"
#include "SDL.h"

struct Essentials;

struct GameObject
{
	KeycodesInfos keycodes;
	AccurateTimeDelay drawingFreq;
	AccurateTimeDelay pieceFallTime;
	BorderDrawing borderDraw;
	SquaresDrawing sqrDraw;
	LoadedPieces allPieces;
	MatrixTemp2D<SquareData> matrix;
	RandomSingleton random;
	ActivePiece currentPiece;
	ScanLinesInfos scanLinesInf;
	PlayerScore playScore;
	ChronoTimer chronoTimer;
	SpeedInterface speedInterface;
	
//Member functions	
	GameObject(Essentials& essentials, unsigned skillLevel, const TimeOptions& timeOptions);
	Piece getCurrentPiece() const;
	Piece& getCurrentPiece();
	
	bool isSquarePresent(int x_sqr, int y_sqr) const;
	
	int getCurrentPieceWidth() const;
	int getCurrentPieceHeight() const;
	
	void moveCurrentPieceDowner();
	
	void movePieceToMatrix();
	void resetCurrentPiece();
	
	void drawEverything(Essentials& essentials);
	
	void updateChronoTimer(Essentials& essentials);
	void updateSpeedText(Essentials& essentials, const TimeOptions& timeOptions);
};

#endif //GLOBAL_GAME_OBJECT_H
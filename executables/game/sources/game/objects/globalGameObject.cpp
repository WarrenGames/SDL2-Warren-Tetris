#include "game/objects/globalGameObject.h"
#include "commonFiles/types/essentials.h"
#include "game/gameActions/moveCurrentPieceToMatrix.h"
#include "game/drawing/drawPiece.h"
#include "game/drawing/drawMatrix.h"


GameObject::GameObject(Essentials& essentials, unsigned skillLevel, const TimeOptions& timeOptions):
	keycodes{essentials.logs, essentials.prefPath},
	drawingFreq{},
	pieceFallTime{},
	borderDraw{essentials.logs, essentials.rndWnd},
	sqrDraw{essentials.logs, essentials.rndWnd},
	allPieces{essentials.logs, skillLevel},
	matrix{BIGMAT_WIDTH, BIGMAT_HEIGHT},
	random{{Difference{0, static_cast<int>(allPieces.size()) - 1}}},
	currentPiece{random, allPieces},
	scanLinesInf{},
	playScore{essentials.logs, essentials.rndWnd},
	chronoTimer{essentials},
	speedInterface{essentials, timeOptions}
{
	
}

const Piece& GameObject::getCurrentPiece() const
{
	return allPieces.getPiece(currentPiece.pieceIndex);
}

Piece& GameObject::getCurrentPiece()
{
	return allPieces.getPiece(currentPiece.pieceIndex);
}

bool GameObject::isSquarePresent(std::size_t x_sqr, std::size_t y_sqr) const
{
	return getCurrentPiece().getPresenceSquare(currentPiece.rotateIndex, x_sqr, y_sqr);
}

std::size_t GameObject::getCurrentPieceWidth() const
{
	return getCurrentPiece().width(currentPiece.rotateIndex);
}

std::size_t GameObject::getCurrentPieceHeight() const
{
	return getCurrentPiece().height(currentPiece.rotateIndex);
}

void GameObject::moveCurrentPieceDowner()
{
	currentPiece.posy++;
	scanLinesInf.canScanToRemoveLines = false;
	scanLinesInf.bottomLine = 0;
}

void GameObject::movePieceToMatrix()
{
	moveCurrentPieceToMatrix(currentPiece, getCurrentPiece(), matrix, scanLinesInf);
}

void GameObject::resetCurrentPiece()
{
	currentPiece.resetPieceValues(random, allPieces);
}

void GameObject::drawEverything(Essentials& essentials)
{
	borderDraw.drawAllBorders(essentials.rndWnd);
	drawPiece(essentials.rndWnd, currentPiece, getCurrentPiece(), sqrDraw);
	drawMatrix(essentials.rndWnd, sqrDraw, matrix);
	playScore.drawScore(essentials.rndWnd);
	chronoTimer.drawText(essentials);
	speedInterface.drawSpeedText(essentials);
}

void GameObject::updateChronoTimer(Essentials& essentials)
{
	chronoTimer.mesureElapsedTime();
	chronoTimer.changeGraphicalTextIfNeeded(essentials);
}

void GameObject::updateSpeedText(Essentials& essentials, const TimeOptions& timeOptions)
{
	speedInterface.resetText(essentials, timeOptions);
}
#include "game/objects/activePieceThings.h"
#include "game/objects/randomSingleton.h"
#include "game/objects/loadedPieces.h"

ActivePiece::ActivePiece(RandomSingleton& rand, const LoadedPieces& allPieces):
	pieceIndex{rand.getRandomNumber(0)}, 
	rotateIndex{ROT_IND::NORTH}, 
	posx{BIGMAT_WIDTH/2 - 1}, 
	posy{0}, 
	colorIndex{allPieces.getPiece(pieceIndex).getColor()}
{
	
}

void ActivePiece::resetPieceValues(RandomSingleton& rand, const LoadedPieces& pieces)
{
	pieceIndex = rand.getRandomNumber(0);
	rotateIndex = ROT_IND::NORTH;
	posx = BIGMAT_WIDTH / 2 - 1;
	posy = 0;
	colorIndex = pieces.getPiece(pieceIndex).getColor();
}
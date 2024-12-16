#include "game/objects/activePieceThings.h"
#include "game/objects/randomSingleton.h"
#include "game/objects/loadedPieces.h"

ActivePiece::ActivePiece(RandomSingleton& rand, const LoadedPieces& allPieces):
	pieceIndex{rand.getRandomNumber(0)}, 
	rotateIndex{RotationIndex::North},
	colorIndex{allPieces.getPiece(pieceIndex).getColor()},
	posx{BigMatrixWidth/2 - 1}, 
	posy{0}
{
	
}

void ActivePiece::resetPieceValues(RandomSingleton& rand, const LoadedPieces& pieces)
{
	pieceIndex = rand.getRandomNumber(0);
	rotateIndex = RotationIndex::North;
	posx = BigMatrixWidth / 2 - 1;
	posy = 0;
	colorIndex = pieces.getPiece(pieceIndex).getColor();
}
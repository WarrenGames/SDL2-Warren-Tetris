#ifndef ACTIVE_PIECE_THINGS_H
#define ACTIVE_PIECE_THINGS_H

#include <cstddef>

class RandomSingleton;
class LoadedPieces;

struct ActivePiece
{
	size_t pieceIndex;
	size_t rotateIndex;
	int posx;
	int	posy;
	size_t colorIndex;
	
	ActivePiece(RandomSingleton& rand, const LoadedPieces& allPieces);
	void resetPieceValues(RandomSingleton& rand, const LoadedPieces& pieces);
};

#endif //ACTIVE_PIECE_THINGS_H
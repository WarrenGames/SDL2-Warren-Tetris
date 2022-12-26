#ifndef ACTIVE_PIECE_THINGS_H
#define ACTIVE_PIECE_THINGS_H

#include <cstdlib>

class RandomSingleton;
class LoadedPieces;

struct ActivePiece
{
	std::size_t pieceIndex;
	std::size_t rotateIndex;
	std::size_t colorIndex;
	int posx;
	int	posy;
	
	explicit ActivePiece(RandomSingleton& rand, const LoadedPieces& allPieces);
	void resetPieceValues(RandomSingleton& rand, const LoadedPieces& pieces);
};

#endif //ACTIVE_PIECE_THINGS_H
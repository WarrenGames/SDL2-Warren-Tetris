#include "game/objects/loadedPieces.h"
#include "game/loadFiles/loadPieceFile.h"

LoadedPieces::LoadedPieces(AppLogFiles& logs, unsigned skillLevel)
{
	loadPiecesAccToSkillLevel(logs, skillLevel, *this);
}

void LoadedPieces::addPiece(const MatrixTemp2D<SquareData>& northMatrix, std::size_t color)
{
	allPieces.push_back(Piece{northMatrix, color});
}

const Piece& LoadedPieces::getPiece(std::size_t index) const
{
	assert( index < allPieces.size() );
	return allPieces[index];
}

Piece& LoadedPieces::getPiece(std::size_t index)
{
	assert( index < allPieces.size() );
	return allPieces[index];
}

std::size_t LoadedPieces::size() const
{
	return allPieces.size();
}
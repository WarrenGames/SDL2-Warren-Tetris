#ifndef LOADED_PIECES_H
#define LOADED_PIECES_H

#include "game/objects/pieceClass.h"
#include <vector>

template<typename>class MatrixTemp2D;
struct AppLogFiles;

class LoadedPieces
{
private:
	std::vector<Piece> allPieces;

public:
	explicit LoadedPieces(AppLogFiles& logs, unsigned skillLevel);
	~LoadedPieces() = default;
	LoadedPieces( const LoadedPieces& ) = delete;
	LoadedPieces& operator= ( const LoadedPieces& ) = delete;
	
	void addPiece(const MatrixTemp2D<SquareData>& northMatrix, std::size_t color);
	const Piece& getPiece(std::size_t index) const;
	Piece& getPiece(std::size_t index);
	std::size_t size() const;
};

#endif //LOADED_PIECES_H
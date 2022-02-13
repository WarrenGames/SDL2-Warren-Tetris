#include "game/gameActions/moveCurrentPieceToMatrix.h"
#include "game/structs/scanLinesInfos.h"
#include "game/objects/randomSingleton.h"
#include "game/objects/loadedPieces.h"
#include "game/objects/activePieceThings.h"
#include "matrices/matrix2D.h"
#include "game/consts/constexpr.h"

void moveCurrentPieceToMatrix(const ActivePiece& pieceData, const Piece& piece, MatrixTemp2D<SquareData>& matrix, ScanLinesInfos& scanLinesInf)
{
	for( size_t posx{0} ; posx < piece.width(pieceData.rotateIndex) ; ++posx )
	{
		for( size_t posy{0} ; posy < piece.height(pieceData.rotateIndex) ; ++posy )
		{
			if( piece.getPresenceSquare(pieceData.rotateIndex, posx, posy) )
			{
				if( matrix.isSignedInsideBoundaries(pieceData.posx + static_cast<int>(posx), pieceData.posy + static_cast<int>(posy) ) )
				{
					matrix(pieceData.posx + static_cast<int>(posx), pieceData.posy + static_cast<int>(posy) ).color = static_cast<unsigned>( pieceData.colorIndex );
					matrix(pieceData.posx + static_cast<int>(posx), pieceData.posy + static_cast<int>(posy) ).filled = true;
				}
			}
		}
	}
	scanLinesInf.canScanToRemoveLines = true;
	scanLinesInf.topLine = pieceData.posy;
	scanLinesInf.bottomLine = pieceData.posy + piece.height(pieceData.rotateIndex) - 1;
}
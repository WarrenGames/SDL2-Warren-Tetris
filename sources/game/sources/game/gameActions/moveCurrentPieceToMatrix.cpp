#include <array>
#include "game/consts/constexpr.h"
#include "matrices/matrix2D.h"
#include "game/structs/scanLinesInfos.h"
#include "game/objects/randomSingleton.h"
#include "game/objects/loadedPieces.h"
#include "game/objects/activePieceThings.h"
#include "game/gameActions/moveCurrentPieceToMatrix.h"

void moveCurrentPieceToMatrix(const ActivePiece& pieceData, const Piece& piece, MatrixTemp2D<SquareData>& matrix, ScanLinesInfos& scanLinesInf)
{
	for( int posx{0} ; posx < piece.width(pieceData.rotateIndex) ; ++posx )
	{
		for( int posy{0} ; posy < piece.height(pieceData.rotateIndex) ; ++posy )
		{
			if( piece.getPresenceSquare(pieceData.rotateIndex, posx, posy) )
			{
				if( matrix.isSignedInsideBoundaries(pieceData.posx + posx, pieceData.posy + posy) )
				{
					matrix(pieceData.posx + posx, pieceData.posy + posy).color = static_cast<unsigned>( pieceData.colorIndex );
					matrix(pieceData.posx + posx, pieceData.posy + posy).filled = true;
				}
			}
		}
	}
	scanLinesInf.canScanToRemoveLines = true;
	scanLinesInf.topLine = pieceData.posy;
	scanLinesInf.bottomLine = pieceData.posy + piece.height(pieceData.rotateIndex) - 1;
}
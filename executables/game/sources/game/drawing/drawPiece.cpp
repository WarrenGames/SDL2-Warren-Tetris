#include "game/drawing/drawPiece.h"
#include "game/objects/activePieceThings.h"
#include "game/drawing/squareTexturing.h"
#include "game/objects/loadedPieces.h"
#include "game/consts/constexpr.h"

void drawPiece(sdl2::RendererWindow& rndWnd, const ActivePiece& activeP, const Piece& piece, SquaresDrawing& sqrDraw)
{	
	for( std::size_t sqr_x{0} ; sqr_x < piece.width(activeP.rotateIndex) ; ++sqr_x )
	{
		for( std::size_t sqr_y{0} ; sqr_y < piece.height(activeP.rotateIndex) ; ++sqr_y )
		{
			if( piece.getPresenceSquare(activeP.rotateIndex, sqr_x, sqr_y) )
			{
				sqrDraw.drawSquare(activeP.colorIndex, SQR_SIZE * (activeP.posx + static_cast<int>(sqr_x) ) + SQR_SIZE, SQR_SIZE * (activeP.posy + static_cast<int>(sqr_y) ), rndWnd);
			}
		}
	}
}
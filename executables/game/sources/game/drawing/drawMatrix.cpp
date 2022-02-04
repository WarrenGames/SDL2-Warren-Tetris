#include "game/drawing/drawMatrix.h"
#include "matrices/matrix2D.h"
#include "game/objects/squareData.h"
#include "game/drawing/squareTexturing.h"
#include "game/consts/constexpr.h"

void drawMatrix(sdl2::RendererWindow& render, SquaresDrawing& sqrDraw, const MatrixTemp2D<SquareData>& matrix)
{
	for(size_t y_pos{0} ; y_pos < matrix.height() ; ++y_pos )
	{
		for( size_t x_pos{0} ; x_pos < matrix.width() ; ++x_pos )
		{
			if( matrix(x_pos, y_pos).filled )
			{
				sqrDraw.drawSquare(matrix(x_pos, y_pos).color, SQR_SIZE * (static_cast<int>(x_pos)+1), SQR_SIZE * static_cast<int>(y_pos), render );
			}
		}
	}
}
#include "game/gameActions/checkGameOver.h"
#include "matrices/matrix2D.h"
#include "game/objects/squareData.h"

bool isGameOver(const MatrixTemp2D<SquareData>& matrix)
{
	for( size_t height{0} ; height < 3 ; ++height )
	{
		for( size_t width{0} ; width < matrix.width() ; ++width )
		{
			if( matrix(width, height).filled )
				return true;
		}
	}
	return false;
}

void setGameOverIfMatrixFilled(const MatrixTemp2D<SquareData>& matrix, bool& quitGame)
{
	if( isGameOver(matrix) )
	{
		quitGame = true;
	}
}
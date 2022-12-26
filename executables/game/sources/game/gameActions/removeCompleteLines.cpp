#include "game/gameActions/removeCompleteLines.h"
#include "game/structs/scanLinesInfos.h"
#include "game/drawing/playerScore.h"
#include "game/objects/squareData.h"
#include "matrices/matrix2D.h"
#include "game/consts/constexpr.h"
#include "SDL.h"
#include <array>

void removeCompleteLinesIfAny(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, MatrixTemp2D<SquareData>& matrix, PlayerScore& playerScore, ScanLinesInfos& scanLinesInf)
{
	if( scanLinesInf.canScanToRemoveLines )
	{
		std::size_t completeLinesNum{0};
		countCompleteLines(matrix, scanLinesInf, completeLinesNum);
		playerScore.addToScore( static_cast<unsigned>(addCompletedLinesToScore(completeLinesNum) ) );
		playerScore.updateScoreText(logs, rndWnd);
		decalOverCompleteLine(matrix, scanLinesInf);
		
		scanLinesInf.canScanToRemoveLines = false;
		scanLinesInf.bottomLine = 0;
	}
}

void countCompleteLines(const MatrixTemp2D<SquareData>& matrix, ScanLinesInfos& scanLinesInf, std::size_t& completeLinesNum)
{
	assert( scanLinesInf.bottomLine < matrix.height() );
	assert( scanLinesInf.topLine < matrix.height() );
	assert( scanLinesInf.bottomLine >= scanLinesInf.topLine );
	for( std::size_t height{scanLinesInf.topLine} ; height <= scanLinesInf.bottomLine ; ++height )
	{
		if( height >= 3 && height < matrix.height() )
		{
			if( isLineComplete(matrix, height) )
			{
				completeLinesNum++;
			}
		}
	}
}
 
bool isLineComplete(const MatrixTemp2D<SquareData>& matrix, std::size_t heightParam)
{
	assert( heightParam < matrix.height() );
	for( std::size_t width{0} ; width < matrix.width() ; ++width )
	{
		if( ! matrix(width, heightParam).filled  )
			return false;
	}
	return true;	
}

void decalOverCompleteLine(MatrixTemp2D<SquareData>& matrix, ScanLinesInfos& scanLinesInf)
{
	assert( scanLinesInf.bottomLine < matrix.height() );
	assert( scanLinesInf.topLine < matrix.height() );
	for( std::size_t height{scanLinesInf.bottomLine} ; height >= scanLinesInf.topLine ; --height )
	{
		if( height >= 3 && height < matrix.height() )
		{
			while( isLineComplete(matrix, height) )
			{
				browseTopLinesToMoveThem(matrix, height);
			}
		}
		else{
			return;
		}
	}
}

void browseTopLinesToMoveThem(MatrixTemp2D<SquareData>& matrix, std::size_t startBottom)
{
	for( std::size_t height{startBottom} ; height > 0 ; --height )
	{
		moveMatrixLineDowner(matrix, height);
	}
}

void moveMatrixLineDowner(MatrixTemp2D<SquareData>& matrix, std::size_t height)
{
	for( std::size_t width{0} ; width < matrix.width() ; ++width )
	{
		matrix(width, height) = matrix(width, height - 1);
		matrix(width, height - 1).filled = false;
	}
}

std::size_t addCompletedLinesToScore(std::size_t completeLinesNum)
{
	switch( completeLinesNum )
	{
		case 1:
			return 10;
			break;
		case 2:
			return 40;
			break;
		case 3:
			return 120;
			break;
		case 4:
			return 320;
			break;
		default:
			return 0;
			break;
	}
}
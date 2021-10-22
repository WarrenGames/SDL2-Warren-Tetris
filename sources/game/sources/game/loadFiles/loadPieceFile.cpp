#include "game/loadFiles/loadPieceFile.h"
#include "logging/logsStruct.h"
#include "game/objects/loadedPieces.h"
#include "game/objects/squareData.h"
#include "matrices/matrix2D.h"
#include "game/consts/constexpr.h"
#include <fstream>

void loadPieceFile(AppLogFiles& logs, const std::string fileName, LoadedPieces& pieces)
{
	const std::string filePath{ "data/pieces/" + fileName };
	
	if( std::ifstream pieceFile{filePath} )
	{
		loadPieceFirstData(logs, filePath, pieceFile, pieces);
	}
	else{
		logs.error << "Error: couldn't open '" << filePath << "' piece file.\n";
	}
}

void loadPieceFirstData(AppLogFiles& logs, const std::string& filePath, std::ifstream& inputFile, LoadedPieces& pieces)
{
	size_t matWidth{0}, matHeight{0};
	unsigned colorIndex{0};
		
	if( inputFile >> matWidth >> matHeight >> colorIndex )
	{
		MatrixTemp2D<SquareData> TemporaryMat{matWidth, matHeight};
		loadPieceMatrixData(logs, filePath, inputFile, TemporaryMat, pieces, colorIndex);
	}
	else{
		logs.error << "Error: in '" << filePath << "' file. Redaing mat width , height and color index error.\n";
	}
}

void loadPieceMatrixData(AppLogFiles& logs, const std::string& fileName, std::ifstream& inputFile, MatrixTemp2D<SquareData>& matrix, LoadedPieces& pieces, unsigned color)
{
	bool data{0};
	for(size_t sqr_y{0} ; sqr_y < matrix.height() ; ++sqr_y )
	{
		for( size_t sqr_x{0} ; sqr_x < matrix.width() ; ++sqr_x )
		{
			if( inputFile >> data )
			{
				matrix(sqr_x, sqr_y).color = color;
				matrix(sqr_x, sqr_y).filled = data;
			}
			else{
				logs.error << "Error: couldn't read data x(" << sqr_x << ") y(" << sqr_y << ") for the following piece: " << fileName << '\n'; 
			}
		}
	}
	pieces.addPiece(matrix, color);
}

void loadPiecesAccToSkillLevel(AppLogFiles& logs, unsigned skillLevel, LoadedPieces& pieces)
{
	switch( skillLevel )
	{
		case EASY_GAME:
			loadPieceFile(logs, "bigBar.piece", pieces);
			loadPieceFile(logs, "bigSquare.piece", pieces);
			loadPieceFile(logs, "littleBar.piece", pieces);
			loadPieceFile(logs, "littleSquare.piece", pieces);
			loadPieceFile(logs, "mediumBar.piece", pieces);
			break;
		case INTERMEDIATE_GAME:
			loadPieceFile(logs, "bigBar.piece", pieces);
			loadPieceFile(logs, "bigSquare.piece", pieces);
			loadPieceFile(logs, "corner.piece", pieces);
			loadPieceFile(logs, "knightMove.piece", pieces);
			loadPieceFile(logs, "littleBar.piece", pieces);
			loadPieceFile(logs, "littleSquare.piece", pieces);
			loadPieceFile(logs, "mediumBar.piece", pieces);
			break;
		case HARD_GAME:
			loadPieceFile(logs, "bigBar.piece", pieces);
			loadPieceFile(logs, "bigSquare.piece", pieces);
			loadPieceFile(logs, "bridge.piece", pieces);
			loadPieceFile(logs, "corner.piece", pieces);
			loadPieceFile(logs, "heap.piece", pieces);
			loadPieceFile(logs, "knightMove.piece", pieces);
			loadPieceFile(logs, "littleBar.piece", pieces);
			loadPieceFile(logs, "mediumBar.piece", pieces);
			loadPieceFile(logs, "zigzag.piece", pieces);
			break;
		default:
			assert( ! "You shouldn't have come here: wrong skill level" );
			break;
	}
}
#ifndef LOAD_PIECE_FILE_H
#define LOAD_PIECE_FILE_H

#include <string>
#include <iosfwd>

struct AppLogFiles;
class LoadedPieces;
template<typename>class MatrixTemp2D;
struct SquareData;

void loadPieceFile(AppLogFiles& logs, const std::string fileName, LoadedPieces& pieces);

void loadPieceFirstData(AppLogFiles& logs, const std::string& filePath, std::ifstream& inputFile, LoadedPieces& pieces);

void loadPieceMatrixData(AppLogFiles& logs, const std::string& filePath, std::ifstream& inputFile, MatrixTemp2D<SquareData>& matrix, LoadedPieces& pieces, std::size_t color);

void loadPiecesAccToSkillLevel(AppLogFiles& logs, unsigned skillLevel, LoadedPieces& pieces);

#endif //LOAD_PIECE_FILE_H
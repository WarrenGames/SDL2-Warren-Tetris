#ifndef REMOVE_COMPLETE_LINES_H
#define REMOVE_COMPLETE_LINES_H

#include <cstdlib>

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }
template<typename>class MatrixTemp2D;
struct SquareData;
class PlayerScore;
struct ScanLinesInfos;

void removeCompleteLinesIfAny(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, MatrixTemp2D<SquareData>& matrix, PlayerScore& playerScore, ScanLinesInfos& scanLinesInf);

void countCompleteLines(const MatrixTemp2D<SquareData>& matrix, ScanLinesInfos& scanLinesInf, std::size_t& completeLinesNum);

bool isLineComplete(const MatrixTemp2D<SquareData>& matrix, std::size_t heightParam);

void decalOverCompleteLine(MatrixTemp2D<SquareData>& matrix, ScanLinesInfos& scanLinesInf);

void browseTopLinesToMoveThem(MatrixTemp2D<SquareData>& matrix, std::size_t startBottom);

void moveMatrixLineDowner(MatrixTemp2D<SquareData>& matrix, std::size_t height);

std::size_t addCompletedLinesToScore(std::size_t completeLinesNum);

#endif //REMOVE_COMPLETE_LINES_H
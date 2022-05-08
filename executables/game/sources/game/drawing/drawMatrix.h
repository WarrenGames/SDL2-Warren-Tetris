#ifndef DRAW_MATRIX_H
#define DRAW_MATRIX_H

namespace sdl2{ class RendererWindow; }
class SquaresDrawing;
template<typename>class MatrixTemp2D;
struct SquareData;

void drawMatrix(sdl2::RendererWindow& rndWnd, SquaresDrawing& sqrDraw, const MatrixTemp2D<SquareData>& matrix);

#endif //DRAW_MATRIX_H
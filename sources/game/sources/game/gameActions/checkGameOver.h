#ifndef CHECK_GAME_OVER_H
#define CHECK_GAME_OVER_H

template<typename>class MatrixTemp2D;
struct SquareData;

bool isGameOver(MatrixTemp2D<SquareData>& matrix);

void setGameOverIfMatrixFilled(MatrixTemp2D<SquareData>& matrix, bool& quitGame);

#endif //CHECK_GAME_OVER_H
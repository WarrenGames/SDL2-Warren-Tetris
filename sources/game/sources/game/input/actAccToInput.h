#ifndef ACT_ACCORDING_TO_INPUT_H
#define ACT_ACCORDING_TO_INPUT_H

void actAccToPlayerInput(UserInput& Inp, GameObject& GameObj);

void moveCurrentPieceToLeft(UserInput& Inp, GameObject& GameObj);

void moveCurrentPieceToRight(UserInput& Inp, GameObject& GameObj);

void moveCurrentPieceDowner(UserInput& Inp, GameObject& GameObj);

void rotateClockwisePiece(UserInput& Inp, GameObject& GameObj);

void rotateAntiClockwisePiece(UserInput& Inp, GameObject& GameObj);

#endif //ACT_ACCORDING_TO_INPUT_H
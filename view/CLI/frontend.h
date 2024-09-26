//
// Created by roach on 24.09.2024.
//

#ifndef FRONTEND_H
#define FRONTEND_H
#include "../../models/SnakeCore/inc/SnakeGameModel.h"

using namespace s21;
void PrintGameField(SnakeGameModel* model);
void printGameInfo(SnakeGameModel* model);
void loadShapeInBuffer(SnakeGameModel* model, BaseBoardModel* boardModel);
void PrintField(BaseBoardModel Buffer);
#endif //FRONTEND_H

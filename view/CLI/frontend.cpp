//
// Created by roach on 24.09.2024.
//
#include "frontend.h"

#include <ncurses.h>
void loadShapeInBuffer(SnakeGameModel* model, BaseBoardModel* boardModel) {
  SnakeModel snakeModel(model->getSnakeModel());
  for (auto it = snakeModel.begin(); it != snakeModel.end(); ++it) {
    int x = (*it).x, y = (*it).y;
    if (x >= 0 && x < boardModel->getWidth() && y >= 0 &&
        y < boardModel->getHeight())
      (*boardModel)[y][x] = 1;
  }
  for (int i = 0; i < boardModel->getHeight(); ++i) {
    for (int j = 0; j < boardModel->getWidth(); ++j) {
      if (model->getSnakeFood().isFood(j, i)) (*boardModel)[i][j] = 1;
    }
  }
}
void PrintGameField(SnakeGameModel* model) {
  BaseBoardModel boardModel(model->getGameBoard());
  clear();
  loadShapeInBuffer(model, &boardModel);
  PrintField(boardModel);
  printGameInfo(model);
  wrefresh(stdscr);
}

void PrintField(BaseBoardModel Buffer) {
  for (int i = 0; i < Buffer.getHeight(); i++) {
    for (int j = 0; j < Buffer.getWidth(); j++) {
      mvaddch(i + 3, (j + 1) * 2, Buffer[i][j] ? '#' : '.');
    }
  }
}

void printGameInfo(SnakeGameModel* model) {
  mvprintw(1, 8, "Brick Game: Tetris");
  mvprintw(13, 40, "Best Score: %d", model->getBestScore());
  mvprintw(14, 40, "Score: %d", model->getScore());
  mvprintw(15, 40, "Input: %d", model->getGameControl());

  if (model->getState() == SnakeGameModel::PAUSE)
    mvprintw(15, 40, "Game on pause");
}

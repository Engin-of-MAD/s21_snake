#include "tetris_frontend.h"

void alignmentShapes(game_data_t gameData, char helpScreen[8][8]) {
  for (int i = 0; i < gameData.next.width; ++i) {
    for (int j = 0; j < gameData.next.width; ++j) {
      switch (gameData.next.name) {
      case 'O':
        helpScreen[i + 3][j + 3] = gameData.next.array[i][j];
        break;
      case 'I':
        helpScreen[i + 3][j + 2] = gameData.next.array[i][j];
        break;
      case 'L':
        helpScreen[i + 3][j + 3] = gameData.next.array[i][j];
        break;
      case 'J':
        helpScreen[i + 3][j + 3] = gameData.next.array[i][j];
        break;
      case 'T':
        helpScreen[i + 3][j + 3] = gameData.next.array[i][j];
        break;
      case 'S':
        helpScreen[i + 3][j + 3] = gameData.next.array[i][j];
        break;
      case 'Z':
        helpScreen[i + 3][j + 3] = gameData.next.array[i][j];
        break;
      }
    }
  }
}

void printGameInfo(game_data_t gameData) {
  mvprintw(1, 8, "Brick Game: Tetris");
  mvprintw(3, 40, "Next Shape:");
  mvprintw(14, 40, "Score: %d", gameData.score);
  if (gameData.state == PAUSE)
    mvprintw(15, 40, "Game on pause");
}

void nextShapeScreen(game_data_t gameData) {
  clear();
  char helpScreen[8][8] = {0};
  alignmentShapes(gameData, helpScreen);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      mvaddch(i + 5, j * 2 + 40, (helpScreen[i][j]) ? '#' : '.');
    }
  }
}

void loadShapeInBuffer(game_data_t gameData, char Buffer[ROWS_TB][COLS_TB]) {
  for (int i = 0; i < gameData.current.width; i++) {
    for (int j = 0; j < gameData.current.width; j++) {
      if (gameData.current.array[i][j])
        Buffer[gameData.current.row + i][gameData.current.col + j] =
            gameData.current.array[i][j];
    }
  }
}

void PrintField(game_data_t gameData, char Buffer[ROWS_TB][COLS_TB]) {
  for (int i = 0; i < ROWS_TB; i++) {
    for (int j = 0; j < COLS_TB; j++) {
      mvaddch(i + 3, (j + 1) * 2,
              (gameData.Table[i][j] + Buffer[i][j]) ? '#' : '.');
    }
  }
}

void PrintGameField(game_data_t gameData) {
  char Buffer[ROWS_TB][COLS_TB] = {0};
  loadShapeInBuffer(gameData, Buffer);
  clear();
  nextShapeScreen(gameData);
  PrintField(gameData, Buffer);
  printGameInfo(gameData);
  wrefresh(stdscr);
}

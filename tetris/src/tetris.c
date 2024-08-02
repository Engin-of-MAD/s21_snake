#include "brick_game/tetris/tetris.h"
#include "brick_game/tetris/tetris_backend.h"
#include "gui/cli/tetris_frontend.h"

#include <ncurses.h>
void game_loop(game_data_t *gameData) {
  gettimeofday(&gameData->before_now, NULL);
  SetNewRandomShape(gameData, &gameData->next);
  bool break_flag = TRUE;
  while (break_flag) {
    if (gameData->state == GAMEOVER || gameData->state == EXIT_STATE)
      break_flag = FALSE;
    stateMachine(gameData,get_signal(gameData->input));
    gameData->input = GET_USER_INPUT;

    PrintGameField(*gameData);
  }
}

void game_end(game_data_t game_data) {
  for (int i = 0; i < ROWS_TB; i++) {
    for (int j = 0; j < COLS_TB; j++)
      printf("%c ", game_data.Table[i][j] ? '#' : '.');
    printf("\n");
  }
  printf("\nGame over!\n");
  printf("\nScore: %d\n", game_data.score);
}

void ncursesMode() {
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(40);
}

void ClearMem(game_data_t *gameData) {
  DeleteShape(&gameData->current);
  DeleteShape(&gameData->next);
  endwin();
}

int main() {
  game_data_t game_data;
  initGameData(&game_data);
  ncursesMode();
  game_loop(&game_data);
  ClearMem(&game_data);
  game_end(game_data);

  initscr();
  return 0;
}

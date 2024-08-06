#ifndef TETRIS_H
#define TETRIS_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define ESCAPE_KEY 27
#define ENTER_KEY 10

#define ROWS_TB 20
#define COLS_TB 15

#define GET_USER_INPUT getch()

//enum {
//  MOVE_UP = 0,
//  MOVE_DOWN,
//  MOVE_RIGHT,
//  MOVE_LEFT,
//  ESCAPE_BTN,
//  ENTER_BTN,
//  NOSIG,
//  PAUSE_BTN
//} signals;

typedef enum { START = 0, SPAWN, MOVING, PAUSE, GAMEOVER, EXIT_STATE } state_t;

typedef struct {
  char **array; // shape
  int width;
  char name;
  int row, col; // params shape

} Shape;


typedef struct {
  char Table[ROWS_TB][COLS_TB]; // game field
  Shape *ShapesArray;
  struct timeval before_now, now; // time points
  suseconds_t timer;              // time delay
  int score;     // current score
  int input;     // user input
  state_t state; // game state
  Shape current; // current shape
  Shape next;
} game_data_t; // game object

#endif // TETRIS_H
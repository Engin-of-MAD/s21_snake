#ifndef FROGGER_FRONTEND_H
#define FROGGER_FRONTEND_H

#include <string.h>
#include <time.h>

#include "../../brick_game/tetris/tetris.h"

void PrintGameField(game_data_t game_data);

typedef enum { I = 0, J, L, O, S, Z, T } shapes;

#endif
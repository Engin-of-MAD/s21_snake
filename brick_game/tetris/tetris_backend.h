#ifndef FROGGER_BACKEND_H
#define FROGGER_BACKEND_H

#include "tetris.h"

void WriteToTable(game_data_t *game_data);
bool delay(game_data_t game_data);
void initGameData(game_data_t *game_data);
void ManipulateCurrent(game_data_t *game_data, signals action);
Shape CopyShape(Shape shape);
void DeleteShape(Shape *shape);
bool CheckPosition(Shape shape, char Table[ROWS_TB][COLS_TB]);
bool SetNewRandomShape(game_data_t *gameData, Shape *newShape);
void RotateShape(Shape shape);
void RemoveFullRowsAndUpdateScore(game_data_t *game_data);
void start_action(const signals input, state_t *state);
void stateMachine(game_data_t *gameData, signals input);
signals get_signal(int user_input);

#endif
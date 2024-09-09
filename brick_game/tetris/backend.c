#include "tetris_backend.h"

// Фигуры


const Shape ShapesArray[7] = {
        {(char *[]){(char[]){0, 1, 1}, (char[]){1, 1, 0}, (char[]){0, 0, 0}}, 3,
                                                                                 'S', 0, 0}, // S shape
        {(char *[]){(char[]){1, 1, 0}, (char[]){0, 1, 1}, (char[]){0, 0, 0}}, 3,
                                                                                 'Z', 0, 0}, // Z shape
        {(char *[]){(char[]){0, 1, 0}, (char[]){1, 1, 1}, (char[]){0, 0, 0}}, 3,
                                                                                 'T', 0, 0}, // T shape
        {(char *[]){(char[]){0, 0, 1}, (char[]){1, 1, 1}, (char[]){0, 0, 0}}, 3,
                                                                                 'L', 0, 0}, // L shape
        {(char *[]){(char[]){1, 0, 0}, (char[]){1, 1, 1}, (char[]){0, 0, 0}}, 3,
                                                                                 'J', 0, 0},                                                // J shape
        {(char *[]){(char[]){1, 1}, (char[]){1, 1}}, 2, 'O', 0, 0}, // O shape
        {(char *[]){(char[]){0, 0, 0, 0}, (char[]){1, 1, 1, 1},
                    (char[]){0, 0, 0, 0}, (char[]){0, 0, 0, 0}},
                                                                              4, 'I', 0, 0} // I shape
        // you can add any shape like it's done above. Don't be naughty.
};



void WriteToTable(game_data_t *game_data) {
  for (int i = 0; i < game_data->current.width; i++) {
    for (int j = 0; j < game_data->current.width; j++) {
      if (game_data->current.array[i][j])
        game_data
            ->Table[game_data->current.row + i][game_data->current.col + j] =
            game_data->current.array[i][j];
    }
  }
}

suseconds_t getMicroSeconds(struct timeval timeDiff) {
  suseconds_t microSeconds =
      timeDiff.tv_sec * 1000000 +
      timeDiff.tv_usec; // getting microseconds for all time
  return microSeconds;
}

bool delay(game_data_t gameData) {
  return (getMicroSeconds(gameData.now) -
          getMicroSeconds(gameData.before_now)) > gameData.timer;
}

// Инициализация игрового объекта

void init_table(char table[ROWS_TB][COLS_TB]) {
  for (int y = 0; y < ROWS_TB; y++) {
    for (int x = 0; x < COLS_TB; x++) {
      table[y][x] = 0;
    }
  }
}

void initShapes(game_data_t *gameData) {
  gameData->current.array = NULL;
  gameData->current.width = 0;
  gameData->current.col = 0;
  gameData->current.row = 0;

  gameData->next.array = NULL;
  gameData->next.width = 0;
  gameData->next.col = 0;
  gameData->next.row = 0;
}

void initGameData(game_data_t *gameData) {
  init_table(gameData->Table); // init curr game field
  initShapes(gameData);        // init curr shape
  gameData->score = 0;         // base score
  gameData->timer = 1000000;   // time delay in microseconds
  gameData->state = START;
}

// Генерация фигуры

bool SetNewRandomShape(game_data_t *gameData,
                       Shape *newShape) { // updates [current] with new shape
  bool collision = false;
  Shape new_shape = CopyShape(ShapesArray[rand() % 7]);
  new_shape.col = rand() % (COLS_TB - new_shape.width + 1);
  new_shape.row = 0;
  DeleteShape(newShape);
  *newShape = new_shape;
  if (!CheckPosition(*newShape, gameData->Table)) {
    collision = true;
  }
  return collision;
}

bool CheckPosition(
    Shape shape,
    char Table[ROWS_TB][COLS_TB]) { // Check the position of the copied shape
  char **array = shape.array;
  int i, j;
  for (i = 0; i < shape.width; i++) {
    for (j = 0; j < shape.width; j++) {
      if ((shape.col + j < 0 || shape.col + j >= COLS_TB ||
           shape.row + i >= ROWS_TB)) { // Out of borders
        if (array[i][j])                // but is it just a phantom?
          return FALSE;
      } else if (Table[shape.row + i][shape.col + j] && array[i][j])
        return FALSE;
    }
  }
  return TRUE;
}
// Управление

void ManipulateCurrent(game_data_t *game_data, signals action) {
  Shape temp =
      CopyShape(game_data->current); // Creating copy shape for check collision
  switch (action) {
  case MOVE_DOWN:
    temp.row++;                                //
    if (CheckPosition(temp, game_data->Table)) // Check collision
      game_data->current.row++;
    else {
      WriteToTable(game_data);
      RemoveFullRowsAndUpdateScore(game_data);
      DeleteShape(&game_data->current);
      game_data->state = SPAWN;
    }
    break;
  case MOVE_RIGHT:
    temp.col++;                                // Вправо по оси X
    if (CheckPosition(temp, game_data->Table)) // Check collision
      game_data->current.col++;
    break;
  case MOVE_LEFT:
    temp.col--;                                // Влево по оси X
    if (CheckPosition(temp, game_data->Table)) // Check collision
      game_data->current.col--;
    break;
  case MOVE_UP:
    RotateShape(temp);
    if (CheckPosition(temp, game_data->Table)) // Check collision
      RotateShape(game_data->current);
    break;
  case ESCAPE_BTN:
    game_data->state = EXIT_STATE;
    break;
  case PAUSE_BTN:
    game_data->state = PAUSE;
    break;
    //Заглушки
  case ENTER_BTN:
    break;
  case NOSIG:
    break;
  }
  DeleteShape(&temp);
}

Shape CopyShape(Shape shape) {
  Shape new_shape = shape;
  char **copyshape = shape.array;
  new_shape.array = (char **)malloc(new_shape.width * sizeof(char *));
  int i, j;
  for (i = 0; i < new_shape.width; i++) {
    new_shape.array[i] = (char *)malloc(new_shape.width * sizeof(char));
    for (j = 0; j < new_shape.width; j++) {
      new_shape.array[i][j] = copyshape[i][j];
    }
  }
  return new_shape;
}


// Вращение фигуры

void RotateShape(Shape shape) { // rotates clockwise
  Shape temp = CopyShape(shape);
  int width;
  width = shape.width;
  for (int i = 0; i < width; i++) {
    for (int j = 0, k = width - 1; j < width; j++, k--) {
      shape.array[i][j] = temp.array[k][i];
    }
  }
  DeleteShape(&temp);
}

// Очистка данных

void RemoveFullRowsAndUpdateScore(game_data_t *game_data) {
  int sum, count = 0;
  for (int i = 0; i < ROWS_TB; i++) {
    sum = 0;
    for (int j = 0; j < COLS_TB; j++) {
      sum += game_data->Table[i][j];
    }
    if (sum == COLS_TB) {
      count++;
      int l, k;
      for (k = i; k >= 1; k--)
        for (l = 0; l < COLS_TB; l++)
          game_data->Table[k][l] = game_data->Table[k - 1][l];
      for (l = 0; l < COLS_TB; l++)
        game_data->Table[k][l] = 0;
    }
  }
  game_data->score += 100 * count;
}

signals get_signal(int user_input) {
  signals rc = NOSIG;

  if (user_input == KEY_UP)
    rc = MOVE_UP;
  else if (user_input == KEY_DOWN)
    rc = MOVE_DOWN;
  else if (user_input == KEY_LEFT)
    rc = MOVE_LEFT;
  else if (user_input == KEY_RIGHT)
    rc = MOVE_RIGHT;
  else if (user_input == ESCAPE_KEY)
    rc = ESCAPE_BTN;
  else if (user_input == ENTER_KEY)
    rc = ENTER_BTN;
  else if (user_input == ERR)
    rc = NOSIG;
  else if (user_input == 'p')
    rc = PAUSE_BTN;
  return rc;
}

void start_action(const signals input, state_t *state) {
  if (input == ENTER_BTN) *state = SPAWN;
  if (input == ESCAPE_BTN) *state = EXIT_STATE;
}

void stateMachine(game_data_t *gameData, signals input) {
  switch (gameData->state) {
  case START:
    start_action(input, &gameData->state);
    break;
  case SPAWN:
    gameData->current = CopyShape(gameData->next);
    bool collision = SetNewRandomShape(gameData, &gameData->next);
    gameData->state = collision ? GAMEOVER : MOVING;
    break;
  case MOVING:
    ManipulateCurrent(gameData, input);
    gettimeofday(&gameData->now, NULL);
    if (delay(*gameData)) { // time difference in microsec accuracy
      ManipulateCurrent(gameData, MOVE_DOWN);
      gettimeofday(&gameData->before_now, NULL);
    }
    if (input == PAUSE_BTN)
      gameData->state = PAUSE;
    break;
  case PAUSE:
    if (input == ENTER_BTN)
      gameData->state = MOVING;
    break;
  case GAMEOVER:
      DeleteShape(&gameData->current);
      DeleteShape(&gameData->next);
      endwin();
    break;
  case EXIT_STATE:
      DeleteShape(&gameData->current);
      DeleteShape(&gameData->next);
      endwin();
    break;
  }
}
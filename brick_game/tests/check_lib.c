#include <check.h>

#include "../tetris/tetris.h"
#include "../tetris/tetris_backend.h"

START_TEST(Shapes_test) {
  game_data_t gameData;
  initGameData(&gameData);
  SetNewRandomShape(&gameData, &gameData.next);
  SetNewRandomShape(&gameData, &gameData.current);
  ck_assert(gameData.current.array != NULL);
  ck_assert(gameData.next.array != NULL);
  DeleteShape(&gameData.current);
  DeleteShape(&gameData.next);
  ck_assert(gameData.current.array == NULL);
  ck_assert(gameData.next.array == NULL);

  gameData.next = CopyShape(gameData.ShapesArray[0]);
  int width = gameData.ShapesArray[0].width;
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < width; ++j) {
      ck_assert(gameData.next.array[i][j] == gameData.ShapesArray[0].array[i][j]);
    }
  }
  DeleteShape(&gameData.next);
}
END_TEST
/*
  GameInfo_t *stats = getGameInfo_t();
  startGame();
  moveFigure(Left);
  moveFigure(Right);
  UserAction_t action;
  int key = '\n';
  keyboardParser(key, &action);
  key = KEY_LEFT;
  keyboardParser(key, &action);
  key = KEY_RIGHT;
  keyboardParser(key, &action);
  key = KEY_DOWN;
  keyboardParser(key, &action);
  key = KEY_UP;
  keyboardParser(key, &action);
  userInput(Right, 1);
  userInput(Action, 1);
  userInput(Left, 1);
  userInput(Pause, 1);
  key = '\n';
  keyboardParser(key, &action);
  key = 'n';
  keyboardParser(key, &action);
  key = 'y';
  keyboardParser(key, &action);
  userInput(Up, 1);
  userInput(Start, 1);
  rotateFigure();
  pauseGame();
  pauseGame();
  moveFigure(Down);

  keyboardParser(key, &action);
  userInput(Terminate, 1);
  key = 'y';
  keyboardParser(key, &action);
  playAgain();
  ck_assert_int_eq(stats->started, 1);
  deleteLines();
  updateCurrentState();
  changeSpeed(5);
  userInput(Terminate, 1);
  ck_assert_int_eq(stats->stop, 1);
  key = 'n';
  keyboardParser(key, &action);
*/



START_TEST(GAME_TEST) {
    game_data_t gameData;
    initGameData(&gameData);
    ck_assert(gameData.state == START);
    stateMachine(&gameData, ESCAPE_BTN);
    ck_assert(gameData.state == EXIT_STATE);
    DeleteShape(&gameData.next);
    DeleteShape(&gameData.current);

    gameData.state = START;
    SetNewRandomShape(&gameData,&gameData.next);
    stateMachine(&gameData, ENTER_BTN);
    ck_assert(gameData.state == SPAWN);
    stateMachine(&gameData, NOSIG);
    stateMachine(&gameData, MOVE_LEFT);

    ck_assert(gameData.state == MOVING);
    while(gameData.state != SPAWN)
        ManipulateCurrent(&gameData, MOVE_DOWN);
    ck_assert(gameData.state == SPAWN);
    gameData.state = EXIT_STATE;
    stateMachine(&gameData, NOSIG);

    gameData.state = SPAWN;
    SetNewRandomShape(&gameData,&gameData.next);
    stateMachine(&gameData, MOVE_LEFT);
    while (gameData.state != SPAWN) {

        ManipulateCurrent(&gameData, MOVE_LEFT);
        stateMachine(&gameData, MOVE_DOWN);
        ManipulateCurrent(&gameData, MOVE_UP);
        ManipulateCurrent(&gameData, MOVE_RIGHT);
        ManipulateCurrent(&gameData, ENTER_BTN);
        ManipulateCurrent(&gameData, NOSIG);
    }
    ck_assert(SPAWN == gameData.state);

    stateMachine(&gameData, MOVE_LEFT);
    stateMachine(&gameData, PAUSE_BTN);
    printf("state %d\n", gameData.state);
    ck_assert(gameData.state == PAUSE);
    stateMachine(&gameData, ENTER_BTN);
    ck_assert(gameData.state == MOVING);
    stateMachine(&gameData, ESCAPE_BTN);
    ck_assert(gameData.state == EXIT_STATE);
    gameData.state = GAMEOVER;
    stateMachine(&gameData, NOSIG);
}
END_TEST


START_TEST(PARSER_CHECK){
    ck_assert(MOVE_DOWN == get_signal(KEY_DOWN));
    ck_assert(MOVE_UP == get_signal(KEY_UP));
    ck_assert(MOVE_LEFT == get_signal(KEY_LEFT));
    ck_assert(MOVE_RIGHT == get_signal(KEY_RIGHT));
    ck_assert(NOSIG == get_signal(ERR));
    ck_assert(PAUSE_BTN == get_signal('p'));

}END_TEST

Suite *back() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Backend functions test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, Shapes_test);
  tcase_add_test(tc_core, GAME_TEST);
  tcase_add_test(tc_core, PARSER_CHECK);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_backend() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = back();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}

int main() {
  int no_failed = 0;

  no_failed |= test_backend();

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

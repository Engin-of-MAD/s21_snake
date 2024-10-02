#include <gtest/gtest.h>

#include "test.h"

using namespace s21;
TEST(TetrisTest1, Constructor_branch_test_1) {
  TetrisGameModel model;
  ASSERT_EQ(model.getScore(), 0);
  ASSERT_EQ(model.getStateGame(), TetrisGameModel::START);
}

TEST(TetrisTest2, FSM_CHECK) {
    TetrisGameModel model;
    model.disableDelay();

    ASSERT_EQ(TetrisGameModel::START, model.getStateGame());
    model.setGameControl(TetrisGameModel::STAR_GAME);
    while (model.getStateGame() != s21::TetrisGameModel::SPAWN)
        model.stateMachine();
    ASSERT_EQ(TetrisGameModel::SPAWN, model.getStateGame());
    model.stateMachine();
    ASSERT_EQ(TetrisGameModel::MOVING, model.getStateGame());
    while (model.getStateGame() != s21::TetrisGameModel::SPAWN)
        model.stateMachine();
    ASSERT_EQ(TetrisGameModel::SPAWN, model.getStateGame());
    model.setGameControl(TetrisGameModel::PAUSE_GAME);
    model.stateMachine();
    model.stateMachine();
    model.getCurrentTetromino().printInConsole();
    ASSERT_EQ(TetrisGameModel::PAUSE, model.getStateGame());
    model.setGameControl(TetrisGameModel::PAUSE_GAME);
    model.stateMachine();
    ASSERT_EQ(TetrisGameModel::MOVING, model.getStateGame());
    for (int i = 0; i < 10; ++i) {
        model.stateMachine();
    }

    model.resetGame();
    model.setGameControl(s21::TetrisGameModel::STAR_GAME);
    model.stateMachine();
    while (model.getStateGame() != s21::TetrisGameModel::GAMEOVER) {
        model.stateMachine();
    }
    ASSERT_EQ(TetrisGameModel::GAMEOVER, model.getStateGame());
    model.stateMachine();
    model.resetGame();
    model.setGameControl(s21::TetrisGameModel::STAR_GAME);
    model.stateMachine();
    model.stateMachine();
    model.setGameControl(s21::TetrisGameModel::EXIT_GAME);
    model.stateMachine();
    ASSERT_EQ(TetrisGameModel::EXIT_STATE, model.getStateGame());
    model.resetGame();
    model.setGameControl(s21::TetrisGameModel::STAR_GAME);
    for (int i = 0; i < 10; ++i) {
        model.stateMachine();
    }
    model.setGameControl(s21::TetrisGameModel::STOP_GAME);
    model.stateMachine();
    model.stateMachine();
    model.stateMachine();
    ASSERT_EQ(TetrisGameModel::START, model.getStateGame());
    model.stateMachine();
    model.setGameControl(s21::TetrisGameModel::STAR_GAME);
    model.stateMachine();
    model.stateMachine();
    model.stateMachine();
    model.setGameControl(TetrisGameModel::EXIT_GAME);
    model.stateMachine();
    ASSERT_EQ(TetrisGameModel::EXIT_STATE, model.getStateGame());
}

TEST(TetrisTest3, CheckControl) {
    TetrisGameModel model(1, 1);
    model.setGameControl(TetrisGameModel::STAR_GAME);
    while (model.getStateGame() != TetrisGameModel::GAMEOVER){
        model.stateMachine();
        model.setGameControl(TetrisGameModel::MOVE_LEFT);
    }
    model.resetGame();
    model.setGameControl(TetrisGameModel::STAR_GAME);
    while (model.getStateGame() != TetrisGameModel::GAMEOVER){
        model.stateMachine();
        model.setGameControl(TetrisGameModel::MOVE_RIGHT);
        model.setGameControl(TetrisGameModel::MOVE_UP);
    }
}


TEST(TetrisTest4, GameBoardCheck) {
    TetrisGameModel model(1, 1);
    model.setGameControl(TetrisGameModel::STAR_GAME);
    while (model.getStateGame() != TetrisGameModel::GAMEOVER) {
        model.stateMachine();
        model.getBoardModel();
    }
    model.resetGame();
    model.setGameControl(TetrisGameModel::STAR_GAME);
    model.getBoardModel().initRow(0);
    model.getBoardModel().initRow(1);
    model.getBoardModel().initRow(3);
    model.getBoardModel().initRow(4);
    model.getBoardModel().initRow(5);
    model.getBoardModel().initRow(6);    model.getBoardModel().initRow(0);
    model.getBoardModel().initRow(7);
    model.getBoardModel().initRow(8);
    while (model.getStateGame() != TetrisGameModel::GAMEOVER) {
        model.stateMachine();

    }
    TetrisBoardModel board1 = model.getBoardModel(), board2;
    board1.reset();
    board1.initRow(0);
    board1.initRow(1);
    board1.initRow(2);
    board2 = board1;
    board1.printInConsole();
    board2.printInConsole();
    ASSERT_TRUE(board1 == board2);
    int removedRowsCount = 0;
    for (int rowI = 0; rowI < board2.getHeight(); ++rowI) {
        if (board2.isRowFull(rowI)) {
            board2.clearRow(rowI);
            board2.shiftDownRows(rowI);
            removedRowsCount++;
        }
    }
    board2.printInConsole();
    ASSERT_TRUE(3 == removedRowsCount);
}

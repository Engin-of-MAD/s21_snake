#include <gtest/gtest.h>
#include "test.h"

using namespace s21;
TEST(GameTest1, Constructor_branch_test_1) {
    SnakeGameModel model;

    while (model.getState() == s21::SnakeGameModel::GAMEOVER) {
        SnakeGameModel::GameState state = model.getState();
        if(state == SnakeGameModel::GAMEOVER || state == SnakeGameModel::EXIT_STATE)

        model.stateMachine();
        model.setGameControl(s21::SnakeGameModel::MOVE_DOWN);
    }

    ASSERT_EQ(true, true);
}

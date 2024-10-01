#include <gtest/gtest.h>
#include "../inc/SnakeGameModel.h"
#include "../inc/FabricSnakeFood.h"
#include "../inc/SnakeModel.h"


 using namespace s21;
 TEST(SnakeTest, Init) {
    SnakeGameModel model;
    model.setGameControl(s21::SnakeGameModel::STAR_GAME);
    SnakeGameModel::GameControl control = model.getGameControl();
    ASSERT_EQ(model.getGameControl(), control);
}

TEST(SnakeTest1, reset) {
     SnakeGameModel model;
     model.setGameControl(s21::SnakeGameModel::STAR_GAME);
    for (int i = 0; i < 20; ++i) {
        model.stateMachine();
    }
    model.reset();
    ASSERT_TRUE(model.getScore() == 0 && model.getGameControl() == SnakeGameModel::MOVE_DOWN);
 }

TEST(SnakeTest2, GameOver){
     SnakeGameModel model;
     model.disableDelay();
     model.setGameControl(s21::SnakeGameModel::STAR_GAME);
    while (model.getState() != SnakeGameModel::GAMEOVER) {
        model.stateMachine();
    }
    ASSERT_EQ(model.getState(), SnakeGameModel::GAMEOVER);
 }

TEST(SnakeTest3, PauseTest) {
     SnakeGameModel model(0);
     model.setGameControl(s21::SnakeGameModel::STAR_GAME);
    for (int i = 0; i < 5; ++i)
        model.stateMachine();
    model.setGameControl(s21::SnakeGameModel::PAUSE_GAME);
    model.stateMachine();

    model.log();
    SnakeGameModel::GameState check_state = model.getState();
    ASSERT_EQ(check_state, s21::SnakeGameModel::PAUSE);
    model.setGameControl(s21::SnakeGameModel::PAUSE_GAME);
    model.stateMachine();
    ASSERT_EQ(model.getState(), s21::SnakeGameModel::MOVING);

 }

TEST(SnakeTest3, SnakeDirection) {
    SnakeGameModel model;
    SnakeModel snake;
    model.disableDelay();
    model.setGameControl(s21::SnakeGameModel::STAR_GAME);
    for (int i = 0; i < 6; ++i) {
        model.stateMachine();
    }
    model.log();
    snake = model.getSnakeModel();
    ASSERT_EQ(model.getGameControl(), SnakeGameModel::MOVE_DOWN);
    ASSERT_EQ(snake.getDirection(), SnakeModel::Direction::MoveDown);
    ASSERT_TRUE(snake[0].x == 0 && snake[0].y == 4);

    model.setGameControl(s21::SnakeGameModel::MOVE_RIGHT);
    for (int i = 0; i < 6; ++i) {
        model.stateMachine();
    }
    model.log();
    snake = model.getSnakeModel();
    ASSERT_EQ(model.getGameControl(), SnakeGameModel::MOVE_RIGHT);
    ASSERT_EQ(snake.getDirection(), SnakeModel::Direction::MoveRight);
    ASSERT_TRUE(snake[0].x == 6 && snake[0].y == 4);

    model.setGameControl(s21::SnakeGameModel::MOVE_UP);
    for (int i = 0; i < 4; ++i) {
        model.stateMachine();
    }

    model.log();
    snake = model.getSnakeModel();
    ASSERT_EQ(model.getGameControl(), SnakeGameModel::MOVE_UP);
    ASSERT_EQ(snake.getDirection(), SnakeModel::Direction::MoveUp);
    ASSERT_TRUE(snake[0].x == 6 && snake[0].y == 0);

    model.setGameControl(s21::SnakeGameModel::MOVE_LEFT);
    for (int i = 0; i < 10; ++i) {
        model.stateMachine();
    }
    model.log();
    snake = model.getSnakeModel();
    ASSERT_EQ(model.getGameControl(), SnakeGameModel::MOVE_LEFT);
    ASSERT_EQ(snake.getDirection(), SnakeModel::Direction::MoveLeft);
    ASSERT_TRUE(snake[0].x == 0 && snake[0].y == 0);
    ASSERT_EQ(model.getState(), SnakeGameModel::GAMEOVER);

 }
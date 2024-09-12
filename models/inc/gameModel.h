//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H
// models/inc/gameModel.h
#include "boardModel.h"
#include "TetrominoFactory.h"
#include "Timer.h"
#include <functional>
#include <chrono>
#include <cstdint>

using namespace std::chrono;
class GameModel {
public:
    enum stateGame{START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE};
    enum gameControl {  NOSIG = 0
        ,MOVE_UP
        ,MOVE_DOWN
        ,MOVE_RIGHT
        ,MOVE_LEFT
        ,STAR_PAUSE_GAME
        ,EXIT_GAME
        ,STOP_GAME};
    GameModel();
    BoardModel getBoardModel();
    Tetromino getCurrentTetromino();
    Tetromino getNextTetromino();
    void setGameControl(gameControl control);
    gameControl getGameControl();
    stateGame getStateGame();
    void stateMachine();
private:
    BoardModel* m_gBoard;
    Tetromino* m_currShape;
    Tetromino* m_nextShape;
    Timer* timerDown;
    Timer* timerControl;
    int score;
    gameControl input;
    stateGame state;
    bool checkPos(Tetromino* shape);
    bool genRandomShape(Tetromino* shape);
    void userAction(gameControl g_input);
    void removeFullRowsAndUpdateScore();
    void start_action();
};

#endif //BRICKGAME_GAMEOBJ_H

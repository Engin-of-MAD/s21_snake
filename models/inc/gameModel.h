//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H

#include <ctime>
#include <sys/time.h>
#include <memory>

#include "Timer.h"
#include "boardModel.h"
#include "TetrominoFactory.h"

class GameModel {
public:
    enum stateGame{START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE};
    enum gameControl {  MOVE_UP = 0,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        STAR_PAUSE_GAME,
        EXIT_GAME,
        STOP_GAME,
        NOSIG};
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

//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H

#include <ctime>
#include <sys/time.h>
#include <memory>


#include "boardModel.h"
#include "TetraminoFactory.h"

class GameModel {
public:
    enum stateGame{START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE};
    enum gameControl {  MOVE_UP = 0,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        STAR_PAUSE_GAME,
        EXIT_GAME,
        STOP_GAME};
    GameModel();
    BoardModel* getBoardModel();
    void setGameControl(gameControl control);
    gameControl getGameControl();
    stateGame getStateGame();
    void stateMachine();
private:
    BoardModel* m_gBoard;
    Tetromino* m_currShape;
    Tetromino* m_nextShape;

    int score;
    struct timeval before_now, now; // time points
    gameControl input;
    stateGame state;
    suseconds_t timer;

    bool checkPos(Tetromino* shape);
    bool genRandomShape(Tetromino* shape);

    bool delay();
    suseconds_t getMicroSeconds(struct timeval timeDiff);
    void userAction(gameControl g_input);
    void updateScore();
    void start_action();
};



#endif //BRICKGAME_GAMEOBJ_H

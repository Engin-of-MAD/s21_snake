//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H
// #include "../brick_game/tetris/tetris.h"
// #include <initializer_list>

#include <ctime>
#include <sys/time.h>

#include "boardModel.h"
#include "shapeModel.h"


class GameModel {
    const char shapesArray[7] = {'S', 'Z','T','L','J', 'O', 'I'};
    enum stateGame{START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE};
    enum gameControl {  MOVE_UP = 0,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        STAR_PAUSE_GAME,
        EXIT_GAME,
        STOP_GAME};
    BoardModel m_gBoard;
    Shape m_currShape;
    Shape m_nextShape;

    int score;
    struct timeval before_now, now; // time points
    gameControl input;
    stateGame state;
    suseconds_t timer;


    bool genRandomShape(Shape& shape);
    suseconds_t getMicroSeconds(struct timeval timeDiff);
    bool delay();
    bool checkPos(Shape& shape);
    void userAction(gameControl g_input);
    void updateScore();
    void stateMachine();
    void start_action();
public:
    GameModel();
    BoardModel getBoardModel();
};



#endif //BRICKGAME_GAMEOBJ_H

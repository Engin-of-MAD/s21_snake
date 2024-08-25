//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H
// #include "../brick_game/tetris/tetris.h"
// #include <initializer_list>
#include <Qt>
#include <ctime>
#include <sys/time.h>

#include "boardModel.h"
#include "shapeModel.h"








class GameObject {
    const char shapesArray[7] = {'S', 'Z','T','L','J', 'O', 'I'};
    enum stateGame{START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE};
    enum gameControl {  MOVE_UP = 0,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        STAR_PAUSE_GAME,
        EXIT_GAME,
        STOP_GAME};
    GameBoard* m_gBoard;
    Shapes* m_currShape;
    Shapes* m_nextShape;

    int score, bestScore;
    struct timeval before_now, now; // time points
    gameControl input;
    stateGame state;
    suseconds_t timer;


    bool genRandomShape(Shapes* newShape);
    suseconds_t getMicroSeconds(struct timeval timeDiff);
    bool delay();
    bool checkPos(Shapes& shape);
    void userAction(gameControl g_input);
    void removeFullRows();
    void updateScore();
    void stateMachine();
    void start_action();
public:
    GameObject();
};



#endif //BRICKGAME_GAMEOBJ_H

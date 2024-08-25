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
typedef enum {START = 0, SPAWN, MOVING, PAUSE, GAMEOVER, EXIT_STATE} stateGame;







class GameObject {

    GameBoard* m_gBoard;
    Shapes* m_currShape;
    Shapes* m_nextShape;
    stateGame state;
    int score, bestScore;
    struct timeval before_now, now; // time points
    int input;
    suseconds_t timer;
    const char shapesArray[7] = {'S', 'Z','T','L','J', 'O', 'I'};

    bool genRandomShape(Shapes* newShape, GameBoard* board);
    suseconds_t getMicroSeconds(struct timeval timeDiff);
    bool delay();
    bool chekPos(Shapes* shape, GameBoard* board);
//    void userAction(stateGame state);
    void removeFullRows();
    void updateScore();
    void stateMachine();
    void start_action(const int input, stateGame state);
public:
    GameObject();
};



#endif //BRICKGAME_GAMEOBJ_H

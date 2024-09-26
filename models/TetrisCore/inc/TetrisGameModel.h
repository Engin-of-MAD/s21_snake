//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H

#include "TetrisBoardModel.h"
#include "TetrominoFactory.h"
#include "../../SharedModule/inc/Timer.h"
#include <chrono>
#include <algorithm>
#include <fstream>
namespace s21 {
    class TetrisGameModel {
    public:
        enum stateGame {
            START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE
        };
        enum gameControl {
            NOSIG = 0, MOVE_UP, MOVE_DOWN, MOVE_RIGHT, MOVE_LEFT, STAR_GAME, PAUSE_GAME, EXIT_GAME, STOP_GAME
        };

        TetrisGameModel();
        ~TetrisGameModel();
        TetrisBoardModel getBoardModel();
        Tetromino getCurrentTetromino();
        Tetromino getNextTetromino();
        void setGameControl(gameControl control);
        gameControl getGameControl();
        stateGame getStateGame();

        int getScore() const;
        int getBestScore() const;
        void stateMachine();
        void resetGame();

    private:

        TetrisBoardModel *m_gBoard;
        std::string nameDataFile;
        Tetromino *m_currShape;
        Tetromino *m_nextShape;
        Timer *timerDown;
        Timer *timerControl;
        int score, bestScore;
        gameControl input;
        stateGame state;

        bool checkPos(Tetromino *shape);
        bool genRandomShape(Tetromino *shape);
        void userAction(gameControl g_input);
        void removeFullRowsAndUpdateScore();
        void start_action();
        void spawn_action();
        void move_action();
        void stop_action();
        void exit_action();
        void pause_action();
        int readFromFile();
        void writeToFile();
    };
}
#endif //BRICKGAME_GAMEOBJ_H

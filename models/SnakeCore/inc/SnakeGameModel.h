//
// Created by roach on 18.09.2024.
//

#ifndef SNAKEGAMEMODEL_H
#define SNAKEGAMEMODEL_H
#include "../../UnionModule/inc/BaseBoardModel.h"
#include "../../UnionModule/inc/Timer.h"
#include "FabricSnakeFood.h"
#include "SnakeModel.h"
#include <algorithm>
#include <fstream>
#include <string>
namespace s21 {
    class SnakeGameModel {
    public:
        enum GameState { START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE};
        enum GameControl {
            NOSIG = 0, MOVE_UP, MOVE_DOWN, MOVE_RIGHT, MOVE_LEFT, STAR_GAME, PAUSE_GAME, EXIT_GAME, STOP_GAME};
        SnakeGameModel();
        ~SnakeGameModel();
        void stateMachine();
        void reset();
        void setGameControl(GameControl control);
        BaseBoardModel& getGameBoard();
        SnakeModel& getSnakeModel();
        SnakeFood& getSnakeFood();
        GameState getState();
        GameControl getGameControl();
        int getScore() const;
        int getBestScore() const;
        void log();
    private:
        int readFromFile();
        void writeToFile();
        bool isBorders(SnakeItem head);
        bool checkPos(SnakeItem head);
        void startAction();
        void stopAction();
        void pauseAction();
        void exitAction();
        void spawnAction();
        void movingAction();
        void gameControl();
        int m_score, m_bestScore;
        std::string nameDataFile;
        GameControl m_userControl;
        GameState m_state;
        Timer m_timerDown;
        BaseBoardModel m_board;
        SnakeModel m_snake;
        void updateScore();
        SnakeFood m_food;
    };

}
#endif //SNAKEGAMEMODEL_H

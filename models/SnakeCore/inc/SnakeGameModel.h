//
// Created by roach on 18.09.2024.
//

#ifndef SNAKEGAMEMODEL_H
#define SNAKEGAMEMODEL_H
#include "../../inc/BaseBoardModel.h"
#include "SnakeModel.h"
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
        void setState(GameState gameState);
        BaseBoardModel& getGameBoard();
        SnakeModel& getSnakeModel();
        GameState getState();
        GameControl getGameControl(GameControl control);
        int getScore();
        int getBestScore();
    private:
        bool isBorders();
        bool checkPos();
        void startAction();
        void movingAction();
        void gameControl();
        int m_score, m_bestScore;
        GameControl m_userControl;
        GameState m_state;
        BaseBoardModel* m_board;
        SnakeModel* m_snake;
    };

}
#endif //SNAKEGAMEMODEL_H

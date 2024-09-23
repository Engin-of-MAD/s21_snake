//
// Created by roach on 18.09.2024.
//

#ifndef SNAKEGAMEMODEL_H
#define SNAKEGAMEMODEL_H
#include "../../SharedModule/inc/BaseBoardModel.h"
#include "../../SharedModule/inc/Timer.h"
#include "FabricSnakeFood.h"
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
        SnakeFood& getSnakeFood();
        GameState getState();
        GameControl getGameControl();
        int getScore() const;
        int getBestScore() const;
    private:
        bool isBorders(SnakeItem head);
        bool checkPos(SnakeItem head);
        void startAction();
        void spawnAction();
        void movingAction();
        void gameControl();
        int m_score, m_bestScore;
        GameControl m_userControl;
        GameState m_state;
        Timer* m_timerDown;
        BaseBoardModel* m_board;
        SnakeModel* m_snake;
        SnakeFood* m_food;
    };

}
#endif //SNAKEGAMEMODEL_H

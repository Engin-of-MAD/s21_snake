//
// Created by roach on 18.09.2024.
//

#include "../inc/SnakeGameModel.h"
namespace s21 {

    SnakeGameModel::SnakeGameModel()
    : m_board(new BaseBoardModel(10, 20))
    , m_snake(new SnakeModel(4, m_board->getSizeCell() - 4))
    , m_state(START), m_userControl(NOSIG), m_score(0), m_bestScore(0){}
    SnakeGameModel::~SnakeGameModel() {
        delete m_board;
        delete m_snake;
    }

    void SnakeGameModel::setGameControl(SnakeGameModel::GameControl control) { m_userControl = control; }
    void SnakeGameModel::setState(SnakeGameModel::GameState gameState) { m_state = gameState; }
    SnakeGameModel::GameControl SnakeGameModel::getGameControl(SnakeGameModel::GameControl control) {return m_userControl; }
    SnakeGameModel::GameState SnakeGameModel::getState() { return m_state; }
    BaseBoardModel &SnakeGameModel::getGameBoard() { return *m_board; }
    SnakeModel &SnakeGameModel::getSnakeModel() { return *m_snake; }
    int SnakeGameModel::getScore() { return m_score; }
    int SnakeGameModel::getBestScore() { return m_bestScore; }

    void SnakeGameModel::gameControl() {
        SnakeModel tmp(*m_snake);
        switch (m_userControl) {
            case MOVE_DOWN:
                tmp[0].y -= 1;
                if(checkPos()) (*m_snake)[0].y -= 1;
                break;
            case MOVE_UP:
                tmp[0].y += 1;
                if(checkPos()) (*m_snake)[0].y += 1;
                break;
            case MOVE_LEFT:
                tmp[0].x -= 1;
                if(checkPos()) (*m_snake)[0].x -= 1;
                break;
            case MOVE_RIGHT:
                tmp[0].x += 1;
                if(checkPos()) (*m_snake)[0].x += 1;
                break;
        }
    }

    bool SnakeGameModel::checkPos() {
        for (int y = 0; y < m_board->getHeight(); ++y) {
            for (int x = 0; x < m_board->getWidth(); ++x) {
                if (isBorders() || m_snake->isSnake(x, y)
                || m_snake->checkSelfIntersection(x, y)) return false;
            }
        }
        return true;
    }

    bool SnakeGameModel::isBorders() {
        bool checkX, checkY;
        checkX = (*m_snake)[0].x < 0 || (*m_snake)[0].x >= m_board->getWidth();
        checkY = (*m_snake)[0].y < 0 || (*m_snake)[0].y >= m_board->getHeight();
        return checkX || checkY;
    }

    void SnakeGameModel::stateMachine() {
        switch (m_state) {
            case START: startAction(); break;
            case SPAWN:
                break;
            case MOVING:
                movingAction();
                break;
            case PAUSE:
                break;
        }
    }

    void SnakeGameModel::startAction() {
        if (m_userControl == STAR_GAME) m_state = SPAWN;
        if (m_userControl == EXIT_GAME) m_state = EXIT_STATE;
    }

    void SnakeGameModel::movingAction() {
        gameControl();
    }

    void SnakeGameModel::reset() {

    }


}

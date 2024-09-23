//
// Created by roach on 18.09.2024.
//

#include "../inc/SnakeGameModel.h"
namespace s21 {

    SnakeGameModel::SnakeGameModel()
    : m_board(new BaseBoardModel(10, 20))
    , m_snake(new SnakeModel(4, m_board->getSizeCell() - 4))
    , m_food(new SnakeFood()), m_timerDown(new Timer())
    , m_state(START), m_userControl(MOVE_DOWN)
    , m_score(0), m_bestScore(0){}

    SnakeGameModel::~SnakeGameModel() {
        delete m_board;
        delete m_snake;
        delete m_timerDown;
    }

    void SnakeGameModel::setGameControl(SnakeGameModel::GameControl control) { m_userControl = control; }
    void SnakeGameModel::setState(SnakeGameModel::GameState gameState) { m_state = gameState; }
    SnakeGameModel::GameControl SnakeGameModel::getGameControl() {return m_userControl; }
    SnakeGameModel::GameState SnakeGameModel::getState() { return m_state; }
    BaseBoardModel &SnakeGameModel::getGameBoard() { return *m_board; }
    SnakeModel &SnakeGameModel::getSnakeModel() { return *m_snake; }
    int SnakeGameModel::getScore() const { return m_score; }
    int SnakeGameModel::getBestScore() const { return m_bestScore; }


    void SnakeGameModel::gameControl() {
        SnakeModel tmp = *m_snake;
        std::cerr << "Input: " << m_userControl << std::endl;
        switch (m_userControl) {
            case MOVE_UP: tmp.setDirection(SnakeModel::Direction::MoveUp); break;
            case MOVE_LEFT: tmp.setDirection(SnakeModel::Direction::MoveLeft); break;
            case MOVE_DOWN: tmp.setDirection(SnakeModel::Direction::MoveDown); break;
            case MOVE_RIGHT: tmp.setDirection(SnakeModel::Direction::MoveRight); break;
        }
        tmp.update();
        if (checkPos(*tmp[0]))
            m_state = GAMEOVER;
        else *m_snake = tmp;
    }

    bool SnakeGameModel::checkPos(SnakeItem head) {
        for (int y = 0; y < m_board->getHeight(); ++y) {
            for (int x = 0; x < m_board->getWidth(); ++x) {
                if (isBorders(head) || !m_snake->isBody(head)) return true;
            }
        }
        return false;
    }

    bool SnakeGameModel::isBorders(SnakeItem head) {
        bool checkX, checkY;
        checkX = head.x < 0 || head.x >= m_board->getWidth();
        checkY = head.y < 0 || head.y >= m_board->getHeight();
        return checkX || checkY;
    }

    void SnakeGameModel::stateMachine() {
        switch (m_state) {
            case START: startAction(); break;
            case SPAWN: spawnAction(); break;
            case MOVING: movingAction(); break;
        }
    }

    void SnakeGameModel::startAction() {
        if (m_userControl == STAR_GAME) {
            m_state = SPAWN;
            m_userControl = MOVE_DOWN;
        }
        if (m_userControl == EXIT_GAME) m_state = EXIT_STATE;
    }

    void SnakeGameModel::spawnAction() {
        SnakeFood food(FabricSnakeFood::createFood());
        bool correctFood = false;
        while (!correctFood) {
            if (m_snake->isSnake(food.getX(), food.getY())) {
                *m_food = food;
                correctFood = true;
                m_state = MOVING;
            }
        }
        m_food->log();
    }

    void SnakeGameModel::movingAction() {
        m_timerDown->setCurrentTime(Clock::now());
        if (m_timerDown->delay(Milliseconds{200})) {
            m_timerDown->setLastUpdateTime(Clock::now());
            gameControl();
        }
    }

    void SnakeGameModel::reset() {
        m_board->reset();
        delete m_snake;
        delete m_food;
        m_food = new SnakeFood(FabricSnakeFood::createFood());
        m_snake = new SnakeModel(4, m_board->getSizeCell() - 4);
        m_state = START;
        m_userControl = MOVE_DOWN;
    }

    SnakeFood &SnakeGameModel::getSnakeFood() {
        return *m_food;
    }
}

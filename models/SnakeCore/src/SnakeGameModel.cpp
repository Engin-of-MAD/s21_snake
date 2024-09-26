//
// Created by roach on 18.09.2024.
//

#include "../inc/SnakeGameModel.h"
namespace s21 {

    SnakeGameModel::SnakeGameModel()
    : m_score(0)
    , m_bestScore(0)
    , nameDataFile("snakeData.txt"), m_userControl(MOVE_DOWN)
    , m_state(START), m_timerDown(Timer())
    , m_board(BaseBoardModel(10, 20)), m_snake( SnakeModel(4, m_board.getSizeCell() - 4)), m_food(SnakeFood()){
        m_bestScore = readFromFile();
    }


    SnakeGameModel::~SnakeGameModel() {}

    void SnakeGameModel::setGameControl(SnakeGameModel::GameControl control) { m_userControl = control; }
    SnakeGameModel::GameControl SnakeGameModel::getGameControl() {return m_userControl; }
    SnakeGameModel::GameState SnakeGameModel::getState() { return m_state; }
    BaseBoardModel &SnakeGameModel::getGameBoard() { return m_board; }
    SnakeModel &SnakeGameModel::getSnakeModel() { return m_snake; }
    int SnakeGameModel::getScore() const { return m_score; }
    int SnakeGameModel::getBestScore() const { return m_bestScore; }


    void SnakeGameModel::gameControl() {
        SnakeModel tmp = m_snake;
//        std::cerr << "Input: " << m_userControl << std::endl;
        switch (m_userControl) {
            case MOVE_UP: tmp.setDirection(SnakeModel::Direction::MoveUp); break;
            case MOVE_LEFT: tmp.setDirection(SnakeModel::Direction::MoveLeft); break;
            case MOVE_DOWN: tmp.setDirection(SnakeModel::Direction::MoveDown); break;
            case MOVE_RIGHT: tmp.setDirection(SnakeModel::Direction::MoveRight); break;
            case PAUSE_GAME: m_state = PAUSE;
            case NOSIG: break;
            case STAR_GAME: m_state = START;break;
            case EXIT_GAME: m_state = EXIT_STATE; break;
            case STOP_GAME: m_state = STOP; break;
        }
        tmp.update();

        if (checkPos((*tmp.begin())))
            m_state = GAMEOVER;
        else {
            m_snake = tmp;
            if (m_food.isFood((*tmp.begin()).x, (*tmp.begin()).y)){
                m_snake.addTail();
                m_state = SPAWN;
                updateScore();
            }
        }
    }

    bool SnakeGameModel::checkPos(SnakeItem head) {
        for (int y = 0; y < m_board.getHeight(); ++y) {
            for (int x = 0; x < m_board.getWidth(); ++x) {
                if (isBorders(head) || !m_snake.isBody(head)) return true;
            }
        }
        return false;
    }

    bool SnakeGameModel::isBorders(SnakeItem head) {
        bool checkX, checkY;
        checkX = head.x < 0 || head.x >= m_board.getWidth();
        checkY = head.y < 0 || head.y >= m_board.getHeight();
        return checkX || checkY;
    }

    void SnakeGameModel::stateMachine() {
        switch (m_state) {
            case START: startAction(); break;
            case SPAWN: spawnAction(); break;
            case MOVING: movingAction(); break;
            case PAUSE: pauseAction(); break;
            case GAMEOVER: writeToFile(); break;
            case STOP: stopAction(); break;
            case EXIT_STATE: exitAction(); break;
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
        if (m_snake.isSnake(food.getX(), food.getY())) {
                m_food = food;
                m_state = MOVING;
        }
        m_food.log();
    }

    void SnakeGameModel::movingAction() {
        m_timerDown.setCurrentTime(Clock::now());
        if (m_timerDown.delay(Milliseconds{200})) {
            m_timerDown.setLastUpdateTime(Clock::now());
            gameControl();
        }
    }

    void SnakeGameModel::reset() {
        m_food = SnakeFood(FabricSnakeFood::createFood());
        m_snake = SnakeModel(4, m_board.getSizeCell() - 4);
        m_state = START;
        m_userControl = MOVE_DOWN;
        m_score = 0;
    }

    SnakeFood &SnakeGameModel::getSnakeFood() {
        return m_food;
    }

    void SnakeGameModel::updateScore() {
        m_score += 1;
        m_bestScore = m_score > m_bestScore ? m_score : m_bestScore;
    }

    void SnakeGameModel::log() {
        std::cout << "SnakeGameModel: " << this << ", Score: " << m_score << ", Best: " << m_bestScore << std::endl;
        m_snake.log();
        m_food.log();
    }

    int SnakeGameModel::readFromFile() {
        std::fstream file(nameDataFile);
        std::vector<int> nums;
        int maxElement = 0;
        if(!file.is_open()){ return -1;}
        while (file >> maxElement){ nums.push_back(maxElement);}

        file.close();
        maxElement = 0;
        std::cout << "Data from file:" << std::endl;
        for (int num : nums) {std::cout << num  << std::endl;}
        if (!nums.empty()) {
            maxElement = *std::max_element(nums.begin(), nums.end());
            std::cout << "Get max num from file: " << maxElement << std::endl;
        } else {
            std::cout << "File empty"<< std::endl;
            maxElement = 0;
        }
        return maxElement;
    }

    void SnakeGameModel::writeToFile() {
        int tmp = readFromFile();
        std::fstream file(nameDataFile, std::ios_base::app);
        if (file.is_open() && m_bestScore > 0 && m_bestScore > tmp) {
            file << m_bestScore << std::endl;
        }
    }

    void SnakeGameModel::stopAction() {
        if(m_userControl == STOP_GAME){
            m_state = MOVING;}
    }
    void SnakeGameModel::pauseAction() {
        if (m_userControl == PAUSE_GAME)
            m_state = MOVING;
    }
    void SnakeGameModel::exitAction() {
        if(m_userControl == PAUSE_GAME){
            m_state = MOVING;}
    }


}

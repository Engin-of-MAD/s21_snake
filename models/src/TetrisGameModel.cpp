#include "../inc/TetrisGameModel.h"
// models/src/m_gameModel.cpp
namespace s21 {
    TetrisGameModel::TetrisGameModel()
            : m_gBoard(new TetrisBoardModel(10, 20)), score(0), bestScore(0), state(START),
              m_currShape(new Tetromino()), m_nextShape(new Tetromino(TetrominoFactory::randomTetromino())),
              timerDown(new Timer()), timerControl(new Timer()) {
    }


    void TetrisGameModel::userAction(gameControl g_input) {
        Tetromino temp(*m_currShape);
        switch (g_input) {
            case MOVE_DOWN:
                temp.increaseCordY();
                if (checkPos(&temp)) m_currShape->increaseCordY();
                else {
                    m_gBoard->setShapeOnBoard(*m_currShape);
                    removeFullRowsAndUpdateScore();
                    state = SPAWN;
                }
                break;
            case MOVE_RIGHT:
                temp.increaseCordX();
                if (checkPos(&temp)) m_currShape->increaseCordX();
                break;
            case MOVE_LEFT:
                temp.decreaseCordX();
                if (checkPos(&temp)) m_currShape->decreaseCordX();
                break;
            case MOVE_UP:
                temp.rotate();
                if (checkPos(&temp)) m_currShape->rotate();
                break;
            case STAR_GAME:
                if (state == START) state = SPAWN;
                if (state == MOVING) state = PAUSE;
                if (state == PAUSE) state = MOVING;
                break;
            case STOP_GAME:
                state = STOP;
                break;
            case EXIT_GAME:
                state = EXIT_STATE;
                break;
        }
    }

    void TetrisGameModel::start_action() {
        if (input == STAR_GAME) state = SPAWN;
        if (input == EXIT_GAME) state = EXIT_STATE;
    }

    void TetrisGameModel::move_action() {
        std::cout << "Input: " << input << std::endl;
        if (input == PAUSE_GAME) {
            state = PAUSE;
            input = NOSIG; // для моментального сброса состояния переменной движения
        }
        timerControl->setCurrentTime(Clock::now());
        if (input) {
            if (timerControl->delay(std::chrono::milliseconds{100})) {
                userAction(input);
                timerControl->setLastUpdateTime(Clock::now());
            }
        }
        timerDown->setCurrentTime(Clock::now());
        if (timerDown->delay(std::chrono::milliseconds{250})) {
            userAction(MOVE_DOWN);
            timerDown->setLastUpdateTime(Clock::now());
        }

    }

    void TetrisGameModel::stateMachine() {
        switch (state) {
            case START:
                start_action();
                break;
            case SPAWN:
                *m_currShape = *m_nextShape;
                state = genRandomShape(m_nextShape) ? GAMEOVER : MOVING;
                break;
            case MOVING:
                move_action();
                break;
            case PAUSE:
                if (input == PAUSE_GAME) {
                    state = MOVING;
                    input = NOSIG; // для моментального сброса состояния переменной движения
                }
                break;
        }
    }

    bool TetrisGameModel::genRandomShape(Tetromino *shape) {
        bool collision = false;
        *(shape) = std::move(TetrominoFactory::randomTetromino());
        shape->setCordX(rand() % (m_gBoard->getWidth() - shape->getWidth() + 1));
        if (!checkPos(shape))
            collision = true;
        return collision;
    }

    bool TetrisGameModel::checkPos(Tetromino *shape) {
        for (int i = 0; i < shape->getWidth(); i++) {
            for (int j = 0; j < shape->getWidth(); j++) {
                int col = shape->getCordX() + j;
                int row = shape->getCordY() + i;
                int width = m_gBoard->getWidth();
                int height = m_gBoard->getHeight();
                bool checkShape = (*shape)[i][j];
                if (col < 0 || col >= width || row >= height) {
                    if (checkShape) return false;
                } else if ((*m_gBoard)[row][col] && checkShape)
                    return false;
            }
        }
        return true;
    }

    TetrisBoardModel TetrisGameModel::getBoardModel() { return *m_gBoard; }

    void TetrisGameModel::setGameControl(TetrisGameModel::gameControl control) { input = control; }

    TetrisGameModel::gameControl TetrisGameModel::getGameControl() { return input; }

    TetrisGameModel::stateGame TetrisGameModel::getStateGame() { return state; }

    Tetromino TetrisGameModel::getCurrentTetromino() {
        return *m_currShape;
    }

    Tetromino TetrisGameModel::getNextTetromino() {
        return *m_nextShape;
    }

    void TetrisGameModel::removeFullRowsAndUpdateScore() {
        int removedRowsCount = 0;
        for (int rowI = 0; rowI < m_gBoard->getHeight(); ++rowI) {
            if (m_gBoard->isRowFull(rowI)) {
                m_gBoard->clearRow(rowI);
                m_gBoard->shiftDownRows(rowI);
                removedRowsCount++;
            }
        }
        score += 100 * removedRowsCount;
        bestScore = score > bestScore ? score : bestScore;
    }

    int TetrisGameModel::getScore() const { return score; }

    int TetrisGameModel::getBestScore() const { return bestScore; }

    TetrisGameModel::~TetrisGameModel() {
        delete m_gBoard;
        delete m_currShape;
        delete m_nextShape;
        delete timerDown;
        delete timerControl;
    }

    void TetrisGameModel::resetGame() {
        m_gBoard->reset();
        input = NOSIG;
        state = START;
        delete m_currShape;
        delete m_nextShape;
        m_currShape = nullptr;
        m_nextShape = nullptr;
        m_currShape = new Tetromino();
        m_nextShape = new Tetromino(TetrominoFactory::randomTetromino());
        score = 0;
    }
}
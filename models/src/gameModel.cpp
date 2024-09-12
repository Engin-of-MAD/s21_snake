#include "../inc/gameModel.h"
// models/src/gameModel.cpp
GameModel::GameModel()
    : m_gBoard(new BoardModel(10, 20))
    , score(0), bestScore(0), state(START)
    , m_currShape(new Tetromino()), m_nextShape(new Tetromino())
    , timerDown(new Timer()), timerControl(new Timer()){}

void GameModel::userAction(gameControl g_input) {
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
        case STAR_PAUSE_GAME:
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

void GameModel::start_action() {
    if (input == STAR_PAUSE_GAME) state = SPAWN;
    if (input == EXIT_GAME) state = EXIT_STATE;
}

void GameModel::stateMachine() {
    switch (state) {
        case START:
            start_action();
            break;
        case SPAWN:
            m_currShape = m_nextShape;
            state = genRandomShape(m_nextShape) ? GAMEOVER : MOVING;
            break;
        case MOVING:
            timerControl->setCurrentTime(Clock::now());
            if (input) {
                if (timerControl->delay(milliseconds{100})) {
                    userAction(input);
                    timerControl->setLastUpdateTime(Clock::now());
                }
            }

            timerDown->setCurrentTime(Clock::now());
            if (timerDown->delay(milliseconds{250})){
                userAction(MOVE_DOWN);
                timerDown->setLastUpdateTime(Clock::now());
            }
            break;
    }
}

bool GameModel::genRandomShape(Tetromino* shape) {
    bool collision = false;
    *shape = std::move(TetrominoFactory::randomTetromino());
    shape->setCordX(rand() % (m_gBoard->width() - shape->getWidth() + 1));
    if (!checkPos(shape))
        collision = true;
    return collision;
}

bool GameModel::checkPos(Tetromino* shape) {
    for (int i = 0; i < shape->getWidth(); i++) {
        for (int j = 0; j < shape->getWidth(); j++) {
            int col = shape->getCordX() + j;
            int row = shape->getCordY() + i;
            int width = m_gBoard->width();
            int height = m_gBoard->height();
            bool checkShape = (*shape)[i][j];
            if (col < 0 || col >= width || row >= height) {
                if (checkShape) return false;
            } else if ((*m_gBoard)[row][col] && checkShape)
                return false;
        }
    }
    return true;
}

BoardModel GameModel::getBoardModel() { return *m_gBoard; }
void GameModel::setGameControl(GameModel::gameControl control) {input = control;}
GameModel::gameControl GameModel::getGameControl() {return input;}
GameModel::stateGame GameModel::getStateGame() {return state;}

Tetromino GameModel::getCurrentTetromino() {
    return *m_currShape;
}

Tetromino GameModel::getNextTetromino() {
    return *m_nextShape;
}

void GameModel::removeFullRowsAndUpdateScore() {
    int removedRowsCount = 0;
    for (int rowI = 0; rowI < m_gBoard->height(); ++rowI) {
        if (m_gBoard->isRowFull(rowI)) {
            m_gBoard->clearRow(rowI);
            m_gBoard->shiftDownRows(rowI);
            removedRowsCount++;
        }
    }
    score += 100 * removedRowsCount;
    bestScore = score > bestScore ? score : bestScore;
    std::cout << "Score: "<< score << ", BestScore: " << bestScore << std::endl;
}

int GameModel::getScore() { return score; }
int GameModel::getBestScore() { return bestScore; }


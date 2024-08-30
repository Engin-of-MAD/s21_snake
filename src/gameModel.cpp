#include "gameModel.h"

GameModel::GameModel()
        : m_gBoard(new BoardModel(10, 20))
        , score(0) , timer(1000000), state(START)
        , m_currShape(nullptr), m_nextShape(nullptr)
        {}

// getting microseconds for all time
suseconds_t GameModel::getMicroSeconds(struct timeval timeDiff) {
    suseconds_t microSeconds = timeDiff.tv_sec * 1000000 + timeDiff.tv_usec;
    return microSeconds;
}


bool GameModel::delay() {
    return (getMicroSeconds(now) -
            getMicroSeconds(before_now)) > timer;
}

void GameModel::updateScore() {
    int sum, count = 0;
    for (int i = 0; i < m_gBoard->width(); ++i) {
        if (sum == m_gBoard->width()) {
            count++;
            m_gBoard->clearFullRows(sum);
        }
        for (int j = 0; j < m_gBoard->width(); ++j) {
            sum += *m_gBoard[i][j];
        }
    }
    score += 100;
}

void GameModel::userAction(gameControl g_input) {
    Tetromino temp(*m_currShape);

    switch (g_input) {
        case MOVE_DOWN:
            temp.increaseCordY();
            if (checkPos(&temp)) temp.increaseCordY();
            else {
                m_gBoard->setShapeOnBoard(temp);
                updateScore();
                state = SPAWN;
                delete m_currShape;
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
            m_currShape = new Tetromino(TetrominoFactory::randomTetromino());
            state = genRandomShape(m_nextShape) ? GAMEOVER : MOVING;
            break;
        case MOVING:
            userAction(input);
            gettimeofday(&now, nullptr);
            if (delay()) {
                userAction(MOVE_DOWN);
            }
            break;
    }
}

bool GameModel::genRandomShape(Tetromino* shape) {

    Tetromino newShape = TetrominoFactory::randomTetromino();
    bool collision = false;
    if (!checkPos(&newShape))
        collision = true;
    else if (shape != &newShape) *shape = newShape;
    return collision;
}

bool GameModel::checkPos(Tetromino* shape) {
    for (int i = 0; i < shape->getWidth(); ++i) {
        for (int j = 0; j < shape->getWidth(); ++j) {
            if (shape->getCordX() + j < 0 || shape->getCordX() >= m_gBoard->width() || shape->getCordY() + i) {
                if (shape[i][j]) return false;
            } else if (m_gBoard[shape->getCordY() + i][shape->getCordX() + j] && shape[i][j])
                return false;
        }
    }
    return true;
}

BoardModel* GameModel::getBoardModel() {
    return m_gBoard;
}

void GameModel::setGameControl(GameModel::gameControl control) {
    input = control;
}

GameModel::gameControl GameModel::getGameControl() {
    return input;
}

GameModel::stateGame GameModel::getStateGame() {
    return state;
}

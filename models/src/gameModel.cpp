#include "../inc/gameModel.h"
#include <QtCore>
GameModel::GameModel()
    : m_gBoard(new BoardModel(10, 20))
    , score(0) , timer(1000000), state(START)
    , m_currShape(new Tetromino()), m_nextShape(new Tetromino()){}


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
            sum += (*m_gBoard)[i][j];
        }
    }
    score += 100;
}

void GameModel::userAction(gameControl g_input) {

    Tetromino temp(*m_currShape);
    std::cout << char(temp.getName()) << " " << m_currShape << std::endl;
    switch (g_input) {
        case MOVE_DOWN:
            temp.increaseCordY();
            if (checkPos(&temp)) m_currShape->increaseCordY();

            else {
                m_gBoard->setShapeOnBoard(*m_currShape);
                updateScore();
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
            if (NOSIG != input) {
                userAction(input);
            }


            userAction(MOVE_DOWN);

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
            int row = shape->getCordY() + j;
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

#include "gameobj.h"



suseconds_t GameObject::getMicroSeconds(struct timeval timeDiff) {
    suseconds_t microSeconds =
            timeDiff.tv_sec * 1000000 +
            timeDiff.tv_usec; // getting microseconds for all time
    return microSeconds;
}


bool GameObject::delay() {
    return (getMicroSeconds(now) -
            getMicroSeconds(before_now)) > timer;
}

bool GameObject::chekPos(Shapes *shape, GameBoard *board) {
    for (int i = 0; i < shape->width(); ++i) {
        for (int j = 0; j < shape->width(); ++j) {
            if (shape->cordX() + j < 0 || shape->cordX() >= board->width() || shape->cordY() + i) {
                if (*shape[i][j]) return false;
            } else if (*m_gBoard[shape->cordY() + i][shape->cordX() + j] && *shape[i][j])
                return false;
        }
    }
    return true;
}

bool GameObject::genRandomShape(Shapes* newShape, GameBoard* board)
{
    bool collision = false;
    newShape = new Shapes(shapesArray[rand() % 7], rand() % board->width());
    if (!chekPos(newShape, board)) collision = true;
    return collision;
}

void GameObject::removeFullRows() {
    int sum, count = 0;
    for (int i = 0; i < m_gBoard->height(); ++i) {
        sum = 0;
        for (int j = 0; j < m_gBoard->width(); ++j) {
            sum += *m_gBoard[i][j];
        }
        if (sum == m_gBoard->width()){
            ++count;
            int l, k;
            for (k = 0; k >= 1; --k)
                for (l = 0; l < m_gBoard->width(); ++l)
                    *m_gBoard[k][l] = *m_gBoard[k-1][l];
            for ( l = 0; l < m_gBoard->width(); ++l) {
                *m_gBoard[k][l] = 0;
            }
        }
    }
    score += 100;
}

void GameObject::updateScore() {

}

void GameObject::start_action(const int input, stateGame state) {
    if (input == 0) state = SPAWN;
    if (input == 1) state = EXIT_STATE;
}

void GameObject::stateMachine() {
    switch (state) {
        case START:
            break;
        case SPAWN:
            break;
        case MOVING:
            break;
        case PAUSE:
            break;
        case GAMEOVER:
            break;
        case EXIT_STATE:
            break;
    }
}

GameObject::GameObject()
: m_gBoard(new GameBoard(10, 20))
, score(0) , bestScore(0), timer(1000000), state(START)
{
    genRandomShape(m_currShape, m_gBoard);
    genRandomShape(m_nextShape, m_gBoard);

}




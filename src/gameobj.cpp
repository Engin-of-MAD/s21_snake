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

bool GameObject::checkPos(Shapes& shape) {
    for (int i = 0; i < shape.width(); ++i) {
        for (int j = 0; j < shape.width(); ++j) {
            if (shape.cordX() + j < 0 || shape.cordX() >= m_gBoard->width() || shape.cordY() + i) {
                if (shape[i][j]) return false;
            } else if (*m_gBoard[shape.cordY() + i][shape.cordX() + j] && shape[i][j])
                return false;
        }
    }
    return true;
}

bool GameObject::genRandomShape(Shapes* newShape)
{

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


GameObject::GameObject()
: m_gBoard(new GameBoard(10, 20))
, score(0) , bestScore(0), timer(1000000), state(START){}

void GameObject::userAction(gameControl g_input) {
    Shapes temp(*m_currShape);

    switch (g_input) {
        case MOVE_DOWN:
            temp.increaseCordY();
            if (checkPos(temp)) temp.increaseCordY();
            else {
                m_gBoard->setShapeOnBoard(&temp);
                removeFullRows();
                state = SPAWN;
            }
            break;
        case MOVE_RIGHT:
            temp.increaseCordX();
            if (checkPos(temp)) m_currShape->increaseCordX();
            break;
        case MOVE_LEFT:
            temp.decreaseCordX();
            if (checkPos(temp)) m_currShape->decreaseCordX();
            break;
        case MOVE_UP:
            temp.rotateShape();
            if (checkPos(temp)) m_currShape->rotateShape();
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

void GameObject::start_action() {
    if (input == STAR_PAUSE_GAME) state = SPAWN;
    if (input == EXIT_GAME) state = EXIT_STATE;
}

void GameObject::stateMachine() {
    switch (state) {
        case START:
            start_action();
            break;
        case SPAWN:
            m_currShape = new Shapes(*m_nextShape);
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


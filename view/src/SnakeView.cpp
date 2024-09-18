//
// Created by roach on 18.09.2024.
//

#include "../inc/SnakeView.h"

SnakeView::SnakeView(QWidget *parent) : QWidget(parent){
    m_buttonBoard = new ButtonBoardView();
    m_infoBoard = new InfoBoardView();
    m_boardView = new SnakeBoardView(10, 20);
    m_gridLayout = new QGridLayout();
    m_gameModel = new SnakeModel();
    m_gameTimer = new QTimer(this);
    initView();
}

SnakeView::~SnakeView() {
    delete m_buttonBoard;
    delete m_infoBoard;
    delete m_boardView;
    delete m_gridLayout;
    delete m_gameModel;
    delete m_gameTimer;
}

void SnakeView::initView() {
    m_gridLayout->addWidget(m_boardView, 0, 0, 2, 2);
    m_gridLayout->addWidget(m_infoBoard, 0, 2, 1, 1);
    m_gridLayout->addWidget(m_buttonBoard, 1, 2, 1, 1);
    setLayout(m_gridLayout);
    setWindowTitle("Snake Game");
}

void SnakeView::keyPressEvent(QKeyEvent *e) {
    switch(e->key())
    {
//        case Qt::Key_P:
//            m_gameModel->setGameControl(GameModel::PAUSE_GAME);
//            break;
//        case Qt::Key_Return:
//            m_gameModel->setGameControl(GameModel::STAR_GAME);
//            break;
//        case Qt::Key_A:
//            m_gameModel->setGameControl(GameModel::MOVE_LEFT);
//            break;
//        case Qt::Key_D:
//            m_gameModel->setGameControl(GameModel::MOVE_RIGHT);
//            break;
//        case Qt::Key_R:
//            m_gameModel->setGameControl(GameModel::MOVE_UP);
//            break;
//        case Qt::Key_S:
//            m_gameModel->setGameControl(GameModel::MOVE_DOWN);
//            break;
//        case Qt::Key_G:
//            m_gameModel->setGameControl(GameModel::STOP_GAME);
//            break;
//        case Qt::Key_Escape:
//            m_gameModel->setGameControl(GameModel::EXIT_GAME);
//            break;
    }
}

void SnakeView::keyReleaseEvent(QKeyEvent *e) {
    QWidget::keyReleaseEvent(e);
}

void SnakeView::gameLoop() {

}

void SnakeView::startGame() {

}

void SnakeView::pauseGame() {

}

void SnakeView::stopGame() {

}

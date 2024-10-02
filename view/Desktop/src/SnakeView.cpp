//
// Created by roach on 18.09.2024.
//

#include "../inc/SnakeView.h"
namespace s21 {
SnakeView::SnakeView(QWidget *parent) : QWidget(parent) {
  initView();
  connect(m_buttonBoard->getStartBtn(), &QPushButton::clicked, this,
          &SnakeView::startGame);
  connect(m_buttonBoard->getPauseBtn(), &QPushButton::clicked, this,
          &SnakeView::pauseGame);
  connect(m_buttonBoard->getStopBtn(), &QPushButton::clicked, this,
          &SnakeView::stopGame);
  connect(m_gameTimer, &QTimer::timeout, this, &SnakeView::gameLoop);
}

SnakeView::~SnakeView() {
  delete m_buttonBoard;
  delete m_infoBoardView;
  delete m_boardView;
  delete m_gridLayout;
  delete m_gameModel;
  delete m_gameTimer;
}

void SnakeView::initView() {
  m_buttonBoard = new ButtonBoardView();
  m_infoBoardView = new InfoBoardView();
  m_boardView = new SnakeBoardView(10, 20);
  m_gridLayout = new QGridLayout();
  m_gameModel = new SnakeGameModel();
  m_gameTimer = new QTimer(this);

  m_gridLayout->addWidget(m_boardView, 0, 0, 2, 2);
  m_gridLayout->addWidget(m_infoBoardView, 0, 2, 1, 1);
  m_gridLayout->addWidget(m_buttonBoard, 1, 2, 1, 1);
  m_boardView->setGameModel(m_gameModel);
  m_infoBoardView->hideNextShape();
  setLayout(m_gridLayout);
  adjustSize();
  setFixedSize(size());
  setWindowTitle("Snake Game");
}

void SnakeView::keyPressEvent(QKeyEvent *e) {
  switch (e->key()) {
    case Qt::Key_P:
      m_gameModel->setGameControl(SnakeGameModel::PAUSE_GAME);
      break;
    case Qt::Key_Return:
      m_gameModel->setGameControl(SnakeGameModel::STAR_GAME);
      break;
    case Qt::Key_A:
      m_gameModel->setGameControl(SnakeGameModel::MOVE_LEFT);
      break;
    case Qt::Key_D:
      m_gameModel->setGameControl(SnakeGameModel::MOVE_RIGHT);
      break;
    case Qt::Key_W:
      m_gameModel->setGameControl(SnakeGameModel::MOVE_UP);
      break;
    case Qt::Key_S:
      m_gameModel->setGameControl(SnakeGameModel::MOVE_DOWN);
      break;
    case Qt::Key_G:
      m_gameModel->setGameControl(SnakeGameModel::STOP_GAME);
      break;
    case Qt::Key_Escape:
      m_gameModel->setGameControl(SnakeGameModel::EXIT_GAME);
      break;
  }
}

void SnakeView::gameLoop() {
  SnakeGameModel::GameState state = m_gameModel->getState();
  if (state == SnakeGameModel::GAMEOVER || state == SnakeGameModel::EXIT_STATE)
    gameOver();
  m_gameModel->stateMachine();
  m_infoBoardView->setScore(m_gameModel->getScore(),
                            m_gameModel->getBestScore());
  m_boardView->repaint();
}

void SnakeView::startGame() {
  if (m_gameModel->getState() == SnakeGameModel::GAMEOVER) m_gameModel->reset();
  m_gameModel->log();
  m_gameTimer->start(1);
  m_gameModel->setGameControl(SnakeGameModel::STAR_GAME);
  m_buttonBoard->getStartBtn()->setEnabled(false);
  m_buttonBoard->getStopBtn()->setEnabled(true);
  m_buttonBoard->getPauseBtn()->setEnabled(true);
  m_infoBoardView->repaint();
}

void SnakeView::pauseGame() {
  m_gameModel->setGameControl(SnakeGameModel::PAUSE_GAME);
  if (m_buttonBoard->getPauseBtn()->text() == "Pause") {
    m_buttonBoard->getPauseBtn()->setText("Resume");
  }

  else if (m_buttonBoard->getPauseBtn()->text() == "Resume") {
    m_buttonBoard->getPauseBtn()->setText("Pause");
    m_gameTimer->start(1);
  }
}

void SnakeView::stopGame() {
  m_buttonBoard->getStartBtn()->setEnabled(true);
  m_buttonBoard->getPauseBtn()->setEnabled(false);
  m_buttonBoard->getStopBtn()->setEnabled(false);
  m_gameModel->setGameControl(SnakeGameModel::STOP_GAME);
  m_infoBoardView->setScore(m_gameModel->getScore(),
                            m_gameModel->getBestScore());
  m_infoBoardView->repaint();
  m_boardView->repaint();
  m_gameModel->log();
}

void SnakeView::gameOver() {
  m_buttonBoard->getStartBtn()->setEnabled(true);
  m_buttonBoard->getPauseBtn()->setEnabled(false);
  m_buttonBoard->getStopBtn()->setEnabled(false);
  m_gameTimer->stop();
  m_boardView->repaint();
  m_infoBoardView->setScore(m_gameModel->getScore(),
                            m_gameModel->getBestScore());
  m_infoBoardView->repaint();
  m_gameModel->log();
}

}  // namespace s21

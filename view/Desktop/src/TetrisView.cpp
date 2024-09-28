//
// Created by roach on 18.09.2024.
//

#include "../inc/TetrisView.h"

namespace s21 {
TetrisView::TetrisView(QWidget *parent) : QWidget(parent) {
  initView();
  connect(m_buttonsField->getStartBtn(), &QPushButton::clicked, this,
          &TetrisView::startGame);
  connect(m_buttonsField->getPauseBtn(), &QPushButton::clicked, this,
          &TetrisView::pauseGame);
  connect(m_buttonsField->getStopBtn(), &QPushButton::clicked, this,
          &TetrisView::stopGame);
  connect(m_gameTimer, &QTimer::timeout, this, &TetrisView::gameLoop);
}

void TetrisView::initView() {
  m_gameTimer = new QTimer(this);
  m_gameModel = new TetrisGameModel();
  m_gridLayout = new QGridLayout();
  m_boardField = new BoardView(m_gameModel);
  m_infoField = new InfoBoardView();
  m_buttonsField = new ButtonBoardView();

  m_gridLayout->addWidget(m_boardField, 0, 0, 2, 2);
  m_gridLayout->addWidget(m_infoField, 0, 2, 1, 1);
  m_gridLayout->addWidget(m_buttonsField, 1, 2, 1, 1);
  setLayout(m_gridLayout);
  adjustSize();
  setFixedSize(size());
  setWindowTitle("BrickGame");
}

void TetrisView::startGame() {
  if (m_gameModel->getStateGame() == TetrisGameModel::GAMEOVER)
    m_gameModel->resetGame();
  m_gameTimer->start(16);
  m_gameModel->setGameControl(TetrisGameModel::STAR_GAME);
  m_buttonsField->getStartBtn()->setEnabled(false);
  m_buttonsField->getStopBtn()->setEnabled(true);
  m_buttonsField->getPauseBtn()->setEnabled(true);
  connect(m_buttonsField->getStopBtn(), &QPushButton::clicked, m_gameTimer,
          &QTimer::stop);
}

void TetrisView::pauseGame() {
  m_gameModel->setGameControl(TetrisGameModel::PAUSE_GAME);
  if (m_buttonsField->getPauseBtn()->text() == "Pause")
    m_buttonsField->getPauseBtn()->setText("Resume");
  else if (m_buttonsField->getPauseBtn()->text() == "Resume")
    m_buttonsField->getPauseBtn()->setText("Pause");
}

void TetrisView::stopGame() {
  m_buttonsField->getStartBtn()->setEnabled(true);
  m_buttonsField->getPauseBtn()->setEnabled(false);
  m_buttonsField->getStopBtn()->setEnabled(false);
  m_gameModel->resetGame();
}

void TetrisView::gameLoop() {
  TetrisGameModel::stateGame state = m_gameModel->getStateGame();

  m_infoField->getNextShapeView()->setNextShape(
      m_gameModel->getNextTetromino());
  if (state == TetrisGameModel::GAMEOVER ||
      state == TetrisGameModel::EXIT_STATE)
    stopGame();
  m_gameModel->stateMachine();
  m_boardField->repaint();
  m_infoField->setScore(m_gameModel->getScore(), m_gameModel->getBestScore());
  m_infoField->getNextShapeView()->repaint();
}

TetrisView::~TetrisView() noexcept {
  delete m_boardField;
  delete m_infoField;
  delete m_buttonsField;
  delete m_gridLayout;
  delete m_gameModel;
  delete m_gameTimer;
}

void TetrisView::keyPressEvent(QKeyEvent *e) {
  switch (e->key()) {
    case Qt::Key_P:
      m_gameModel->setGameControl(TetrisGameModel::PAUSE_GAME);
      break;
    case Qt::Key_Return:
      m_gameModel->setGameControl(TetrisGameModel::STAR_GAME);
      break;
    case Qt::Key_A:
      m_gameModel->setGameControl(TetrisGameModel::MOVE_LEFT);
      break;
    case Qt::Key_D:
      m_gameModel->setGameControl(TetrisGameModel::MOVE_RIGHT);
      break;
    case Qt::Key_R:
      m_gameModel->setGameControl(TetrisGameModel::MOVE_UP);
      break;
    case Qt::Key_S:
      m_gameModel->setGameControl(TetrisGameModel::MOVE_DOWN);
      break;
    case Qt::Key_G:
      m_gameModel->setGameControl(TetrisGameModel::STOP_GAME);
      break;
    case Qt::Key_Escape:
      m_gameModel->setGameControl(TetrisGameModel::EXIT_GAME);
      break;
  }
}

void TetrisView::keyReleaseEvent(QKeyEvent *e) {
  switch (e->key()) {
    case Qt::Key_P:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
    case Qt::Key_Return:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
    case Qt::Key_A:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
    case Qt::Key_D:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
    case Qt::Key_R:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
    case Qt::Key_S:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
    case Qt::Key_G:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
    case Qt::Key_Escape:
      m_gameModel->setGameControl(TetrisGameModel::NOSIG);
      break;
  }
}
}  // namespace s21
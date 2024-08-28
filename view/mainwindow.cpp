#include "inc/mainwindow.h"
#include <qmenubar.h>
// #include "../src/gameobj.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    initView();
    adjustSize();
    setFixedSize(size());
    connect(m_snakeGame, &QAction::triggered, m_infoField, &InfoBoardView::snakeMod);
    connect(m_tetrisGame, &QAction::triggered, m_infoField, &InfoBoardView::tetrisMod);
    connect(m_buttonsField->getStartBtn(), &QPushButton::clicked, this, &MainWindow::gameLoop);
}



void MainWindow::initView() {
    gameModel = new GameModel();
    m_infoField = new InfoBoardView();
    m_boardField = new BoardView(*gameModel->getBoardModel());
    m_gridLayout = new QGridLayout();
    m_buttonsField = new ButtonBoardView();
    m_centralWidget = new QWidget();

    m_menuBar = new QMenuBar(this);

    setMenuBar(m_menuBar);
    m_gameMenu = m_menuBar->addMenu("Games");
    m_snakeGame = m_gameMenu->addAction("Snake");
    m_tetrisGame = m_gameMenu->addAction("Tetris");

    m_menuBar->addMenu(m_gameMenu);
    m_gridLayout->addWidget(m_boardField, 0, 0, 2, 2);
    m_gridLayout->addWidget(m_infoField, 0, 2, 1, 1);
    m_gridLayout->addWidget(m_buttonsField, 1, 2, 1, 1);
    m_centralWidget->setLayout(m_gridLayout);

    setCentralWidget(m_centralWidget);
    setWindowTitle("BrickGame");
}

void MainWindow::gameLoop() {
    bool breakFlag = true;
    while (breakFlag){
        GameModel::stateGame state = gameModel->getStateGame();
        if (state == GameModel::GAMEOVER || state == GameModel::EXIT_STATE)
            breakFlag = false;
        gameModel->stateMachine();
        qDebug() << gameModel->getStateGame() << gameModel->getGameControl();
    }
}

MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    switch(e->key())
    {
        case Qt::Key_Return:
            gameModel->setGameControl(GameModel::STAR_PAUSE_GAME);
            qDebug() << "Pressed Enter. GameControl: " << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_A:
            gameModel->setGameControl(GameModel::MOVE_LEFT);
            qDebug() << "Pressed Left. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_D:
            gameModel->setGameControl(GameModel::MOVE_RIGHT);
            qDebug() << "Pressed Right. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_R:
            gameModel->setGameControl(GameModel::MOVE_UP);
            qDebug() << "Pressed Up. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_S:
            gameModel->setGameControl(GameModel::MOVE_DOWN);
            qDebug() << "Pressed Down. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_G:
            gameModel->setGameControl(GameModel::STOP_GAME);
            qDebug() << "Pressed Stop. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_Escape:
            gameModel->setGameControl(GameModel::EXIT_GAME);
            qDebug() << "Pressed Stop. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e) {



}





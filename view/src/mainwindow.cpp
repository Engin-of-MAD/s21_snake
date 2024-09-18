#include "../inc/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    m_tetris =  new TetrisView();
    m_startScreen = new StartScreenView();
    m_snake = new SnakeView();
    setCentralWidget(m_startScreen);
    setWindowTitle("Brick Game");
    setFixedSize(m_startScreen->size());
    connect(m_startScreen->getTetrisBtn(), &QPushButton::clicked, this, &MainWindow::openTetris);
    connect(m_startScreen->getSnakeBtn(), &QPushButton::clicked, this, &MainWindow::openSnake);
}

MainWindow::~MainWindow()
{
    delete m_tetris;
    delete m_startScreen;
}

void MainWindow::openTetris() {
    m_tetris->show();
    close();
}

void MainWindow::openSnake() {
    m_snake->show();
    close();
}

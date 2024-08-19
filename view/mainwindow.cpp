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
}


void MainWindow::initView() {

    m_infoField = new InfoBoardView();
    m_boardField = new BoardView();
    m_gridLayout = new QGridLayout();
    m_buttonsField =new ButtonBoardView();
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


MainWindow::~MainWindow()
{

}



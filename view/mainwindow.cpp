#include "inc/mainwindow.h"
// #include "../src/gameobj.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    initView();
    adjustSize();
    setFixedSize(size());

}


void MainWindow::initView() {

    m_infoField = new InfoBoardView();
    m_boardField = new BoardView();
    m_gridLayout = new QGridLayout();
    m_buttonsField =new ButtonBoardView();
    m_centralWidget = new QWidget();

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



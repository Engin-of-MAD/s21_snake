#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../view/boardview.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitGame()));

    // m_view = new QGraphicsView(this);
    // // init GameObj
    m_board = new BoardView(30,30, this);
    ui->graphicsView->resize(m_board->getSize());
    ui->graphicsView->setScene(m_board);
     m_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);


    // m_view->setScene(m_board);
    // setCentralWidget(m_view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitGame() {}
void MainWindow::pauseGame() {}
void MainWindow::resumeGame() {}
void MainWindow::handleGameOver() {}

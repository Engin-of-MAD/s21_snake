#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_board = new BoardView(10,20, this);
//    ui->graphicsView->resize(m_board->getSize());
    ui->graphicsView->setScene(m_board);
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    resize(m_board->getSize());
    ui->graphicsView->resize(m_board->getSize());
//    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    connect(ui->actionSizeField, SIGNAL(triggered()), this, SLOT(sizeFieldDialog()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitGame()));

    qDebug() << "Pointer: " << this << size();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sizeFieldDialog() {
    Dialog d(this, ui->graphicsView, m_board);
    d.exec();
}

void MainWindow::printResize(QResizeEvent* event) {
    qDebug() << "Pointer: " << this << size();
}
void MainWindow::exitGame() {
}
void MainWindow::pauseGame() {}
void MainWindow::resumeGame() {}


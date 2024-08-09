#include "mainwindow.h"
#include "gameobj.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    m_board = new BoardView(15,20, this);

    initView();


    GameObject g;

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitGame()));

    qDebug() << "Pointer: " << this << size();


}


void MainWindow::initView() {
    QSize size(m_board->getSize().width() , m_board->getSize().height());
    ui->setupUi(this);
    ui->graphicsView->setScene(m_board);
    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    resize(size);
    qDebug() << "Pointer: " << this << size;
}

void MainWindow::setFixSize() {
    QRect frameGeometry = this->frameGeometry();
    fixSize.rheight() = frameGeometry.height() - m_board->getSize().height();
    fixSize.rwidth() = frameGeometry.width() - m_board->getSize().width();
    qDebug() << "Fix fixSize: " << this << fixSize;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::printResize(QResizeEvent* event) {
    qDebug() << "Pointer: " << this << size();
}

void MainWindow::exitGame() {
    QApplication::exit();
}


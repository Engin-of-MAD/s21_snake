#include "inc/mainwindow.h"
#include "../src/gameobj.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    initView();
    GameObject g;
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exitGame()));
//    qDebug() << "Pointer: " << g.Table;
}


void MainWindow::initView() {

    ui->setupUi(this);
    m_view= new QGraphicsView;
    m_scene = new QGraphicsScene;
    QGraphicsItem* board = new BoardView();
    QGraphicsItem* infoField = new InfoBoardView(200);
    m_scene->addItem(board);
    m_scene->addItem(infoField);
    m_view->setScene(m_scene);
    m_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setCentralWidget(m_view);

    setWindowTitle("BrickGame");

    qDebug() << "Pointer: " << this << size();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitGame() {
    QApplication::exit();
}


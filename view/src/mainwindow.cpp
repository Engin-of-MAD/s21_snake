#include "../inc/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    gameTimer = new QTimer(this);
    initView();
    adjustSize();
    setFixedSize(size());
    setFocusPolicy(Qt::StrongFocus);
    connect(m_buttonsField->getStartBtn(), &QPushButton::clicked, this, &MainWindow::startGame);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::gameLoop);
}

void MainWindow::initView() {
    gameModel = new GameModel();
    m_infoField = new InfoBoardView();
    m_boardField = new BoardView(gameModel);
    m_gridLayout = new QGridLayout();
    m_buttonsField = new ButtonBoardView();
    m_centralWidget = new QWidget();

    m_gridLayout->addWidget(m_boardField, 0, 0, 2, 2);
    m_gridLayout->addWidget(m_infoField, 0, 2, 1, 1);
    m_gridLayout->addWidget(m_buttonsField, 1, 2, 1, 1);
    m_centralWidget->setLayout(m_gridLayout);

    setCentralWidget(m_centralWidget);
    setWindowTitle("BrickGame");
}

void MainWindow::startGame() {
    gameTimer->start(16);
    gameModel->setGameControl(GameModel::STAR_PAUSE_GAME);
//    qDebug() << "State:" << gameModel->getStateGame() << ", Control:" << gameModel->getGameControl();
    connect(m_buttonsField->getStopBtn(), &QPushButton::clicked, gameTimer, &QTimer::stop);

}

void MainWindow::gameLoop() {
    QTimer timer(this);
    GameModel::stateGame state = gameModel->getStateGame();

    m_infoField->getNextShapeView()->setNextShape(gameModel->getNextTetromino());
    if (state == GameModel::GAMEOVER)
        close();
    // Обновляем состояние игры
    gameModel->stateMachine();
    m_boardField->repaint();
    m_infoField->setScore(gameModel->getScore(), gameModel->getBestScore());
    m_infoField->getNextShapeView()->repaint();
    // Логирование состояния игры и управления (опционально)
//    qDebug() << "State:" << state << ", Control:" << gameModel->getGameControl();
}

MainWindow::~MainWindow()
{
    delete m_boardField;
    delete m_infoField;
    delete m_buttonsField;
    delete m_gridLayout;
    delete m_centralWidget;
    delete gameModel;
    delete gameTimer;
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    switch(e->key())
    {
        case Qt::Key_Return:
            gameModel->setGameControl(GameModel::STAR_PAUSE_GAME);
//            qDebug() << "Pressed Enter. GameControl: " << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_A:
            gameModel->setGameControl(GameModel::MOVE_LEFT);
//            qDebug() << "Pressed Left. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_D:
            gameModel->setGameControl(GameModel::MOVE_RIGHT);
//            qDebug() << "Pressed Right. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_R:
            gameModel->setGameControl(GameModel::MOVE_UP);
//            qDebug() << "Pressed Up. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_S:
            gameModel->setGameControl(GameModel::MOVE_DOWN);
//            qDebug() << "Pressed Down. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_G:
            gameModel->setGameControl(GameModel::STOP_GAME);
//            qDebug() << "Pressed Stop. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
        case Qt::Key_Escape:
            gameModel->setGameControl(GameModel::EXIT_GAME);
//            qDebug() << "Pressed Stop. GameControl: "  << gameModel->getGameControl() << ", State game: " << gameModel->getStateGame();
            break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e) {
    switch(e->key())
    {
        case Qt::Key_Return:
            gameModel->setGameControl(GameModel::NOSIG);
            break;
        case Qt::Key_A:
            gameModel->setGameControl(GameModel::NOSIG);
            break;
        case Qt::Key_D:
            gameModel->setGameControl(GameModel::NOSIG);
            break;
        case Qt::Key_R:
            gameModel->setGameControl(GameModel::NOSIG);
            break;
        case Qt::Key_S:
            gameModel->setGameControl(GameModel::NOSIG);
            break;
        case Qt::Key_G:
            gameModel->setGameControl(GameModel::NOSIG);
            break;
        case Qt::Key_Escape:
            gameModel->setGameControl(GameModel::NOSIG);
            break;
    }
}







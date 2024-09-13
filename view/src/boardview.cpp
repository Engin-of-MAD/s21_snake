#include "../inc/boardview.h"

#include <QPair>
#include <utility>

const int sizeCell = 21;
const int sizeItem = sizeCell - 4;

BoardView::BoardView() : BoardView(10, 20) {}

BoardView::BoardView(int width, int height) : m_width(width), m_height(height), gameModel(nullptr) {
    setFixedSize(m_width * sizeCell, m_height * sizeCell);
}

BoardView::BoardView(GameModel* model)
: BoardView(model->getBoardModel().width()
, model->getBoardModel().height()) {gameModel = model;}

void BoardView::drawGrid(QPainter *painter) {
    QPen gridPen(Qt::lightGray);
    painter->setPen(gridPen);
    for (int i = 20; i < height() - 1; i += sizeCell) {
        painter->drawLine(1, i, width() - 2, i);
        for (int j = 20; j < width() - 1; j += sizeCell)
            painter->drawLine(j, 1, j, height() - 2);
    }
    border(painter);
}

void BoardView::border(QPainter *painter) {
    QPen border(Qt::black);
    painter->setPen(border);
    painter->drawRect(0, 0, width() - 1, height() - 1);
}

QRect BoardView::normalizeCords(int x, int y) {
    int x1 = x * sizeCell + 1;
    int y1 = y * sizeCell + 1;


    QRect pixel(x1, y1, sizeItem, sizeItem);
    return pixel;
}

void BoardView::drawPixel(QPainter *painter, int x, int y, bool isFillItem) {

    QBrush brush(Qt::green);
    QPen pixelPen(Qt::green);
    if (isFillItem) {
        brush.setColor(Qt::green);
        pixelPen.setColor(Qt::green);
    } else {
        brush.setColor(Qt::white);
        pixelPen.setColor(Qt::white);
    }
    painter->setBrush(brush);
    painter->setPen(pixelPen);
    painter->drawRect(normalizeCords(x, y));
}

void BoardView::drawBoardModel(QPainter *painter) {
    BoardModel gameBoard = gameModel->getBoardModel();
    BoardModel buffer(gameBoard.width(), gameBoard.height());
    Tetromino current = gameModel->getCurrentTetromino();
    Tetromino next = gameModel->getNextTetromino();

    for (int i = 0; i < current.getWidth(); i++) {
        for (int j = 0; j < current.getWidth(); j++) {
            if (current[i][j])
                buffer[current.getCordY() + i][current.getCordX() + j] = current[i][j];
        }
    }

    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            drawPixel(painter, j, i, gameBoard[i][j] + buffer[i][j] ? 1 : 0);
        }
    }
}

void BoardView::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter p;

    p.begin(this);
    border(&p);
    drawGrid(&p);
    drawBoardModel(&p);
    p.end();
}

void BoardView::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Enter:
            qDebug() << "Enter";
            break;
    }
}

BoardView::BoardView(const BoardView &other) {
    gameModel = other.gameModel;
    m_width = other.m_width;
    m_height = other.m_height;
}

NextShapeView::NextShapeView() : BoardView(5, 5) {}
void NextShapeView::setNextShape(Tetromino nextShape) {
    m_nextShape = std::move(nextShape);
}

void NextShapeView::centralShape(int ShapeField[5][5]) {
    m_nextShape.printInConsole();
    for (int i = 0; i < m_nextShape.getWidth(); ++i) {
        for (int j = 0; j < m_nextShape.getWidth(); ++j) {
            switch (m_nextShape.getName()) {
                case ShapesTypes::I :
                    ShapeField[i][j] = m_nextShape[i][j];
                    break;
                case ShapesTypes::O :
                    ShapeField[i + 1][j + 2] = m_nextShape[i][j];
                    break;
                case ShapesTypes::S :
                    ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                    break;
                case ShapesTypes::Z :
                    ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                    break;
                case ShapesTypes::L :
                    ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                    break;
                case ShapesTypes::J :
                    ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                    break;
                case ShapesTypes::T :
                    ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                    break;
            }
        }
    }
}

void NextShapeView::drawNextShape(QPainter* painter) {
    m_nextShape.printInConsole();
    if (ShapesTypes::I == m_nextShape.getName()
        || ShapesTypes::Z == m_nextShape.getName() ||
        ShapesTypes::S == m_nextShape.getName()) {
        m_nextShape.rotate();
    }
    int ShapeField[5][5] = {0};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            centralShape(ShapeField);
            drawPixel(painter, i, j, ShapeField[i][j]);
        }
    }
}

void NextShapeView::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e)
    QPainter painter;
    painter.begin(this);
    drawGrid(&painter);
    drawNextShape(&painter);
    painter.end();
}


InfoBoardView::InfoBoardView() {
    setFixedSize(200, 196);
    m_gridLayout = new QGridLayout();
    m_score = new QLabel("Score: ");
    m_bestScore = new QLabel("Best score: ");
    m_nextShapeLabel = new QLabel("Next Shape: ");

    m_lcdScore = new QLCDNumber();
    m_lcdBestScore = new QLCDNumber();
    m_nextShape = new NextShapeView();

    m_gridLayout->addWidget(m_score, 0, 0);
    m_gridLayout->addWidget(m_bestScore, 1, 0);
    m_gridLayout->addWidget(m_lcdScore, 0, 1);
    m_gridLayout->addWidget(m_lcdBestScore, 1, 1);
    m_gridLayout->addWidget(m_nextShapeLabel, 2, 0);
    m_gridLayout->addWidget(m_nextShape, 2, 1);


    setLayout(m_gridLayout);
}




void InfoBoardView::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter p;
    p.begin(this);
    p.drawRect(0, 0, width() - 1, height() - 1);
    p.end();
}

void InfoBoardView::setScore(int score, int bestScore) {
    if (score && bestScore) {
        m_lcdScore->display(score);
        m_lcdBestScore->display(bestScore);
    }
}

InfoBoardView::~InfoBoardView() {
    delete m_gridLayout;
    delete m_score;
    delete m_bestScore;
    delete m_nextShapeLabel;
    delete m_lcdScore;
    delete m_lcdBestScore;
    delete m_nextShape;
}


NextShapeView* InfoBoardView::getNextShapeView() {
    return m_nextShape;
}

ButtonBoardView::ButtonBoardView() {
    setFixedSize(200, 198);
    m_startBtn = new QPushButton("Start");
    m_pauseBtn = new QPushButton("Pause");
    m_stopBtn = new QPushButton("Stop");

    m_stopBtn->setEnabled(false);
    m_pauseBtn->setEnabled(false);
    m_lineLayout = new QVBoxLayout();
    m_lineLayout->addWidget(m_startBtn);
    m_lineLayout->addWidget(m_pauseBtn);
    m_lineLayout->addWidget(m_stopBtn);
    setLayout(m_lineLayout);

}

void ButtonBoardView::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e)
    QPainter p;
    p.begin(this);
    p.drawRect(0, 0, width() - 1, height() - 1);
    p.end();
}

QPushButton *ButtonBoardView::getStartBtn() { return m_startBtn; }
QPushButton *ButtonBoardView::getPauseBtn() { return m_pauseBtn; }
QPushButton *ButtonBoardView::getStopBtn() { return m_stopBtn; }

ButtonBoardView::~ButtonBoardView() {
    delete m_lineLayout;
    delete m_startBtn;
    delete m_pauseBtn;
    delete m_stopBtn;
}

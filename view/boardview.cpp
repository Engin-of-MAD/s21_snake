#include "inc/boardview.h"
#include <iostream>
#include <QPair>
const int sizeCell = 21;
const int sizeItem = sizeCell - 4;

BoardView::BoardView() : BoardView(10, 20) {}
BoardView::BoardView(int width, int height) : m_width(width), m_height(height)
    {setFixedSize(m_width * sizeCell, m_height * sizeCell);}
BoardView::BoardView(BoardModel &model)
        : BoardView(model.width(), model.height()) {gameBoard = &model;}

void BoardView::drawGrid(QPainter *painter)
{

    QPen gridPen(Qt::lightGray);
    painter->setPen(gridPen);
    for (int i = 20; i < height() - 1; i += sizeCell) {
        painter->drawLine(1, i, width() - 2, i);
        for (int j = 20; j < width() - 1; j += sizeCell)
            painter->drawLine(j, 1, j, height() - 2);
    }
    border(painter);
}

void BoardView::border(QPainter* painter) {
    QPen border(Qt::black);
    painter->setPen(border);
    painter->drawRect(0, 0, width() - 1, height() - 1);
}
QRect BoardView::normalizeCords(int x, int y) {
    int x1 = x * sizeCell + 1;
    int y1 = y * sizeCell + 1;


    QRect pixel(x1, y1, sizeItem , sizeItem) ;
    qDebug() << x << y;
    qDebug() << "(" << x1 << "," << y1 << ')' ;
    qDebug() << pixel.size();
    return pixel;
}

void BoardView::drawPixel(QPainter *painter, int x, int y, bool isFillItem) {

    QBrush brush(Qt::green);
    QPen pixelPen(Qt::green);
    if (isFillItem) {
        brush.setColor(Qt::green);
        pixelPen.setColor(Qt::green);
    }
    else {
        brush.setColor(Qt::white);
        pixelPen.setColor(Qt::white);
    }
    painter->setBrush(brush);
    painter->setPen(pixelPen);
    painter->drawRect(normalizeCords(x, y));
}

void BoardView::drawBoardModel(QPainter *painter) {
    for (int i = 0; i < m_height; ++i) {
        for (int j = 0, item = 0; j < m_width; ++j) {
            drawPixel(painter, j, i, (*gameBoard)[i][j]);
        }
    }
}

void BoardView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p;

    p.begin(this);
    border(&p);
    drawGrid(&p);
//    drawPixel(&p, 0, 0);
//    drawPixel(&p, 1, 1);
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


InfoBoardView::InfoBoardView()
{
    setFixedSize(200, 196);
    m_gridLayout = new QGridLayout();
    m_score = new QLabel("Score: ");
    m_bestScore = new QLabel("Best score: ");
    m_nextShapeLabel = new QLabel("Next Shape: ");

    m_lcdScore = new QLCDNumber();
    m_lcdBestScore = new QLCDNumber();
    m_nextShape = new BoardView(4, 4);


    m_gridLayout->addWidget(m_score, 0, 0);
    m_gridLayout->addWidget(m_bestScore, 1, 0);
    m_gridLayout->addWidget(m_lcdScore, 0, 1);
    m_gridLayout->addWidget(m_lcdBestScore, 1, 1);
    m_gridLayout->addWidget(m_nextShapeLabel, 2, 0);
    m_gridLayout->addWidget(m_nextShape, 2, 1);

    m_nextShape->hide();
    m_nextShapeLabel->hide();

    setLayout(m_gridLayout);
}

void InfoBoardView::snakeMod()
{
    m_nextShape->hide();
    m_nextShapeLabel->hide();
}

void InfoBoardView::tetrisMod()
{
    m_nextShape->show();
    m_nextShapeLabel->show();
}



void InfoBoardView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p;
    p.begin(this);
    p.drawRect(0, 0, width() - 1, height() - 1);
    p.end();
}

ButtonBoardView::ButtonBoardView()
{
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

void ButtonBoardView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p;
    p.begin(this);
    p.drawRect(0, 0, width() - 1, height() - 1);
    p.end();
}

QPushButton *ButtonBoardView::getStartBtn() { return m_startBtn; }
QPushButton *ButtonBoardView::getPauseBtn() { return m_pauseBtn; }
QPushButton *ButtonBoardView::getStopBtn() { return m_stopBtn; }



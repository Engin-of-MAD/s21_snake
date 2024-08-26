#include "inc/boardview.h"
#include "../src/gameModel.h"
const int sizeCell = 20;
const int sizeItem = sizeCell - 2;

BoardView::BoardView() : BoardView(10, 20) {}

BoardView::BoardView(int width, int height)
    {setFixedSize(width * sizeCell, height * sizeCell);}


void BoardView::drawGrid(QPainter *painter)
{
    QPen gridPen(Qt::lightGray);
    painter->setPen(gridPen);
    for (int i = 20; i < height() - 1; i += sizeCell) {
        painter->drawLine(1, i, width() - 2, i);
        for (int j = 20; j < width() - 1; j += sizeCell)
            painter->drawLine(j, 1, j, height() - 2);
    }
}

void BoardView::drawSnake(QPainter *painter)
{

}

void BoardView::drawShape(QPainter *painter)
{

}

void BoardView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p;
    QBrush brush(Qt::green);
    p.begin(this);
    p.drawRect(0, 0, width() - 1, height() - 1);
    drawGrid(&p);
    p.setBrush(brush);
    p.drawRect(1, 1, 18, 18);

    p.end();
}

void BoardView::setBoardModel(BoardModel* gameBoard) {
    this->gameBoard = gameBoard;
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


//
// Created by roach on 24.07.2024.
//


#include "inc/boardview.h"






BoardView::BoardView()
{
    m_sizeField = QRectF(0, 0, 200, 400);
}

BoardView::BoardView(int width, int height, int x0, int y0)
{
    m_sizeField = QRectF(x0, y0, width * sizeItemGrid, height * sizeItemGrid);
}



void BoardView::drawGrid(QPainter *painter)
{
    for (int i = 20; i < m_sizeField.height(); i +=  20) {
        painter->drawLine(0, i, m_sizeField.width(), i);
        for (int j = 0; j < m_sizeField.width(); j += sizeItemGrid) {
            painter->drawLine(j, 0, j,  m_sizeField.height());
        }
    }
}

void BoardView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::lightGray, 1, Qt::SolidLine);
    painter->setPen(pen);
    drawGrid(painter);
    painter->drawRect(m_sizeField);


}

QRectF BoardView::boundingRect() const
{
    return m_sizeField;
}



InfoBoardView::InfoBoardView() : BoardView(1, 1){}

InfoBoardView::InfoBoardView( int x0, int y0)
    : BoardView(10, 10, x0, y0){}





//
// Created by roach on 24.07.2024.
//


#include "boardview.h"
const int sizeSquare = 20;

BoardView::BoardView(int tile_x, int tile_y, QObject *parent): QGraphicsScene(parent) {
    max_bottom_right.rx() = tile_x * sizeSquare;
    max_bottom_right.ry() = tile_y * sizeSquare;
    setSceneRect(0,0, max_bottom_right.x(), max_bottom_right.y());
    addRect(0, 0, max_bottom_right.x(), max_bottom_right.y());
    setItemIndexMethod(QGraphicsScene::NoIndex);
    setBackground(tile_x, tile_y);
}

void BoardView::setBackground(int height, int width) {


    QPixmap bg(sizeSquare, sizeSquare);
    QPainter painter(&bg);
    QPen gridPen(Qt::gray);


    painter.setPen(gridPen);
    painter.setBrush(Qt::white);
    painter.setPen(gridPen);
    painter.drawRect(0, 0, sizeSquare, sizeSquare);
//    setBackgroundBrush(QBrush(Qt::white));
//    p.setBrush(Qt::white);
//    p.setPen(gridPen);
//    p.drawRect(0, 0, sizeSquare, sizeSquare);
//    setBackgroundBrush(QBrush(bg));
    this->setBackgroundBrush(QBrush(bg));

}

QSize BoardView::getSize() {
    QSize size(max_bottom_right.rx()+ 3, max_bottom_right.ry()  + 3);
    return size;
}

//
// Created by roach on 24.07.2024.
//


#include "boardview.h"
const int sizeSquare = 20;

BoardView::BoardView(int tile_x, int tile_y, QObject *parent): QGraphicsScene(parent) {
    sizeField.rx() = tile_x * sizeSquare;
    sizeField.ry() = tile_y * sizeSquare;
    setSceneRect(0, 0, sizeField.x(), sizeField.y());
    addRect(0, 0, sizeField.x(), sizeField.y());
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
    setBackgroundBrush(QBrush(bg));

}

QSize BoardView::getSize() {
    QSize size(sceneRect().width(), sceneRect().height());
    return size;
}

void BoardView::setHeight(int height) {
    sizeField.ry() = height * sizeSquare;
}

void BoardView::setWidth(int width) {
    sizeField.rx() = width * sizeSquare;
}

void BoardView::resize(int width, int height) {
    setWidth(width);
    setHeight(height);
    setSceneRect(0, 0, sizeField.x(), sizeField.y());
    addRect(0, 0, sizeField.x(), sizeField.y());
//    setItemIndexMethod(QGraphicsScene::NoIndex);
//    setBackground(width, height);
}

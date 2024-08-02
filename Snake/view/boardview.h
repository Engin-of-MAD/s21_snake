//
// Created by roach on 24.07.2024.
//

#ifndef BRICKGAME_BOARDVIEW_H
#define BRICKGAME_BOARDVIEW_H

#include <QGraphicsScene>
#include <QPainter>

class BoardView : public QGraphicsScene{
private:
    QPointF startPos;
    QPointF max_bottom_right;
public:
    BoardView(int tile_x, int tile_y, QObject *parent = nullptr);
    void setBackground(int height, int width);
    void setSnake();
    void setFood();

    QSize getSize();
    void delFood();
};


#endif //BRICKGAME_BOARDVIEW_H

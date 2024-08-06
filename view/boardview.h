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
    QPointF sizeField;
public:
    const int paddingY = 66;
    const int paddingX = 20;

    explicit BoardView(int tile_x, int tile_y, QObject *parent = nullptr);

    void setBackground(int height, int width);
    void setHeight(int height);
    void setWidth(int width);
    void setSnake();
    void setFood();

    QSize getSize();
    void resize(int width, int height);
    void delFood();
};


#endif //BRICKGAME_BOARDVIEW_H

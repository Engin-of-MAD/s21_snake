//
// Created by roach on 18.09.2024.
//

#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QWidget>
#include <QPainter>

#include "../../models/inc/gameModel.h"
#include "../../models/inc/SnakeModel.h"
class BoardView : public QWidget {
    Q_OBJECT
    GameModel* gameModel;
    int m_width;
    int m_height;
public:
    BoardView();
    explicit BoardView(int width, int height);
    explicit BoardView(GameModel* model);


protected:
    void border(QPainter* painter);
    void paintEvent(QPaintEvent* e) override;
    void drawGrid(QPainter* painter);
    void drawBoardModel(QPainter* painter);
    void drawPixel(QPainter* painter, int x, int y, bool isFillItem);
    QRect normalizeCords(int x, int y);

};


class NextShapeView : public BoardView{
    using ShapesTypes = Tetromino::ShapesTypes;
public:
    NextShapeView();
    Tetromino m_nextShape;
    void setNextShape(Tetromino nextShape);
    void centralShape(int ShapeField[5][5]);
    void drawNextShape(QPainter* painter);
    void paintEvent(QPaintEvent* e) override;
};


class SnakeBoardView : public BoardView {
    SnakeModel* gameModel;
    void setGameModel(SnakeModel* model);
public:
    SnakeBoardView();
    SnakeBoardView(int width, int height);
    void paintEvent(QPaintEvent* e) override;
};

#endif //BOARDVIEW_H
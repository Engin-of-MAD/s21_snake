//
// Created by roach on 24.07.2024.
//

#ifndef BRICKGAME_BOARDVIEW_H
#define BRICKGAME_BOARDVIEW_H

#include <QGraphicsItem>
#include <QPainter>

class BoardView : public QGraphicsItem{
    QRectF m_sizeField;
    const int sizeItemGrid = 20;
public:
    BoardView();
    explicit BoardView(int width, int height, int x0 = 0, int y0 = 0);
protected:
    void drawGrid(QPainter *painter);
    void paint(QPainter* painter
               , const QStyleOptionGraphicsItem* option
               , QWidget * widget = nullptr) override;
    QRectF boundingRect() const override;
};

class InfoBoardView : public BoardView {
public:
    InfoBoardView();
    InfoBoardView(int x0 = 0, int y0 = 0);
protected:
    // void drawGrid(QPainter *painter);
    // void paint(QPainter* painter
    //            , const QStyleOptionGraphicsItem* option
    //            , QWidget * widget = nullptr) override;
};

#endif //BRICKGAME_BOARDVIEW_H

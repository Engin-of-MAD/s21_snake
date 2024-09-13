//
// Created by roach on 24.07.2024.
//

#ifndef BRICKGAME_BOARDVIEW_H
#define BRICKGAME_BOARDVIEW_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QLCDNumber>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QKeyEvent>
#include "../../models/inc/gameModel.h"
class BoardView : public QWidget {
    Q_OBJECT
    GameModel* gameModel;
    int m_width;
    int m_height;
public:
    BoardView();
    BoardView(const BoardView& other);
    explicit BoardView(int width, int height);
    explicit BoardView(GameModel* model);


protected:
    void border(QPainter* painter);
    void paintEvent(QPaintEvent* e) override;
    void drawGrid(QPainter* painter);
    void drawBoardModel(QPainter* painter);
    void drawPixel(QPainter* painter, int x, int y, bool isFillItem);
    QRect normalizeCords(int x, int y);
    void keyPressEvent(QKeyEvent* event) override;
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
class InfoBoardView : public QWidget {
    Q_OBJECT
    QGridLayout* m_gridLayout;
    QLabel* m_score;
    QLabel* m_bestScore;
    QLabel* m_nextShapeLabel;
    QLCDNumber* m_lcdScore;
    QLCDNumber* m_lcdBestScore;
    NextShapeView* m_nextShape;
public:
    InfoBoardView();
    ~InfoBoardView() override;
    void setScore(int score, int bestScore);
    NextShapeView* getNextShapeView();
protected:
    void paintEvent(QPaintEvent* e) override;
};


class ButtonBoardView : public QWidget {
    Q_OBJECT
    QVBoxLayout* m_lineLayout;
    QPushButton* m_startBtn;
    QPushButton* m_pauseBtn;
    QPushButton* m_stopBtn;
public:
    ButtonBoardView();
    ~ButtonBoardView() override;
    QPushButton* getStartBtn();
    QPushButton* getPauseBtn();
    QPushButton* getStopBtn();
protected:
    void paintEvent(QPaintEvent* e) override;
};



#endif //BRICKGAME_BOARDVIEW_H

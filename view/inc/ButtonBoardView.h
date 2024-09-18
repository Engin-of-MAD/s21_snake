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
#include "BoardView.h"
#include "../../models/inc/gameModel.h"



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

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
#include "../../models/inc/TetrisGameModel.h"




namespace s21 {

    class ButtonBoardView : public QWidget {
    Q_OBJECT

        QVBoxLayout *m_lineLayout;
        QPushButton *m_startBtn;
        QPushButton *m_pauseBtn;
        QPushButton *m_stopBtn;
    public:
        ButtonBoardView();

        ~ButtonBoardView() override;

        QPushButton *getStartBtn();

        QPushButton *getPauseBtn();

        QPushButton *getStopBtn();

    protected:
        void paintEvent(QPaintEvent *e) override;
    };

}
#endif //BRICKGAME_BOARDVIEW_H

//
// Created by roach on 18.09.2024.
//

#ifndef TETRISVIEW_H
#define TETRISVIEW_H
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>

#include <QTimer>
#include "BoardView.h"
#include "ButtonBoardView.h"
#include "InfoBoardView.h"
#include "../../models/inc/TetrisGameModel.h"
namespace s21 {
    class TetrisView : public QWidget {
    Q_OBJECT

        BoardView *m_boardField;
        InfoBoardView *m_infoField;
        ButtonBoardView *m_buttonsField;
        QGridLayout *m_gridLayout;
        s21::TetrisGameModel *m_gameModel;
        QTimer *m_gameTimer;

        void initView();

    public:
        explicit TetrisView(QWidget *parent = nullptr);

        ~TetrisView() override;

    protected:
        void keyPressEvent(QKeyEvent *e) override;

        void keyReleaseEvent(QKeyEvent *e) override;

    protected slots:

        void gameLoop();

        void startGame();

        void pauseGame();

        void stopGame();
    };
}

#endif //TETRISVIEW_H

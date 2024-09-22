//
// Created by roach on 18.09.2024.
//

#ifndef SNAKEVIEW_H
#define SNAKEVIEW_H

#include "ButtonBoardView.h"
#include "InfoBoardView.h"
#include "BoardView.h"

#include <QWidget>
#include <QGridLayout>
#include <QTimer>
namespace s21 {
    class SnakeView : public QWidget {
    Q_OBJECT
        ButtonBoardView *m_buttonBoard{};
        InfoBoardView *m_infoBoardView{};
        SnakeBoardView *m_boardView{};
        QGridLayout *m_gridLayout{};
        SnakeGameModel *m_gameModel{};
        QTimer *m_gameTimer{};
        void initView();
    public:
        explicit SnakeView(QWidget *parent = nullptr);
        ~SnakeView() override;
    protected:
        void keyPressEvent(QKeyEvent *e) override;
        void keyReleaseEvent(QKeyEvent *e) override;
    protected slots:
        void gameLoop();
        void startGame();
        void pauseGame();
        void stopGame();
        void gameOver();
    };
}

#endif //SNAKEVIEW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StartScreenView.h"
#include "TetrisView.h"
#include "SnakeView.h"
namespace s21 {
    class MainWindow : public QMainWindow {
    Q_OBJECT
        StartScreenView *m_startScreen;
        TetrisView *m_tetris;
        SnakeView *m_snake;
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override;
    public slots:
        void openTetris();
        void openSnake();
    };
}
#endif // MAINWINDOW_H

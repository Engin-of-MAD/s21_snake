#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "../view/boardview.h"
#include "./ui_mainwindow.h"
#include "./dialog.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printResize(QResizeEvent* event);
    void setFixSize();
private:
    QSize fixSize;
    void initView();
    Ui::MainWindow* ui;
    BoardView* m_board;
private slots:
    void exitGame();
    void sizeFieldDialog();
    void pauseGame();
    void resumeGame();
};


#endif // MAINWINDOW_H

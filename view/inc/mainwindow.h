#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QMenuBar>
#include <QAction>
#include "boardview.h"
// #include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    BoardView* m_boardField;
    InfoBoardView* m_infoField;
    ButtonBoardView* m_buttonsField;
    QGridLayout* m_gridLayout;
    QWidget* m_centralWidget;
    QMenuBar* m_menuBar;
    QMenu* m_gameMenu;
    QAction* m_snakeGame;
    QAction* m_tetrisGame;
    void initView();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


};
#endif // MAINWINDOW_H

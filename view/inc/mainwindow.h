#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

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
    void initView();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


};
#endif // MAINWINDOW_H

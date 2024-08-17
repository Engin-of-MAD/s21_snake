#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "boardview.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setFixSize();
    QSize getFixSize() const;

private:
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    Ui::MainWindow* ui;
    void initView();

private slots:
    void exitGame();
};


#endif // MAINWINDOW_H

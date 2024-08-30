#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include <QMainWindow>
#include <QGridLayout>
#include <QMenuBar>
#include <QAction>
#include <QTimer>
#include "boardview.h"
#include "../../src/gameModel.h"

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
    GameModel* gameModel;
    QTimer* gameTimer;

    void initView();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
protected:
    void keyPressEvent(QKeyEvent* e) override;
//    void keyReleaseEvent(QKeyEvent* e) override;
protected slots:
    void gameLoop();
    void startGame();
};
#endif // MAINWINDOW_H

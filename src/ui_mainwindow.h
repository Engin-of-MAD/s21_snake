/********************************************************************************
** Form generated from reading UI file 'mainwindowmXVanu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWMXVANU_H
#define MAINWINDOWMXVANU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewGame;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionExit;
    QAction *actionClI;
    QAction *actionGUI;
    QAction *actionSnake;
    QAction *actionTetris;
    QAction *actionGame;
    QAction *actionAbout;
    QAction *actionSizeField;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuGame_mode;
    QMenu *menuChoose_game;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 800);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        actionNewGame = new QAction(MainWindow);
        actionNewGame->setObjectName(QString::fromUtf8("actionNewGame"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionClI = new QAction(MainWindow);
        actionClI->setObjectName(QString::fromUtf8("actionClI"));
        actionGUI = new QAction(MainWindow);
        actionGUI->setObjectName(QString::fromUtf8("actionGUI"));
        actionSnake = new QAction(MainWindow);
        actionSnake->setObjectName(QString::fromUtf8("actionSnake"));
        actionTetris = new QAction(MainWindow);
        actionTetris->setObjectName(QString::fromUtf8("actionTetris"));
        actionGame = new QAction(MainWindow);
        actionGame->setObjectName(QString::fromUtf8("actionGame"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSizeField = new QAction(MainWindow);
        actionSizeField->setObjectName(QString::fromUtf8("actionSizeField"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        menuGame_mode = new QMenu(menuGame);
        menuGame_mode->setObjectName(QString::fromUtf8("menuGame_mode"));
        menuChoose_game = new QMenu(menuGame);
        menuChoose_game->setObjectName(QString::fromUtf8("menuChoose_game"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuGame->addAction(actionNewGame);
        menuGame->addAction(actionPause);
        menuGame->addAction(actionStop);
        menuGame->addAction(actionSizeField);
        menuGame->addAction(menuChoose_game->menuAction());
        menuGame->addAction(menuGame_mode->menuAction());
        menuGame->addAction(actionExit);
        menuGame_mode->addAction(actionClI);
        menuGame_mode->addAction(actionGUI);
        menuChoose_game->addAction(actionSnake);
        menuChoose_game->addAction(actionTetris);
        menuHelp->addAction(actionGame);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNewGame->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
#if QT_CONFIG(shortcut)
        actionNewGame->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#if QT_CONFIG(shortcut)
        actionPause->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#if QT_CONFIG(shortcut)
        actionStop->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClI->setText(QCoreApplication::translate("MainWindow", "CLI", nullptr));
        actionGUI->setText(QCoreApplication::translate("MainWindow", "GUI", nullptr));
        actionSnake->setText(QCoreApplication::translate("MainWindow", "Snake", nullptr));
        actionTetris->setText(QCoreApplication::translate("MainWindow", "Tetris", nullptr));
        actionGame->setText(QCoreApplication::translate("MainWindow", "Game Help", nullptr));
#if QT_CONFIG(shortcut)
        actionGame->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionSizeField->setText(QCoreApplication::translate("MainWindow", "Size field", nullptr));
        menuGame->setTitle(QCoreApplication::translate("MainWindow", "Game", nullptr));
        menuGame_mode->setTitle(QCoreApplication::translate("MainWindow", "Game mode", nullptr));
        menuChoose_game->setTitle(QCoreApplication::translate("MainWindow", "Choose game", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWMXVANU_H

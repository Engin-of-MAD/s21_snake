//
// Created by roach on 18.09.2024.
//

#ifndef STARTSCREENVIEW_H
#define STARTSCREENVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
class StartScreenView : QWidget{
    Q_OBJECT
    QHBoxLayout* boxLayout;
    QLabel* label;
    QPushButton* snake;
    QPushButton* tetris;
public:
    explicit StartScreenView(QWidget* parent = nullptr);
    ~StartScreenView() override;
};


#endif //STARTSCREENVIEW_H

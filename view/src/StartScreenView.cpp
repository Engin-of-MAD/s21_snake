//
// Created by roach on 18.09.2024.
//

#include "StartScreenView.h"

StartScreenView::StartScreenView(QWidget *parent) : QWidget(parent){
    label = new QLabel("Brick Game");
    snake = new QPushButton("Snake");
    tetris = new QPushButton("Tetris");
    boxLayout = new QHBoxLayout();
    boxLayout->addWidget(label);
    boxLayout->addWidget(snake);
    boxLayout->addWidget(tetris);
    setLayout(boxLayout);
}

StartScreenView::~StartScreenView() {
    delete label;
    delete snake;
    delete tetris;
    delete boxLayout;
}

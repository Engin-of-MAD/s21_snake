//
// Created by roach on 18.09.2024.
//

#include "../inc/StartScreenView.h"
namespace s21 {
    StartScreenView::StartScreenView(QWidget *parent) : QWidget(parent) {
        m_snake = new QPushButton("Snake");
        m_tetris = new QPushButton("Tetris");
        m_boxLayout = new QVBoxLayout();
        m_boxLayout->addWidget(m_snake);
        m_boxLayout->addWidget(m_tetris);
        setLayout(m_boxLayout);
        setFixedSize(250, 100);
        setWindowFlags(windowFlags() & ~Qt::WindowFullscreenButtonHint);
    }

    StartScreenView::~StartScreenView() {
        delete m_snake;
        delete m_tetris;
        delete m_boxLayout;
    }

    QPushButton *StartScreenView::getTetrisBtn() { return m_tetris; }

    QPushButton *StartScreenView::getSnakeBtn() { return m_snake; }
}
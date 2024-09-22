//
// Created by roach on 18.09.2024.
//

#ifndef STARTSCREENVIEW_H
#define STARTSCREENVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
namespace s21 {
    class StartScreenView : public QWidget {
    Q_OBJECT

        QVBoxLayout *m_boxLayout;
        QPushButton *m_snake;
        QPushButton *m_tetris;
    public:
        explicit StartScreenView(QWidget *parent = nullptr);

        ~StartScreenView() override;

        QPushButton *getSnakeBtn();

        QPushButton *getTetrisBtn();
    };

}
#endif //STARTSCREENVIEW_H

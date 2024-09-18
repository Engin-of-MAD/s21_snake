//
// Created by roach on 18.09.2024.
//

#ifndef UNTITLED2_INFOBOARD_H
#define UNTITLED2_INFOBOARD_H
#include <QLCDNumber>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include "BoardView.h"
class InfoBoardView : public QWidget {
    Q_OBJECT
            QGridLayout* m_gridLayout;
    QLabel* m_score;
    QLabel* m_bestScore;
    QLabel* m_nextShapeLabel;
    QLCDNumber* m_lcdScore;
    QLCDNumber* m_lcdBestScore;
    NextShapeView* m_nextShape;
public:
    InfoBoardView();
    ~InfoBoardView() override;
    void setScore(int score, int bestScore);
    NextShapeView* getNextShapeView();
protected:
    void paintEvent(QPaintEvent* e) override;
};


#endif //UNTITLED2_INFOBOARD_H

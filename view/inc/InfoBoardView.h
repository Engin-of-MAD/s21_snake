//
// Created by roach on 18.09.2024.
//

#ifndef INFOBOARDVIEW_H
#define INFOBOARDVIEW_H
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




#endif //INFOBOARDVIEW_H

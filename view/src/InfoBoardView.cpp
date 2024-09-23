//
// Created by roach on 18.09.2024.
//

#include "../inc/InfoBoardView.h"
namespace s21 {

    InfoBoardView::InfoBoardView() {
        setFixedSize(200, 196);
        m_gridLayout = new QGridLayout();
        m_score = new QLabel("Score: ");
        m_bestScore = new QLabel("Best score: ");
        m_nextShapeLabel = new QLabel("Next Shape: ");

        m_lcdScore = new QLCDNumber();
        m_lcdBestScore = new QLCDNumber();
        m_nextShape = new NextShapeView();

        m_gridLayout->addWidget(m_score, 0, 0);
        m_gridLayout->addWidget(m_bestScore, 1, 0);
        m_gridLayout->addWidget(m_lcdScore, 0, 1);
        m_gridLayout->addWidget(m_lcdBestScore, 1, 1);
        m_gridLayout->addWidget(m_nextShapeLabel, 2, 0);
        m_gridLayout->addWidget(m_nextShape, 2, 1);
        setLayout(m_gridLayout);
    }


    void InfoBoardView::paintEvent(QPaintEvent *e) {
        Q_UNUSED(e);
        QPainter p;
        p.begin(this);
        p.drawRect(0, 0, width() - 1, height() - 1);
        p.end();
    }

    void InfoBoardView::setScore(int score, int bestScore) {
        m_lcdScore->display(score);
        m_lcdBestScore->display(bestScore);
    }

    InfoBoardView::~InfoBoardView() {
        delete m_gridLayout;
        delete m_score;
        delete m_bestScore;
        delete m_nextShapeLabel;
        delete m_lcdScore;
        delete m_lcdBestScore;
        delete m_nextShape;
    }


    NextShapeView *InfoBoardView::getNextShapeView() {
        return m_nextShape;
    }

    void InfoBoardView::hideNextShape() {
        m_nextShapeLabel->hide();
        m_nextShape->hide();
    }
}
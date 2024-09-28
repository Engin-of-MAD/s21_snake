#include "../inc/ButtonBoardView.h"
namespace s21 {
ButtonBoardView::ButtonBoardView() {
  setFixedSize(200, 198);
  m_startBtn = new QPushButton("Start");
  m_pauseBtn = new QPushButton("Pause");
  m_stopBtn = new QPushButton("Stop");

  m_stopBtn->setEnabled(false);
  m_pauseBtn->setEnabled(false);
  m_lineLayout = new QVBoxLayout();
  m_lineLayout->addWidget(m_startBtn);
  m_lineLayout->addWidget(m_pauseBtn);
  m_lineLayout->addWidget(m_stopBtn);
  setLayout(m_lineLayout);
}

void ButtonBoardView::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e)
  QPainter p;
  p.begin(this);
  p.drawRect(0, 0, width() - 1, height() - 1);
  p.end();
}

QPushButton *ButtonBoardView::getStartBtn() { return m_startBtn; }

QPushButton *ButtonBoardView::getPauseBtn() { return m_pauseBtn; }

QPushButton *ButtonBoardView::getStopBtn() { return m_stopBtn; }

ButtonBoardView::~ButtonBoardView() {
  delete m_lineLayout;
  delete m_startBtn;
  delete m_pauseBtn;
  delete m_stopBtn;
}

}  // namespace s21
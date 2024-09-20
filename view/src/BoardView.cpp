//
// Created by roach on 18.09.2024.
//
const int sizeCell = 21;
const int sizeItem = sizeCell - 4;
#include "../inc/BoardView.h"
namespace s21 {
    BoardView::BoardView() : BoardView(1, 1) {}

    BoardView::BoardView(int width, int height) : m_width(width), m_height(height), gameModel(nullptr) {
        setFixedSize(m_width * sizeCell, m_height * sizeCell);
    }

    BoardView::BoardView(TetrisGameModel *model)
            : BoardView(model->getBoardModel().getWidth(), model->getBoardModel().getHeight()) { gameModel = model; }

    void BoardView::drawGrid(QPainter *painter) {
        QPen gridPen(Qt::lightGray);
        painter->setPen(gridPen);
        for (int i = 20; i < height() - 1; i += sizeCell) {
            painter->drawLine(1, i, width() - 2, i);
            for (int j = 20; j < width() - 1; j += sizeCell)
                painter->drawLine(j, 1, j, height() - 2);
        }
        border(painter);
    }

    void BoardView::border(QPainter *painter) {
        QPen border(Qt::black);
        painter->setPen(border);
        painter->drawRect(0, 0, width() - 1, height() - 1);
    }

    QRect BoardView::normalizeCords(int x, int y) {
        int x1 = x * sizeCell + 1;
        int y1 = y * sizeCell + 1;
        QRect pixel(x1, y1, sizeItem, sizeItem);
        return pixel;
    }

    void BoardView::drawPixel(QPainter *painter, int x, int y, bool isFillItem) {

        QBrush brush(Qt::green);
        QPen pixelPen(Qt::green);
        if (isFillItem) {
            brush.setColor(Qt::green);
            pixelPen.setColor(Qt::green);
        } else {
            brush.setColor(Qt::white);
            pixelPen.setColor(Qt::white);
        }
        painter->setBrush(brush);
        painter->setPen(pixelPen);
        painter->drawRect(normalizeCords(x, y));
    }

    void BoardView::drawBoardModel(QPainter *painter) {
        TetrisBoardModel gameBoard = gameModel->getBoardModel();
        TetrisBoardModel buffer(gameBoard.getWidth(), gameBoard.getHeight());
        Tetromino current = gameModel->getCurrentTetromino();
        Tetromino next = gameModel->getNextTetromino();

        for (int i = 0; i < current.getWidth(); i++) {
            for (int j = 0; j < current.getWidth(); j++) {
                if (current[i][j])
                    buffer[current.getCordY() + i][current.getCordX() + j] = current[i][j];
            }
        }

        for (int i = 0; i < m_height; ++i) {
            for (int j = 0; j < m_width; ++j) {
                drawPixel(painter, j, i, gameBoard[i][j] + buffer[i][j] ? 1 : 0);
            }
        }
    }

    void BoardView::paintEvent(QPaintEvent *e) {
        Q_UNUSED(e);
        QPainter p;
        p.begin(this);
        border(&p);
        drawGrid(&p);
        drawBoardModel(&p);
        p.end();
    }


    NextShapeView::NextShapeView() : BoardView(5, 5) {}

    void NextShapeView::setNextShape(Tetromino nextShape) {
        m_nextShape = std::move(nextShape);
    }

    void NextShapeView::centralShape(int ShapeField[5][5]) {
        for (int i = 0; i < m_nextShape.getWidth(); ++i) {
            for (int j = 0; j < m_nextShape.getWidth(); ++j) {
                switch (m_nextShape.getName()) {
                    case ShapesTypes::I :
                        ShapeField[i][j] = m_nextShape[i][j];
                        break;
                    case ShapesTypes::O :
                        ShapeField[i + 1][j + 2] = m_nextShape[i][j];
                        break;
                    case ShapesTypes::S :
                        ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                        break;
                    case ShapesTypes::Z :
                        ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                        break;
                    case ShapesTypes::L :
                        ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                        break;
                    case ShapesTypes::J :
                        ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                        break;
                    case ShapesTypes::T :
                        ShapeField[i + 1][j + 1] = m_nextShape[i][j];
                        break;
                }
            }
        }
    }

    void NextShapeView::drawNextShape(QPainter *painter) {
        if (ShapesTypes::I == m_nextShape.getName()
            || ShapesTypes::Z == m_nextShape.getName() ||
            ShapesTypes::S == m_nextShape.getName()) {
            m_nextShape.rotate();
        }
        int ShapeField[5][5] = {0};
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                centralShape(ShapeField);
                drawPixel(painter, i, j, ShapeField[i][j]);
            }
        }
    }

    void NextShapeView::paintEvent(QPaintEvent *e) {
        Q_UNUSED(e)
        QPainter painter;
        painter.begin(this);
        drawGrid(&painter);
        drawNextShape(&painter);
        painter.end();
    }

    SnakeBoardView::SnakeBoardView() : BoardView() {}

    SnakeBoardView::SnakeBoardView(int width, int height)
            : BoardView(width, height) {}

    void SnakeBoardView::paintEvent(QPaintEvent *e) {
        QPainter painter;
        painter.begin(this);
        drawGrid(&painter);
        painter.end();
    }

    void SnakeBoardView::setGameModel(SnakeGameModel *model) {
        gameModel = model;
    }

    void SnakeBoardView::drawBoardModel(QPainter *painter) {
        BaseBoardModel board = gameModel->getGameBoard();
        SnakeModel snake = gameModel->getSnakeModel();
        for (int i = 0; i < board.getHeight(); ++i) {
            for (int j = 0; j < board.getWidth(); ++j) {
                drawPixel(painter ,j, i, 0);
            }
        }
    }
}
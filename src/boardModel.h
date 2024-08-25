//
// Created by roach on 23.08.2024.
//
#include "shapeModel.h"

#ifndef BOARDMODEL_H
#define BOARDMODEL_H
class GameBoard {
    int** m_gameField;
    int m_width, m_height;
public:
    GameBoard();
    explicit GameBoard(int width = 1, int height = 1);
    GameBoard(GameBoard& other);
    ~GameBoard();
    int width() const;
    int height() const;
    void setShapeOnBoard(Shapes* shape);
    int* operator [](int index);
    int& operator ()(int row, int col);
    const int& operator ()(int row, int col) const;
};
#endif //BOARDMODEL_H

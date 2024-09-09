//
// Created by roach on 23.08.2024.
//


#ifndef BOARDMODEL_H
#define BOARDMODEL_H
#include "TetrominoFactory.h"
#include <iostream>

class BoardModel {
    int** m_gameField;
    int m_width, m_height;
public:
    BoardModel();
    explicit BoardModel(int width = 1, int height = 1);
    BoardModel(BoardModel& other);
    ~BoardModel();
    int width() const;
    int height() const;
    void printInConsole() const;
    void setShapeOnBoard(Tetromino& shape);
    bool isRowFull(int rowI);
    void shiftDownRows(int rowI);
    void clearRow(int rowI);
    int* operator [](int index);
    int& operator ()(int row, int col);
    void testData1();
};
#endif //BOARDMODEL_H

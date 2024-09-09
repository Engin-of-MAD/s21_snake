//
// Created by roach on 23.08.2024.
//

#include "../inc/boardModel.h"

BoardModel::BoardModel() : BoardModel(10, 20){}
BoardModel::BoardModel(int width, int height)
: m_width(width)
, m_height(height)
{
    m_gameField = new int*[m_height];

    for (int i = 0; i < m_height; ++i)
        m_gameField[i] = new int[m_width];

    for (int i = 0; i < m_height; ++i)
        for (int j = 0; j < m_width; ++j)
            m_gameField[i][j] = 0;
}

BoardModel::BoardModel(BoardModel &other): BoardModel(other.m_width, other.m_height)
{
    for (int i = 0; i < other.m_height; ++i) {
        for (int j = 0; j < other.m_width; ++j) {
            m_gameField[i][j] = other.m_gameField[i][j];
        }
    }
}
BoardModel::~BoardModel() {
    if (m_gameField) {
        for (int i = 0; i < m_height; ++i) {
            delete[] m_gameField[i];
        }
        delete[] m_gameField;
        m_gameField = nullptr;
    }
}
int BoardModel::width() const { return m_width; }
int BoardModel::height() const { return m_height; }
int *BoardModel::operator[](int index) {
    return m_gameField[index];
}

void BoardModel::setShapeOnBoard(Tetromino& shape) {
    for (int i = 0; i < shape.getWidth(); ++i) {
        for (int j = 0; j < shape.getWidth(); ++j) {
            if (shape[i][j])
                m_gameField[shape.getCordY() + i][shape.getCordX() + j] = shape[i][j];
        }
    }
}



void BoardModel::printInConsole() const {
    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            std::cout << m_gameField[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int &BoardModel::operator()(int row, int col) {
    if ((m_height < row || row > m_height) && (m_width < col || m_width > col))
        throw std::out_of_range("Index out of range");
    return m_gameField[row][col];
}

void BoardModel::testData1() {
    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            m_gameField[i][j] = 1;
        }
    }
}

bool BoardModel::isRowFull(int rowI) {
    int sum = 0;
    for (int colI = 0; colI < m_width; ++colI)
        sum += m_gameField[rowI][colI];
    if (sum == m_width) {
        return true;
    }
    return false;
}

void BoardModel::shiftDownRows(int rowI) {
    std::cout << rowI << std::endl;
    for (int shiftRowI = rowI; shiftRowI >= 1 ; --shiftRowI) {
        for (int colI = 0; colI < m_width; ++colI) {
            m_gameField[shiftRowI][colI] = m_gameField[shiftRowI - 1][colI];
        }
    }
}

void BoardModel::clearRow(int rowI) {
    for (int colI = 0; colI < m_width; ++colI) {
        m_gameField[rowI][colI] = 0;
    }
}

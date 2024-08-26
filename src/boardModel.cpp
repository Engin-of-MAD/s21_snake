//
// Created by roach on 23.08.2024.
//

#include "boardModel.h"

GameBoard::GameBoard() : GameBoard(10, 20){}
GameBoard::GameBoard(int width, int height)
{
    m_gameField = new int*[height];

    for (int i = 0; i < height; ++i) {
        m_gameField[i] = new int[width];
    }
}
GameBoard::GameBoard(GameBoard &other): GameBoard(other.m_width, other.m_height)
{
    for (int i = 0; i < other.m_height; ++i) {
        for (int j = 0; j < other.m_width; ++j) {
            m_gameField[i][j] = other.m_gameField[i][j];
        }
    }
}
GameBoard::~GameBoard() {
    if (m_gameField) {
        for (int i = 0; i < m_height; ++i) {
            delete[] m_gameField[i];
        }
        delete[] m_gameField;
        m_gameField = nullptr;
    }
}
int GameBoard::width() const { return m_width; }
int GameBoard::height() const { return m_height; }
int *GameBoard::operator[](int index) {
    return m_gameField[index];
}

void GameBoard::setShapeOnBoard(Shape& shape) {
    for (int i = 0; i < shape.width(); ++i) {
        for (int j = 0; j < shape.width(); ++j) {
            if (shape[i][j])
                m_gameField[shape.cordY() + i][shape.cordX() + j] = shape[i][j];
        }
    }
}

void sumRows(){

}
void GameBoard::clearFullRows(int sum) {
    int r = 0;
    for (r = 0; r >= 1; --r) {
        for (int j = 0; j < m_width; ++j) {
            m_gameField[r][j] = m_gameField[r - 1][j];
        }
    }
    for (int c = 0; c < m_width; ++c) {
        m_gameField[r][c] = 0;
    }
}


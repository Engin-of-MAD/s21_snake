#include "gameobj.h"

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



Shape::Shape(int width, char name) : m_width(width)
    , m_name(name)
    , cordX(0)
    , cordY(0)
{
    m_array = new int*[m_width];
    for (int i = 0; i < m_width; ++i) {
        m_array[i] = new int[m_width];
    }
}

Shape::Shape(Shape& other) {

}

Shape::~Shape()
{
    if (m_array) {
        for (int i = 0; i < m_width; ++i) {
            delete[] m_array[i];
        }
        delete[] m_array;
        m_array = nullptr;
    }
}

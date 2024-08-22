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
int *GameBoard::operator[](int index) {
    return m_gameField[index];
}

int &GameBoard::operator()(int row, int col) {
    if ((row < 0 or col < 0) or (row >= m_width or col >= m_width)) {
        throw std::out_of_range("Index out of range");
    }
    return m_gameField[row][col];
}

Shapes::Shapes(char name): m_cordX(0), m_cordY(0)
{
    switch (m_name) {
    case 'S':
        shapeS();
        break;
    case 'Z':
        shapeZ();
        break;
    case 'T':
        shapeT();
        break;
    case 'L':
        shapeL();
        break;
    case 'J':
        shapeJ();
        break;
    case 'O':
        shapeO();
        break;
    case 'I':
        shapeI();
        break;
    default:
        break;
    }
}

Shapes::Shapes(Shapes& other)
    : m_width(other.m_width), m_cordX(other.m_cordX)
    , m_cordY(other.m_cordY) ,m_name(other.m_name)
{
    createShape(other.m_width);
    fillShape(other.m_array);
}

Shapes::~Shapes()
{
    if (m_array) {
        for (int i = 0; i < m_width; ++i) {
            delete[] m_array[i];
        }
        delete[] m_array;
    }
}

void Shapes::createShape(int width)
{
    m_array = new int*[width];
    if (m_array) {
        for (int i = 0; i < width; ++i) {
            m_array[i] = new int[width];
        }
    }
}

void Shapes::fillShape(int** shape)
{
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_width; ++j) {
            m_array[i][j] = shape[i][j];
        }
    }
}

void Shapes::shapeS() {
    m_width = 3;
    m_name = 'S';
    int newShape[3][3] = {{0, 1, 1}, {1, 1, 0}, {0, 0, 0}};
    createShape(m_width);
    fillShape(reinterpret_cast<int**>(newShape));

}

void Shapes::shapeZ()
{
    m_width = 3;
    m_name = 'Z';
    int newShape[3][3] = {{1, 1, 0}, {0, 1, 1}, {0, 0, 0}};
    createShape(m_width);
    fillShape(reinterpret_cast<int**>(newShape));

}

void Shapes::shapeT()
{
    m_width = 3;
    m_name = 'T';
    int newShape[3][3] = {{0, 1, 0}, {1, 1, 1}, {0, 0, 0}};
    createShape(m_width);
    fillShape(reinterpret_cast<int**>(newShape));
}

void Shapes::shapeL()
{
    m_width = 3;
    m_name = 'L';
    int newShape[3][3] = {{0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    createShape(m_width);
    fillShape(reinterpret_cast<int**>(newShape));
}

void Shapes::shapeJ()
{
    m_width = 3;
    m_name = 'J';
    int newShape[3][3] = {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}};
    createShape(m_width);
    fillShape(reinterpret_cast<int**>(newShape));
}

void Shapes::shapeO()
{
    m_width = 2;
    m_name = 'O';
    int newShape[2][2] = {{1, 1}, {1, 1}};
    createShape(m_width);
    fillShape(reinterpret_cast<int**>(newShape));
}

void Shapes::shapeI()
{
    m_width = 4;
    m_name = 'I';
    int newShape[4][4] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    createShape(m_width);
    fillShape(reinterpret_cast<int**>(newShape));
}

char Shapes::name() const {return m_name;}
int Shapes::width() const{return m_width;}
int Shapes::cordX() const{return m_cordX;}
int Shapes::cordY() const {return m_cordY;}
int *Shapes::operator[](int index) { return  m_array[index];}
int &Shapes::operator()(int row, int col) {
    if ((row < 0 or col < 0) or (row >= m_width or col >= m_width)) {
        throw std::out_of_range("Index out of range");
    }
    return m_array[row][col];

}


bool GameObject::genRandomShape()
{

}

void GameObject::writeToBoard()
{
    for (int i = 0; i < currShape->width(); ++i) {
        for (int j = 0; j < currShape->width(); ++j) {
            if (currShape[i][j]) {
                m_gBoard[currShape->cordY() + i] [currShape->cordX() + j] = currShape[i][j];
            }
        }
    }
}

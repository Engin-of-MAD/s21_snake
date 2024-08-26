//
// Created by roach on 23.08.2024.
//

#include "shapeModel.h"

Shape::Shape() {
    const char shapes[7] = {'S', 'Z', 'T', 'L', 'J', 'O', 'I'};
    char randomShape = shapes[rand() % 7];
    switch (randomShape) {
        case 'S':
            *this = S();
            break;
        case 'Z':
            *this = Z();
            break;
        case 'T':
            *this = T();
            break;
        case 'L':
            *this = L();
            break;
        case 'J':
            *this = J();
            break;
        case 'O':
            *this = O();
            break;
        case 'I':
            *this = I();
            break;
    }
}

Shape::Shape(Shape &other)
        : m_width(other.m_width) , m_cordX(other.m_cordX)
        , m_cordY(other.m_cordY), m_name(other.m_name)
{
    delMatrix();
    m_array =  createMatrix(m_width);
    fillMatrix(m_array, other.m_array, m_width);
}

Shape::Shape(char name, int (*arr)[2], int width, int cordX, int cordY)
: m_name(name), m_width(width)
, m_cordX(cordX), m_cordY(cordY){
    m_array = createMatrix(m_width);
    fillMatrix(m_array, arr);
}
Shape::Shape(char name, int (*arr)[3], int width, int cordX, int cordY)
: m_name(name), m_width(width)
, m_cordX(cordX), m_cordY(cordY){
    m_array = createMatrix(m_width);
    fillMatrix(m_array, arr);
}

Shape::Shape(char name, int (*arr)[4], int width, int cordX, int cordY)
: m_name(name), m_width(width)
, m_cordX(cordX), m_cordY(cordY){
    m_array = createMatrix(m_width);
    fillMatrix(m_array, arr);
}
Shape::~Shape() {
    delMatrix();
}

Shape Shape::S() {
    int S[3][3] = {{0, 1, 1},{1, 1, 0}, {0, 0, 0}};
    Shape shape('S',S, 3);
    return shape;
}
Shape Shape::Z() {
    int Z[3][3] = {{1, 1, 0}, {0, 1, 1},{0, 0, 0}};
    Shape shape('Z',Z, 3);
    return shape;
}
Shape Shape::T() {
    int** arr = createMatrix(3);
    int T[3][3] = {{0, 1, 0},{1, 1, 1}, {0, 0, 0}};
    fillMatrix(arr, T);
    Shape shape('T',T, 3);
    return shape;
}
Shape Shape::L() {
    int L[3][3] = {{0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Shape shape('L', L, 3);
    return shape;
}
Shape Shape::J() {
    int J[3][3] = {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}};
    Shape shape('J',J, 3, 0, 0);
    return shape;
}
Shape Shape::O() {
    int O[2][2] ={{1, 1}, {1, 1}};
    Shape shape('O',O, 2, 0, 0);
    return shape;
}
Shape Shape::I() {

    int I[4][4] ={{0, 0, 0, 0}, {1, 1, 1, 1},
                    {0, 0, 0, 0}, {0, 0, 0, 0}};
    Shape shape('I',I, 4, 0, 0);
    return shape;
}

void Shape::increaseCordX() {++m_cordX;}
void Shape::decreaseCordX() {--m_cordX;}
void Shape::increaseCordY() {++m_cordY;}
void Shape::decreaseCordY() {--m_cordY;}

char Shape::name() const {return m_name;}
int Shape::width() const{return m_width;}
int Shape::cordX() const{return m_cordX;}
int Shape::cordY() const {return m_cordY;}
int* Shape::operator[](int index) {return m_array[index];}



void Shape::rotateShape() {
    Shape tmpShape(*this);
    for (int i = 0; i < tmpShape.m_width; ++i) {
        for (int j = 0, k = tmpShape.m_width - 1; j < tmpShape.m_width; ++j, k--)
            m_array[i][j] = tmpShape[k][i];
    }
}

int& Shape::operator()(int row, int col) {
    if ((row < 0 or col < 0) or (row >= m_width or col >= m_width)) {
        throw std::out_of_range("Index out of range");
    }
    return m_array[row][col];
}

void Shape::delMatrix() {
    if (m_array) {
        for (int i = 0; i < m_width; ++i) {
            delete[] m_array[i];
        }
        delete[] m_array;
    }
}

int** Shape::createMatrix(int width) {
        int** matrix = new int* [width];
        for (int i = 0; i < width; ++i) {
            matrix[i] = new int [width];
        }
    return matrix;
}



Shape& Shape::operator=(const Shape &other) {
    if (this != &other) {
        this->m_width = other.m_width;
        this->m_cordX = other.m_cordX;
        this->m_cordY = other.m_cordY;
        delMatrix();
        m_array =  createMatrix(m_width);
        fillMatrix(m_array,other.m_array, m_width);
    }
    return *this;
}
void Shape::fillMatrix(int** matrix, int** other, const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            matrix[i][j] = other[i][j];
    }
}

void Shape::fillMatrix(int **matrix, int (*other)[3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            matrix[i][j] = other[i][j];
    }
}

void Shape::fillMatrix(int **matrix, int (*other)[2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            matrix[i][j] = other[i][j];
    }
}

void Shape::fillMatrix(int **matrix, int (*other)[4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            matrix[i][j] = other[i][j];
    }
}








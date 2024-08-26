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
    createMatrix();
    fillMatrix(other.m_array);
}

Shape::Shape(char name, int** arr, int width, int cordX, int cordY)
: m_name(name), m_width(width), m_array(nullptr)
, m_cordX(cordX), m_cordY(cordY){
    createMatrix();
    fillMatrix(arr);
}

Shape::~Shape() {
    delMatrix();
}

Shape Shape::S() {
    int arr[3][3] = {{0, 1, 1},{1, 1, 0}, {0, 0, 0}};
    Shape shape('S',reinterpret_cast<int **>(arr), 3, 0, 0);
    return shape;
}
Shape Shape::Z() {

    int arr[3][3] = {{1, 1, 0}, {0, 1, 1},{0, 0, 0}};
    Shape shape('Z',reinterpret_cast<int **>(arr), 3, 0, 0);
    return shape;
}
Shape Shape::T() {
    int arr[3][3] = {{0, 1, 0},{1, 1, 1}, {0, 0, 0}};
    Shape shape('T',reinterpret_cast<int **>(arr), 3, 0, 0);
    return shape;
}
Shape Shape::L() {
    int arr[3][3] = {{0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Shape shape('L',reinterpret_cast<int **>(arr), 3, 0, 0);
    return shape;
}
Shape Shape::J() {
    int arr[3][3] = {{1, 0, 0}, {1, 1, 1}, {0, 0, 0}};
    Shape shape('J',reinterpret_cast<int **>(arr), 3, 0, 0);
    return shape;
}
Shape Shape::O() {
    int arr[2][2] ={{1, 1}, {1, 1}};
    Shape shape('O',reinterpret_cast<int **>(arr), 2, 0, 0);
    return shape;
}
Shape Shape::I() {
    int arr[4][4] ={{0, 0, 0, 0}, {1, 1, 1, 1},
                    {0, 0, 0, 0}, {0, 0, 0, 0}};
    Shape shape('I',reinterpret_cast<int **>(arr), 4, 0, 0);
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

void Shape::createMatrix() {
    if (nullptr == m_array) {
        m_array = new int* [m_width];
        for (int i = 0; i < m_width; ++i) {
            m_array[i] = new int [m_width];
        }
    }
}

void Shape::fillMatrix(int** matrix) {
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_width; ++j)
            m_array[i][j] = matrix[i][j];
    }
}

Shape& Shape::operator=(const Shape &other) {
    this->m_width = other.m_width;
    this->m_cordX = other.m_cordX;
    this->m_cordY = other.m_cordY;
    delMatrix();
    createMatrix();
    fillMatrix(other.m_array);
    return *this;
}




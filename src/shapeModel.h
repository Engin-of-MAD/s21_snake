//
// Created by roach on 23.08.2024.
//
#include<stdexcept>
//#include "../brick_game/tetris/tetris.h"
#ifndef SHAPEMODEL_H
#define SHAPEMODEL_H
class Shapes {
    int **m_array; // shape
    int m_width, m_cordX, m_cordY; // params shape
    char m_name;
    void createShape(int width);
    void fillShape(int** shape);
    void clearShape();
    void shapeS();
    void shapeZ();
    void shapeT();
    void shapeL();
    void shapeJ();
    void shapeO();
    void shapeI();
public:

    Shapes(char name);
    Shapes(char name, int cordX = 0, int cordY = 0);
    Shapes(Shapes& other);
    ~Shapes();

    char name() const;
    int width() const;
    int cordX() const;
    int cordY() const;


    int* operator [](int index);
    int& operator ()(int row, int col);
    void roateShape();
    const int& operator ()(int row, int col) const;
};
#endif //SHAPEMODEL_H

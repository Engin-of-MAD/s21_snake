//
// Created by roach on 23.08.2024.
//

#ifndef SHAPE_MODEL_H
#define SHAPE_MODEL_H

#include <stdexcept>

class Shape{
        char m_name;
        int** m_array; // shape
        int m_width, m_cordX, m_cordY;
        Shape S();
        Shape Z();
        Shape T();
        Shape L();
        Shape J();
        Shape O();
        Shape I();
        void delMatrix();
        void createMatrix();
        void fillMatrix(int** matrix);
public:
        Shape();
        Shape(char name, int** arr, int width, int cordX, int cordY);
        Shape(Shape& other);
        ~Shape();
        char name() const;
        int width() const;
        int cordX() const;
        int cordY() const;

        void increaseCordX();
        void decreaseCordX();
        void increaseCordY();
        void decreaseCordY();
        void rotateShape();

        Shape& operator=(const Shape& other);
        int* operator [](int index);
        int& operator()(int row, int col);
        bool operator()(Shape& other);
};


#endif //SHAPE_MODEL_H

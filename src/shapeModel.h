//
// Created by roach on 23.08.2024.
//

#ifndef SHAPE_MODEL_H
#define SHAPE_MODEL_H

#include<stdexcept>
#include "boardModel.h"


class Shapes {
    struct Shape{
        int **m_array; // shape
        int m_width, m_cordX, m_cordY; // params shape
        char m_name;
    };


    const char shapesArray[7] = {'S', 'Z','T','L','J', 'O', 'I'};
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
    Shapes(GameBoard& gameBoard);
    Shapes(char name);
    Shapes(char name, int cordX, int cordY);
    Shapes(Shapes& other);
    ~Shapes();

    char name() const;
    int width() const;
    int cordX() const;
    int cordY() const;

    bool checkPos();
    void increaseCordX();
    void decreaseCordX();
    void increaseCordY();
    void decreaseCordY();
    void delShape();
    int* operator [](int index);
    int& operator ()(int row, int col);
    void rotateShape();

};
#endif //SHAPE_MODEL_H

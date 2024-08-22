//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H
// #include "../brick_game/tetris/tetris.h"
// #include <initializer_list>
#include<stdexcept>

typedef enum {START = 0, SPAWN, MOVING, PAUSE, GAMEOVER, EXIT_STATE} stateApp;

class GameBoard {
    int** m_gameField;
    int m_width, m_height;
public:
    GameBoard();
    explicit GameBoard(int width = 1, int height = 1);
    GameBoard(GameBoard& other);
    ~GameBoard();
    int width() const;
    int height() const;
    int* operator [](int index);
    int& operator ()(int row, int col);
};

class Shapes {
    int **m_array = nullptr; // shape
    int m_width, m_cordX, m_cordY; // params shape
    char m_name;
    void createShape(int width);
    void fillShape(int** shape);
    void shapeS();
    void shapeZ();
    void shapeT();
    void shapeL();
    void shapeJ();
    void shapeO();
    void shapeI();
public:

    Shapes(char name);
    Shapes(Shapes& other);
    ~Shapes();

    char name() const;
    int width() const;
    int cordX() const;
    int cordY() const;
    int* operator [](int index);
    int& operator ()(int row, int col);
};

class GameObject {

    GameBoard* m_gBoard;
    Shapes* currShape;
    Shapes* nextShape;
    stateApp state;
    int score, bestScore;
    const Shapes* shapesArray[7] = {new Shapes('S'), new Shapes('Z')
                                   , new Shapes('T'), new Shapes('L')
                                   , new Shapes('J'), new Shapes('O')
                                   , new Shapes('I')};

    bool genRandomShape();
    void delShape();
    void writeToBoard();
    bool chekPos();
    void userAction();
    void removeFullRows();
    void updateScore();
    void stateMachine();
};



#endif //BRICKGAME_GAMEOBJ_H

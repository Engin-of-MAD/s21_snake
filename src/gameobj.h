//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H
// #include "../brick_game/tetris/tetris.h"
// #include <initializer_list>


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
};

struct Shape {
    int **m_array; // shape
    int m_width;
    char m_name;
    int cordX, cordY; // params shape
    Shape();
    Shape(int width, char name);
    Shape(Shape& other);
    ~Shape();
};

class GameObject {

    GameBoard* m_gBoard;
    Shape* currShape;
    Shape* nextShape;
    stateApp state;
    int score, bestScore;
    /*
    const Shape ShapesArray[7] = {
        {(int *[]){(int[]){0, 1, 1}, (int[]){1, 1, 0}, (int[]){0, 0, 0}}, 3,
         'S', 0, 0}, // S shape
        {(int *[]){(int[]){1, 1, 0}, (int[]){0, 1, 1}, (int[]){0, 0, 0}}, 3,
         'Z', 0, 0}, // Z shape
        {(int *[]){(int[]){0, 1, 0}, (int[]){1, 1, 1}, (int[]){0, 0, 0}}, 3,
         'T', 0, 0}, // T shape
        {(int *[]){(int[]){0, 0, 1}, (int[]){1, 1, 1}, (int[]){0, 0, 0}}, 3,
         'L', 0, 0}, // L shape
        {(int *[]){(int[]){1, 0, 0}, (int[]){1, 1, 1}, (int[]){0, 0, 0}}, 3,
         'J', 0, 0},                                                // J shape
        {(int *[]){(int[]){1, 1}, (int[]){1, 1}}, 2, 'O', 0, 0}, // O shape
        {(int *[]){(int[]){0, 0, 0, 0}, (int[]){1, 1, 1, 1},
                    (int[]){0, 0, 0, 0}, (int[]){0, 0, 0, 0}},
         4, 'I', 0, 0} // I shape
        // you can add any shape like it's done above. Don't be naughty.
    };
    */

    bool genRandomShape();
    Shape copyShape(Shape& other);
    void delShape();
    void writeToBoard();
    bool chekPos();
    void userAction();
    void removeFullRows();
    void updateScore();
    void stateMachine();
};



#endif //BRICKGAME_GAMEOBJ_H

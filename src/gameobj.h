//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H
#include "../brick_game/tetris/tetris.h"
#include <initializer_list>


class Board {
    int** board = nullptr;
    int width, height;
    void initBoard();
public:
    explicit Board(int width, int height);
    ~Board();

};


struct Shapes : Shape {
//    char **array; // shape
//    char name;
//    int row, col, width;;
    Shapes() = default;

//    Shapes(Shapes& other);
    ~Shapes();
};
//Shapes S = {(char *[]){(char[]){0, 1, 1}, (char[]){1, 1, 0}, (char[]){0, 0, 0}}, 3, 'S', 0, 0};
//Shapes Z = {(char *[]){(char[]){1, 1, 0}, (char[]){0, 1, 1}, (char[]){0, 0, 0}}, 3, 'Z', 0, 0};
//Shapes T = {(char *[]){(char[]){0, 1, 0}, (char[]){1, 1, 1}, (char[]){0, 0, 0}}, 3, 'T', 0, 0};
//Shapes
class GameObject{
    Board* Table;
    Shapes* next;
    Shapes* current;

//    Shapes ShapesArray[7] =  {
//            {(char *[]){(char[]){0, 1, 1}, (char[]){1, 1, 0}, (char[]){0, 0, 0}}, 3,
//                                                                                     'S', 0, 0}, // S shape
//            {(char *[]){(char[]){1, 1, 0}, (char[]){0, 1, 1}, (char[]){0, 0, 0}}, 3,
//                                                                                     'Z', 0, 0}, // Z shape
//            {(char *[]){(char[]){0, 1, 0}, (char[]){1, 1, 1}, (char[]){0, 0, 0}}, 3,
//                                                                                     'T', 0, 0}, // T shape
//            {(char *[]){(char[]){0, 0, 1}, (char[]){1, 1, 1}, (char[]){0, 0, 0}}, 3,
//                                                                                     'L', 0, 0}, // L shape
//            {(char *[]){(char[]){1, 0, 0}, (char[]){1, 1, 1}, (char[]){0, 0, 0}}, 3,
//                                                                                     'J', 0, 0},                                                // J shape
//            {(char *[]){(char[]){1, 1}, (char[]){1, 1}}, 2, 'O', 0, 0}, // O shape
//            {(char *[]){(char[]){0, 0, 0, 0}, (char[]){1, 1, 1, 1},
//                 (char[]){0, 0, 0, 0}, (char[]){0, 0, 0, 0}},
//                                                                                  4, 'I', 0, 0} // I shape
//            // you can add any shape like it's done above. Don't be naughty.
//    };
    struct timeval before_now, now; // time points
    suseconds_t timer;              // time delay
    int score;     // current score
    int input;     // user input
    state_t state;

public:
    GameObject();
    ~GameObject() = default;


    void writeToBoard();
    void speedOfGame();
    void gameControl();
    void checkPos();
    void getNewRandomShape();
    void rotateShape();
    void removeFullString();
    void startAction();
    void stateMachine();
    void getSignal();
};



#endif //BRICKGAME_GAMEOBJ_H

#include "gameobj.h"


Board::Board(int width, int height) : width(width), height(height) {
    board = new int* [height];
    for (size_t i = 0; i < height; ++i) {
        board[i] = new int [width];
    }
    initBoard();
}

Board::~Board() {
    if (board != nullptr) {
        for (int i = 0; i < height; ++i) {
            delete[] board;
        }
        delete board;
        board = nullptr;
    }
}

Shapes::~Shapes() {
    if (array != nullptr) {
        for (size_t i = 0; i < width; i++) {
            delete[] array[i];
        }
    }
    delete[] array;
}



//Shapes::Shapes(Shapes &other) : Shape(other) {}

void Board::initBoard(){
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            board[i][j] = 0;
        }
    }
}
GameObject::GameObject() : score(0)
, timer(1000000)
, state(START)
, Table(new Board(10, 20))
, current(new Shapes())
, next(new Shapes)
{}



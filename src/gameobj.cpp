//
// Created by roach on 23.07.2024.
//

#include "gameobj.h"

void GameObj::Field::createField() {
    field = new int * [height];
    if (nullptr != field) {
        try {
            for (int i = 0; i < height; ++i) {
                field[i] = new int[width];
                if (nullptr == field[i]) {
                    throw std::bad_alloc(); // Or another appropriate exception
                }
            }
        } catch (...) {
            GameObj::Field::deleteField();
        }
    }
}
void GameObj::Field::deleteField() {
    if (nullptr != field) {
        for (size_t i = 0; i < width; i++) {
            delete[] field[i];
        }
        delete[] field;
        field = nullptr;
    }
}
GameObj::Field::Field(int height, int width) :height(height), width(width) {
    createField();
}
GameObj::Field::~Field() {
    deleteField();
}

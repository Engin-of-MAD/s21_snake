//
// Created by roach on 23.07.2024.
//

#ifndef BRICKGAME_GAMEOBJ_H
#define BRICKGAME_GAMEOBJ_H
#include <exception>

class GameObj {
    int state = 0;
    class Field {
        int** field = nullptr;
        int height = 0;
        int width = 0;
        void createField();
        void deleteField();
    public:
        Field(int height, int width);
        ~Field();
    };

    int time = 0;
public:
    ;

};


#endif //BRICKGAME_GAMEOBJ_H

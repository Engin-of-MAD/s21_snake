//
// Created by roach on 18.09.2024.
//

#ifndef UNTITLED2_SNAKEGAMEMODEL_H
#define UNTITLED2_SNAKEGAMEMODEL_H

namespace s21 {
    class SnakeGameModel {
    public:
        enum stateGame {
            START = 0, SPAWN, MOVING, PAUSE, STOP, GAMEOVER, EXIT_STATE
        };
        enum gameControl {
            NOSIG = 0, MOVE_UP, MOVE_DOWN, MOVE_RIGHT, MOVE_LEFT, STAR_GAME, PAUSE_GAME, EXIT_GAME, STOP_GAME
        };
    private:
        gameControl userControl;
        stateGame state;
    };

}
#endif //UNTITLED2_SNAKEGAMEMODEL_H

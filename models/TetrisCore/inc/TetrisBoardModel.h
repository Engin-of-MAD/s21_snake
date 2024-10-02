//
// Created by roach on 19.09.2024.
//

#ifndef TETRISBOARDMODLE_H
#define TETRISBOARDMODLE_H
#include "../../UnionModule/inc/BaseBoardModel.h"
#include "TetrominoFactory.h"
namespace s21 {
    class TetrisBoardModel : public BaseBoardModel {
    public:
        TetrisBoardModel();
        explicit TetrisBoardModel(int width, int height);
        void setShapeOnBoard(Tetromino &shape);
        bool isRowFull(int rowI);
        void shiftDownRows(int rowI);
        void clearRow(int rowI);
        void initRow(int n);
    };

}
#endif //TETRISBOARDMODLE_H

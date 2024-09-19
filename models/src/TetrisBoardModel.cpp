//
// Created by roach on 19.09.2024.
//


#include "../inc/TetrisBoardModel.h"

namespace s21 {
    TetrisBoardModel::TetrisBoardModel() : BaseBoardModel(1, 1) {}

    TetrisBoardModel::TetrisBoardModel(int width, int height) : BaseBoardModel(width, height) {}

    void TetrisBoardModel::setShapeOnBoard(Tetromino &shape) {
        for (int i = 0; i < shape.getWidth(); ++i) {
            for (int j = 0; j < shape.getWidth(); ++j) {
                if (shape[i][j])
                    m_boardField[shape.getCordY() + i][shape.getCordX() + j] = shape[i][j];
            }
        }
    }

    bool TetrisBoardModel::isRowFull(int rowI) {
        int sum = 0;
        for (int colI = 0; colI < m_width; ++colI)
            sum += m_boardField[rowI][colI];
        if (sum == m_width) {
            return true;
        }
        return false;
    }

    void TetrisBoardModel::shiftDownRows(int rowI) {
        std::cout << rowI << std::endl;
        for (int shiftRowI = rowI; shiftRowI >= 1; --shiftRowI) {
            for (int colI = 0; colI < m_width; ++colI) {
                m_boardField[shiftRowI][colI] = m_boardField[shiftRowI - 1][colI];
            }
        }
    }

    void TetrisBoardModel::clearRow(int rowI) {
        for (int colI = 0; colI < m_width; ++colI)
            m_boardField[rowI][colI] = 0;
    }

}

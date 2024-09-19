//
// Created by roach on 23.08.2024.
//

#include "../inc/BaseBoardModel.h"
namespace s21 {
    BaseBoardModel::BaseBoardModel() : BaseBoardModel(1, 1) {}

    BaseBoardModel::BaseBoardModel(int width, int height)
            : m_boardField(nullptr), m_width(width), m_height(height) {
        m_boardField = newBoard(m_width, m_height);
        for (int i = 0; i < m_height; ++i)
            for (int j = 0; j < m_width; ++j)
                m_boardField[i][j] = 0;
    }

    BaseBoardModel::BaseBoardModel(BaseBoardModel &other) : BaseBoardModel(other.m_width, other.m_height) {
        for (int i = 0; i < other.m_height; ++i) {
            for (int j = 0; j < other.m_width; ++j) {
                m_boardField[i][j] = other.m_boardField[i][j];
            }
        }
    }

    BaseBoardModel::~BaseBoardModel() {
        delBoard(m_boardField, m_width, m_height);
    }

    int **BaseBoardModel::newBoard(int width, int height) {
        int **board = new int *[height];
        if (!board) return nullptr;

        for (int i = 0; i < height; ++i) {
            board[i] = new int[width];
            if (!board[i]) {
                for (int j = 0; j < i; ++j) delete board[j];
                delete[] board;
                return nullptr;
            }
        }
        return board;
    }

    int **BaseBoardModel::copyBoard(int **otherBoard, int width, int height) {
        int **board = newBoard(width, height);
        if (!board) return nullptr;
        for (int i = 0; i < height; ++i)
            std::copy(otherBoard[i], otherBoard[i] + width, board[i]);
        return board;
    }


    void BaseBoardModel::delBoard(int **board, int width, int height) {
        if (board) {
            for (int i = 0; i < height; ++i)
                delete[] m_boardField[i];
            delete[] board;

        }
    }

    int BaseBoardModel::getWidth() const { return m_width; }

    int BaseBoardModel::getHeight() const { return m_height; }

    void BaseBoardModel::reset() {
        for (int i = 0; i < m_height; ++i)
            for (int j = 0; j < m_width; ++j)
                m_boardField[i][j] = 0;
    }

    void BaseBoardModel::printInConsole() const {
        for (int i = 0; i < m_height; ++i) {
            for (int j = 0; j < m_width; ++j) {
                std::cout << m_boardField[i][j] << " ";
            }
            std::cout << "\n";
        }
    }


    int *BaseBoardModel::operator[](int index) { return m_boardField[index]; }

    BaseBoardModel &BaseBoardModel::operator=(const BaseBoardModel &other) {
        if (this == &other) return *this;
        m_width = other.m_width;
        m_height = other.m_height;
        delBoard(m_boardField, m_width, m_height);
        m_boardField = copyBoard(other.m_boardField, m_width, m_width);
        return *this;
    }

}



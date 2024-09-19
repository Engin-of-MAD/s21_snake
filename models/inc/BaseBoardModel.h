//
// Created by roach on 23.08.2024.
//

#ifndef BOARDMODEL_H
#define BOARDMODEL_H
#include <iostream>
namespace s21 {
    class BaseBoardModel {
    protected:
        int **m_boardField;
        int m_width, m_height;
        int **newBoard(int width, int height);
        int **copyBoard(int **otherBoard, int width, int height);
        void delBoard(int **board, int width, int height);

    public:
        BaseBoardModel();
        BaseBoardModel(int width, int height);
        BaseBoardModel(BaseBoardModel &other);
        virtual ~BaseBoardModel();
        int getWidth() const;
        int getHeight() const;
        virtual void printInConsole() const;
        void reset();
        virtual int *operator[](int index);
        BaseBoardModel &operator=(const BaseBoardModel &other);
    };
}

#endif //BOARDMODEL_H

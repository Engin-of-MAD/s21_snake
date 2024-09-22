//
// Created by roach on 29.08.2024.
//

#ifndef FIGUREFACTORY_H
#define FIGUREFACTORY_H

#include <iostream>
#include <array>
#include <random>
namespace s21 {
    using Matrix4x4 = std::array<std::array<int, 4>, 4>;
    using Matrix3x3 = std::array<std::array<int, 3>, 3>;
    using Matrix2x2 = std::array<std::array<int, 2>, 2>;

    class Tetromino {

    public:
        enum class ShapesTypes : char {
            Z = 'Z', S = 'S', T = 'T', L = 'L', J = 'J', O = 'O', I = 'I', E = '-'
        };

        Tetromino();

        Tetromino(ShapesTypes shapeType, const Matrix4x4 &shape, int cordX = 0, int cordY = 0);

        Tetromino(ShapesTypes shapeType, const Matrix3x3 &shape, int cordX = 0, int cordY = 0);

        Tetromino(ShapesTypes shapeType, const Matrix2x2 &shape, int cordX = 0, int cordY = 0);

        Tetromino(Tetromino &other);

        Tetromino(Tetromino &&other) noexcept;

        ~Tetromino();

        void printInConsole();

        void setCordX(int cordX);

        int getCordX() const;

        int getCordY() const;

        int getWidth() const;

        ShapesTypes getName();

        void increaseCordX();

        void increaseCordY();

        void decreaseCordX();

        void rotate();

        int *operator[](int index);

        Tetromino &operator=(const Tetromino &other);

        Tetromino &operator=(Tetromino &&other) noexcept;

    protected:
        int m_width, m_cordX, m_cordY;
        int **m_shape;
        ShapesTypes m_name;

        int **createMatrix(int **shape, int width);

        void delMatrix(int **shape, int width);

        void fillMatrix(int **shape, int **other, int width);
    };

    class TetrominoFactory {
    public:

        static Tetromino createTetromino(Tetromino::ShapesTypes type);

        static Tetromino randomTetromino();

        static Tetromino *createTetrominoPointer(Tetromino::ShapesTypes type);

    };
}
#endif //FIGUREFACTORY_H

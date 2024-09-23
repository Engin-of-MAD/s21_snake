//
// Created by roach on 22.09.2024.
//

#ifndef FABRICFOOD_H
#define FABRICFOOD_H
#include <random>
#include <iostream>
namespace s21 {
    class SnakeFood {
        int m_x, m_y;
    public:
        SnakeFood();
        SnakeFood(int x, int y);
        bool isFood(int x, int y) const;
        int getX() const;
        int getY() const;
        void log();
    };
    class FabricSnakeFood {
    public:
        static SnakeFood createFood();

    };
}
#endif //FABRICFOOD_H

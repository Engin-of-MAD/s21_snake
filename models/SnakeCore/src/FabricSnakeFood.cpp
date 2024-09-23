//
// Created by roach on 22.09.2024.
//

#include "../inc/FabricSnakeFood.h"

namespace s21 {
    SnakeFood::SnakeFood() : SnakeFood(5, 10){}
    SnakeFood::SnakeFood(int x, int y) : m_x(x), m_y(y) {}
    bool s21::SnakeFood::isFood(int x, int y) const {
        if (m_x == x && m_y == y) return true;
        return false;
    }
    int SnakeFood::getX() const { return m_x; }
    int SnakeFood::getY() const { return m_y;}

    void SnakeFood::log() {
        std::cout << "Food: " << this << ", X: "<< m_x << ", Y: " << m_y << std::endl;
    }

    SnakeFood FabricSnakeFood::createFood() {
        static std::random_device randDevice;
        static std::mt19937 rnd(randDevice());
        std::uniform_int_distribution<> rangeX(0, 9), rangeY(0, 19);
        return SnakeFood(rangeX(rnd), rangeY(rnd));
    }
}
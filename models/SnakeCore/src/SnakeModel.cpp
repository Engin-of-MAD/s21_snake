//
// Created by roach on 18.09.2024.
//


#include "../inc/SnakeModel.h"
namespace s21 {
    SnakeModel::SnakeItem::SnakeItem(int x, int y) : x(x), y(y) {}
    SnakeModel::SnakeModel(int sizeSnake, int sizeItem)
    : m_size(sizeSnake), m_sizeItem(sizeItem)
    {
        for (int i = 0; i < m_size; ++i)
            m_snakeBody.push_back(SnakeItem(i, 0));
    }

    int SnakeModel::getSize() const { return m_size; }
    int SnakeModel::getSizeItem() const { return m_sizeItem; }
    bool SnakeModel::isSnake(int x, int y) {
        bool is_snake = std::any_of(m_snakeBody.begin(), m_snakeBody.end(),
                    [x, y](const SnakeItem& item){return item.x == x && item.y == y;});
        return is_snake;
    }

    SnakeModel::SnakeItem &SnakeModel::operator[](int index) {
        return m_snakeBody[index];
    }

    bool SnakeModel::checkSelfIntersection(int x, int y) {
        bool check = std::find_if(m_snakeBody.begin() + 1, m_snakeBody.end(),
                                  [x, y](const SnakeItem& item){return item.x == x && item.y == y;}) != m_snakeBody.end();
        return check ;
    }



}
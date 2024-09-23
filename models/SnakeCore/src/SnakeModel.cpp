//
// Created by roach on 18.09.2024.
//


#include "../inc/SnakeModel.h"
namespace s21 {
    SnakeItem::SnakeItem(int x, int y) : x(x), y(y) {}
    SnakeItem::SnakeItem() : SnakeItem(0, 0) {}
    SnakeModel::SnakeModel(int sizeSnake, int sizeItem)
    : m_size(sizeSnake), m_sizeItem(sizeItem)
    ,m_snakeDirection(Direction::MoveDown){for (int i = 0; i < m_size; ++i) m_snakeBody.push_back(new SnakeItem(i, 0));}
    int SnakeModel::getSize() const { return m_size; }
    void SnakeModel::log() {
        for (auto it = m_snakeBody.begin(); it != m_snakeBody.end(); ++it) {
            if (it == m_snakeBody.begin()) std::cout << "Snake Head: " << (*it)->x << " " << (*it)->y << std::endl;
            else std::cout << "Snake Item: " << (*it)->x << " " << (*it)->y << std::endl;
        }
    }
    void SnakeModel::push_head(SnakeItem* item) { m_snakeBody.insert(m_snakeBody.begin(), item); }
    std::vector<SnakeItem*>::iterator SnakeModel::begin() { return m_snakeBody.begin(); }
    std::vector<SnakeItem*>::iterator SnakeModel::end() { return m_snakeBody.end(); }
    void SnakeModel::setDirection(SnakeModel::Direction direction) {
        if (isSelfInterference(direction)) m_snakeDirection = direction; }
    void SnakeModel::update() {
        SnakeItem* head;
        SnakeItem oldHead = **m_snakeBody.begin();
        switch (m_snakeDirection) {
            case Direction::MoveDown:
                head = new SnakeItem(oldHead.x, oldHead.y + 1); break;
            case Direction::MoveUp:
                head = new SnakeItem(oldHead.x, oldHead.y - 1); break;
            case Direction::MoveLeft:
                head = new SnakeItem(oldHead.x - 1, oldHead.y); break;
            case Direction::MoveRight:
                head = new SnakeItem(oldHead.x + 1, oldHead.y); break;
        }
        push_head(head);
        m_snakeBody.pop_back();
    }
    SnakeItem *SnakeModel::operator[](int index) { return m_snakeBody[index]; }
    bool SnakeModel::isBody(SnakeItem head) {
        for (int i = 1; i < m_snakeBody.size(); ++i)
            if (m_snakeBody[i]->x == head.x && m_snakeBody[i]->y == head.y)
                return false;
        return true;
    }
    bool SnakeModel::isSelfInterference(SnakeModel::Direction direction) {
        bool checkDirection = true;
        if (m_snakeDirection == Direction::MoveDown && direction == Direction::MoveUp
        || m_snakeDirection == Direction::MoveUp && direction == Direction::MoveDown)
            checkDirection = false;
        if (m_snakeDirection == Direction::MoveRight && direction == Direction::MoveLeft
        || m_snakeDirection == Direction::MoveLeft && direction == Direction::MoveRight)
            checkDirection = false;
        return checkDirection;
    }
    bool SnakeModel::isSnake(int x, int y) {
        for (int i = 1; i < m_snakeBody.size(); ++i)
            if (m_snakeBody[i]->x == x && m_snakeBody[i]->y == y)
                return false;
        return true;
    }
}
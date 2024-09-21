//
// Created by roach on 18.09.2024.
//


#include "../inc/SnakeModel.h"
namespace s21 {
    SnakeItem::SnakeItem(int x, int y) : x(x), y(y) {}
    SnakeItem::SnakeItem() : SnakeItem(0, 0) {}
    SnakeModel::SnakeModel(int sizeSnake, int sizeItem)
    : m_size(sizeSnake), m_sizeItem(sizeItem), m_snakeDirection(Direction::MoveDown){
        for (int i = 0; i < m_size; ++i)
            m_snakeBody.push_back(new SnakeItem(i, 0));
    }
    int SnakeModel::getSize() const { return m_size; }
    bool SnakeModel::isSnake(int x, int y) {
        bool is_snake = std::any_of(m_snakeBody.begin(), m_snakeBody.end(),
                    [x, y](const SnakeItem* item){return item->x == x && item->y == y;});
        return is_snake;
    }

    bool SnakeModel::checkSelfIntersection(int x, int y) {
        auto it  = m_snakeBody.begin();
        auto end = m_snakeBody.end();
        bool check = std::find_if(it++, end,
                                  [x, y](const SnakeItem* item){return item->x == x && item->y == y;}) != end;
        return check ;
    }

    void SnakeModel::log() {
        for (auto it = m_snakeBody.begin(); it != m_snakeBody.end(); ++it) {
            if (it == m_snakeBody.begin()) std::cout << "Snake Head: " << (*it)->x << " " << (*it)->y << std::endl;
            else std::cout << "Snake Item: " << (*it)->x << " " << (*it)->y << std::endl;
        }
    }

    void SnakeModel::push_head(SnakeItem* item) { m_snakeBody.insert(m_snakeBody.begin(), item); }
    std::vector<SnakeItem*>::iterator SnakeModel::begin() { return m_snakeBody.begin(); }
    std::vector<SnakeItem*>::iterator SnakeModel::end() { return m_snakeBody.end(); }
    void SnakeModel::setDirection(SnakeModel::Direction direction) { m_snakeDirection = direction; }
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

}
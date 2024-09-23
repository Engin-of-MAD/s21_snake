//
// Created by roach on 18.09.2024.
//

#ifndef UNTITLED2_SNAKEMODEL_H
#define UNTITLED2_SNAKEMODEL_H

#include <vector>
#include <iostream>
namespace s21 {
    struct SnakeItem {
        int x, y;
        SnakeItem(int x, int y);
        SnakeItem();
    };
    class SnakeModel {
    public:
        enum class Direction{MoveUp, MoveDown, MoveLeft, MoveRight};
        explicit SnakeModel(int sizeSnake = 4, int sizeItem = 10);
        void setDirection(Direction direction);
        void update();
        bool isBody(SnakeItem head);
        bool isSnake(int x, int y);
        void push_head(SnakeItem* item);
        void addTail();
        int getSize() const;
        std::vector<SnakeItem*>::iterator begin();
        std::vector<SnakeItem*>::iterator end();
        SnakeItem* operator[](int index);
        void log();
    private:
        int m_size,  m_sizeItem;
        std::vector<SnakeItem*> m_snakeBody;
        Direction m_snakeDirection;
        bool isSelfInterference(Direction direction);
        SnakeItem* genSnakeItem(SnakeItem* pos, Direction direction);
    };
}

#endif //UNTITLED2_SNAKEMODEL_H

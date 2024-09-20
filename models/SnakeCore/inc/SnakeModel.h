//
// Created by roach on 18.09.2024.
//

#ifndef UNTITLED2_SNAKEMODEL_H
#define UNTITLED2_SNAKEMODEL_H

#include <vector>
#include <algorithm>
namespace s21 {
    class SnakeModel {
        struct SnakeItem {
            int x, y;
            SnakeItem(int x, int y);
        };
        int m_size,  m_sizeItem;
        std::vector<SnakeItem> m_snakeBody;
    public:
        explicit SnakeModel(int sizeSnake = 4, int sizeItem = 10);
        bool isSnake(int x, int y);
        bool checkSelfIntersection(int x, int y);
        int getSize() const;
        int getSizeItem() const;
        SnakeItem& operator[](int index);

    };
}

#endif //UNTITLED2_SNAKEMODEL_H

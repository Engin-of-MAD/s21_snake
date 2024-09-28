//
// Created by roach on 18.09.2024.
//

#include "../inc/SnakeModel.h"
namespace s21 {
SnakeItem::SnakeItem(int x, int y) : x(x), y(y) {}
SnakeItem::SnakeItem() : SnakeItem(0, 0) {}
SnakeModel::SnakeModel(int sizeSnake, int sizeItem)
    : m_size(sizeSnake),
      m_sizeItem(sizeItem),
      m_snakeDirection(Direction::MoveDown) {
  for (int i = 0; i < m_size; ++i) m_snakeBody.push_back(SnakeItem(i, 0));
}
int SnakeModel::getSize() const { return m_size; }
void SnakeModel::log() {
  std::cout << "Snake: " << this << ", Size: " << getSize() << std::endl;
  for (auto it = m_snakeBody.begin(); it != m_snakeBody.end(); ++it) {
    if (it == m_snakeBody.begin())
      std::cout << "Snake Head: " << (*it).x << " " << (*it).y << std::endl;
    else
      std::cout << "Snake Item: " << (*it).x << " " << (*it).y << std::endl;
  }
}
void SnakeModel::push_head(SnakeItem item) {
  m_snakeBody.insert(m_snakeBody.begin(), item);
}
std::vector<SnakeItem>::iterator SnakeModel::begin() {
  return m_snakeBody.begin();
}
std::vector<SnakeItem>::iterator SnakeModel::end() { return m_snakeBody.end(); }
void SnakeModel::setDirection(SnakeModel::Direction direction) {
  if (isSelfInterference(direction)) m_snakeDirection = direction;
}
void SnakeModel::update() {
  push_head(SnakeItem(genSnakeItem(*m_snakeBody.begin(), m_snakeDirection)));
  m_snakeBody.pop_back();
}
SnakeItem SnakeModel::operator[](int index) { return m_snakeBody[index]; }
bool SnakeModel::isBody(SnakeItem head) {
  for (size_t i = 1; i < m_snakeBody.size(); ++i)
    if (m_snakeBody[i].x == head.x && m_snakeBody[i].y == head.y) return false;
  return true;
}
bool SnakeModel::isSelfInterference(SnakeModel::Direction direction) {
  bool checkDirection = true;
  if ((m_snakeDirection == Direction::MoveDown &&
       direction == Direction::MoveUp) ||
      (m_snakeDirection == Direction::MoveUp &&
       direction == Direction::MoveDown))
    checkDirection = false;
  if ((m_snakeDirection == Direction::MoveRight &&
       direction == Direction::MoveLeft) ||
      (m_snakeDirection == Direction::MoveLeft &&
       direction == Direction::MoveRight))
    checkDirection = false;
  return checkDirection;
}
bool SnakeModel::isSnake(int x, int y) {
  for (size_t i = 1; i < m_snakeBody.size(); ++i)
    if (m_snakeBody[i].x == x && m_snakeBody[i].y == y) return false;
  return true;
}

void SnakeModel::addTail() {
  SnakeItem lastItem = m_snakeBody[m_size - 1];
  SnakeItem prevItem = m_snakeBody[m_size - 2];
  SnakeItem newTail;
  if (prevItem.x - lastItem.x == 1)
    newTail = genSnakeItem(lastItem, Direction::MoveRight);
  else if (prevItem.x - lastItem.x == -1)
    newTail = genSnakeItem(lastItem, Direction::MoveLeft);
  else if (prevItem.y - lastItem.y == 1)
    newTail = genSnakeItem(lastItem, Direction::MoveUp);
  else if (prevItem.y - lastItem.y == -1)
    newTail = genSnakeItem(lastItem, Direction::MoveDown);
  m_snakeBody.push_back(newTail);
  m_size = m_snakeBody.size();
}

SnakeItem SnakeModel::genSnakeItem(SnakeItem pos, Direction direction) {
  SnakeItem head;
  switch (direction) {
    case Direction::MoveDown:
      head = SnakeItem(pos.x, pos.y + 1);
      break;
    case Direction::MoveUp:
      head = SnakeItem(pos.x, pos.y - 1);
      break;
    case Direction::MoveLeft:
      head = SnakeItem(pos.x - 1, pos.y);
      break;
    case Direction::MoveRight:
      head = SnakeItem(pos.x + 1, pos.y);
      break;
  }
  return head;
}
}  // namespace s21
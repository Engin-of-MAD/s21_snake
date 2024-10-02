//
// Created by roach on 23.08.2024.
//

#include "../inc/BaseBoardModel.h"
namespace s21 {
BaseBoardModel::BaseBoardModel() : BaseBoardModel(1, 1) {}
BaseBoardModel::BaseBoardModel(int width, int height, int sizeCell)
    : m_boardField(nullptr),
      m_width(width),
      m_height(height),
      m_sizeCell(sizeCell) {
  m_boardField = newBoard(m_width, m_height);
  if (m_boardField)
    for (int i = 0; i < m_height; ++i)
      for (int j = 0; j < m_width; ++j) m_boardField[i][j] = 0;
}

BaseBoardModel::BaseBoardModel(BaseBoardModel &other)
    : BaseBoardModel(other.m_width, other.m_height) {
  if (m_boardField && other.m_boardField)
    for (int i = 0; i < other.m_height; ++i)
      for (int j = 0; j < other.m_width; ++j)
        m_boardField[i][j] = other.m_boardField[i][j];
}

BaseBoardModel::~BaseBoardModel() { delBoard(m_boardField, m_height); }
int **BaseBoardModel::newBoard(int width, int height) {
  int **board = new int *[height];
  if (!board) return nullptr;

  for (int i = 0; i < height; ++i) {
    board[i] = new int[width];
    if (!board[i]) {
      for (int j = 0; j < i; ++j) delete board[j];
      delete[] board;
      return nullptr;
    }
  }
  return board;
}

int **BaseBoardModel::copyBoard(int **otherBoard, int width, int height) {
  int **board = newBoard(width, height);
  if (!board) return nullptr;
  for (int i = 0; i < height; ++i)
    std::copy(otherBoard[i], otherBoard[i] + width, board[i]);
  return board;
}

void BaseBoardModel::delBoard(int **board, int height) {
  if (!board || !*board) return;
  for (int i = 0; i < height; ++i) delete[] m_boardField[i];
  delete[] board;
}

int BaseBoardModel::getWidth() const { return m_width; }
int BaseBoardModel::getHeight() const { return m_height; }
int BaseBoardModel::getSizeCell() const { return m_sizeCell; }
void BaseBoardModel::reset() {
  for (int i = 0; i < m_height; ++i)
    for (int j = 0; j < m_width; ++j) m_boardField[i][j] = 0;
}
void BaseBoardModel::printInConsole() const {
    std::cout<< "#############################################"<< std::endl;

    std::cout<< "BoardModel: " << this << std::endl;
  for (int i = 0; i < m_height; ++i) {
    for (int j = 0; j < m_width; ++j) {
      std::cout << m_boardField[i][j] << " ";
    }
    std::cout << "\n";
  }
    std::cout<< "#############################################"<< std::endl;

}

int *BaseBoardModel::operator[](int index) { return m_boardField[index]; }
BaseBoardModel &BaseBoardModel::operator=(const BaseBoardModel &other) {
  if (this != &other) {

      delBoard(m_boardField, m_height);
      m_width = other.m_width;
      m_height = other.m_height;
      m_sizeCell = other.m_sizeCell;

//      m_boardField = newBoard(other.m_width, other.m_height);
      m_boardField = copyBoard(other.m_boardField, other.m_width, other.m_height);
  }
  return *this;
}

bool BaseBoardModel::operator==(const BaseBoardModel &other) {
    bool check_params = (m_height == other.m_height) && (m_width == other.m_width) && (m_sizeCell == other.m_sizeCell);
    int content_check = 0;
    if(check_params) {
        for (int i = 0; i < other.m_height; ++i) {
            for (int j = 0; j < other.m_width; ++j) {
                if (m_boardField[i][j] == other.m_boardField[i][j]) content_check++;
            }
        }
    }
    if (m_width * m_height == content_check)
        return true;
    return false;
}

}  // namespace s21

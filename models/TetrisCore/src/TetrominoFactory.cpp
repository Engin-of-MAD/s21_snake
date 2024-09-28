//
// Created by roach on 29.08.2024.
//

#include "../inc/TetrominoFactory.h"

namespace s21 {
Tetromino::Tetromino(Tetromino::ShapesTypes shapeType, const Matrix2x2 &shape,
                     int cordX, int cordY)
    : m_width(2),
      m_cordX(cordX),
      m_cordY(cordY),
      m_shape(new int *[m_width]),
      m_name(shapeType) {
  for (int i = 0; i < m_width; ++i) {
    m_shape[i] = new int[m_width];
    std::copy(shape[i].begin(), shape[i].end(), m_shape[i]);
  }
}

Tetromino::Tetromino(Tetromino::ShapesTypes shapeType, const Matrix3x3 &shape,
                     int cordX, int cordY)
    : m_width(3),
      m_cordX(cordX),
      m_cordY(cordY),
      m_shape(new int *[m_width]),
      m_name(shapeType) {
  for (int i = 0; i < m_width; ++i) {
    m_shape[i] = new int[m_width];
    std::copy(shape[i].begin(), shape[i].end(), m_shape[i]);
  }
}

Tetromino::Tetromino()
    : m_width(4),
      m_cordX(0),
      m_cordY(0),
      m_shape(new int *[m_width]),
      m_name(ShapesTypes::E) {
  for (int i = 0; i < m_width; ++i) {
    m_shape[i] = new int[m_width];
    for (int j = 0; j < m_width; ++j) {
      m_shape[i][j] = 0;
    }
  }
}

Tetromino::Tetromino(Tetromino::ShapesTypes shapeType, const Matrix4x4 &shape,
                     int cordX, int cordY)
    : m_width(4),
      m_cordX(cordX),
      m_cordY(cordY),
      m_shape(new int *[m_width]),
      m_name(shapeType) {
  for (int i = 0; i < m_width; ++i) {
    m_shape[i] = new int[m_width];
    std::copy(shape[i].begin(), shape[i].end(), m_shape[i]);
  }
}

Tetromino::Tetromino(Tetromino &other)
    : m_width(other.m_width),
      m_cordX(other.m_cordX),
      m_cordY(other.m_cordY),
      m_shape(createMatrix(nullptr, m_width)),
      m_name(other.m_name) {
  fillMatrix(m_shape, other.m_shape, m_width);
}

Tetromino::Tetromino(Tetromino &&other) noexcept
    : m_width(other.m_width),
      m_cordX(other.m_cordX),
      m_cordY(other.m_cordY),
      m_shape(other.m_shape),
      m_name(other.m_name) {
  other.m_shape = nullptr;
}

Tetromino::~Tetromino() {
  if (m_shape) {
    for (int i = 0; i < m_width; ++i) {
      delete[] m_shape[i];
    }
    delete[] m_shape;
  }
}

void Tetromino::increaseCordX() { ++m_cordX; }
void Tetromino::decreaseCordX() { --m_cordX; }
void Tetromino::increaseCordY() { ++m_cordY; }
void Tetromino::setCordX(int cordX) { m_cordX = cordX; }
int Tetromino::getCordX() const { return m_cordX; }
int Tetromino::getCordY() const { return m_cordY; }
int Tetromino::getWidth() const { return m_width; }
Tetromino::ShapesTypes Tetromino::getName() { return m_name; }

void Tetromino::printInConsole() {
  std::cout << "################################" << std::endl;
  std::cout << "Pointer Tetromino: " << this << std::endl;
  std::cout << static_cast<char>(m_name) << " " << std::endl;
  for (int i = 0; i < m_width; ++i) {
    for (int j = 0; j < m_width; ++j) {
      std::cout << m_shape[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "################################" << std::endl;
}

int *Tetromino::operator[](int index) { return m_shape[index]; }

Tetromino &Tetromino::operator=(const Tetromino &other) {
  if (this == &other) return *this;
  delMatrix(m_shape, m_width);
  m_width = other.m_width;
  m_cordX = other.m_cordX;
  m_cordY = other.m_cordY;
  m_name = other.m_name;

  m_shape = createMatrix(m_shape, m_width);
  fillMatrix(m_shape, other.m_shape, m_width);

  return *this;
}

Tetromino &Tetromino::operator=(Tetromino &&other) noexcept {
  if (&other != this) {
    delMatrix(m_shape, m_width);
    m_width = other.m_width;
    m_cordX = other.m_cordX;
    m_cordY = other.m_cordY;
    m_shape = other.m_shape;
    m_name = other.m_name;
    other.m_shape = nullptr;
  }
  return *this;
}

int **Tetromino::createMatrix(int **shape, int width) {
  shape = new int *[width];
  for (int i = 0; i < width; ++i) {
    shape[i] = new int[width];
  }
  return shape;
}

void Tetromino::delMatrix(int **shape, int width) {
  if (shape != nullptr) {
    for (int i = 0; i < width; ++i) {
      delete[] shape[i];
    }
    delete[] shape;
  }
}

void Tetromino::fillMatrix(int **shape, int **other, int width) {
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < width; ++j) {
      shape[i][j] = other[i][j];
    }
  }
}

void Tetromino::rotate() {
  Tetromino tmpShape(*this);
  for (int i = 0; i < tmpShape.m_width; ++i) {
    for (int j = 0, k = tmpShape.m_width - 1; j < tmpShape.m_width; ++j, k--)
      m_shape[i][j] = tmpShape[k][i];
  }
}

Tetromino TetrominoFactory::createTetromino(Tetromino::ShapesTypes type) {
  switch (type) {
    case ShapeType::Z:
      return Tetromino(type, Matrix3x3{{{1, 1, 0}, {0, 1, 1}, {0, 0, 0}}});
    case ShapeType::S:
      return Tetromino(type, Matrix3x3{{{0, 1, 1}, {1, 1, 0}, {0, 0, 0}}});
    case ShapeType::T:
      return Tetromino(type, Matrix3x3{{{0, 1, 0}, {1, 1, 1}, {0, 0, 0}}});
    case ShapeType::L:
      return Tetromino(type, Matrix3x3{{{0, 0, 1}, {1, 1, 1}, {0, 0, 0}}});
    case ShapeType::J:
      return Tetromino(type, Matrix3x3{{{1, 0, 0}, {1, 1, 1}, {0, 0, 0}}});
    case ShapeType::O:
      return Tetromino(type, Matrix2x2{{{1, 1}, {1, 1}}});
    case ShapeType::I:
      return Tetromino(
          type,
          Matrix4x4{{{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}}});
    default:
      throw std::invalid_argument("Unsupported tetromino type");
  }
}

Tetromino TetrominoFactory::randomTetromino() {
  const Tetromino::ShapesTypes shapesType[7] = {
      ShapeType ::Z, ShapeType ::S, ShapeType::T, ShapeType::L,
      ShapeType::J,  ShapeType::O,  ShapeType::I};
  static std::mt19937 rnd(std::random_device{}());
  std::uniform_int_distribution<> dist(0, 6);
  return createTetromino(shapesType[dist(rnd)]);
}
}  // namespace s21
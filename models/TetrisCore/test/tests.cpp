#include <gtest/gtest.h>

#include "test.h"

using namespace s21;
TEST(TetrisTest1, Constructor_branch_test_1) {
  TetrisGameModel model;
  ASSERT_EQ(model.getScore(), 0);
  ASSERT_EQ(model.getStateGame(), TetrisGameModel::START);
}

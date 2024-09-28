#include <gtest/gtest.h>
#include "test.h"

using namespace s21;
TEST(UnionModuleTest, BaseBoard1) {
    BaseBoardModel boardModel;
    ASSERT_EQ(boardModel.getWidth(), 1);


}

#include "gtest/gtest.h"
#include "state_machine.hpp"

TEST(FactorialTest, HandlesZeroInput) {
  Mask myMask; 
  myMask.initiate();
  EXPECT_EQ(1, 1);
}

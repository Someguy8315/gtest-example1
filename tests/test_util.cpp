#include "main_test.h"

TEST(some_suite, some_test)
{
    int value = getValue();
    EXPECT_EQ(value, 300);
}

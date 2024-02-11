#ifdef CXX_MEMORY_UNIT_TEST

#include <gtest/gtest.h>

int main(int numArguments, char* arguments[])
{
    ::testing::InitGoogleTest(&numArguments, arguments);

    const int status = RUN_ALL_TESTS();
    return status;
}

#endif // CXX_MEMORY_UNIT_TEST
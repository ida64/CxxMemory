#ifdef CXX_MEMORY_UNIT_TEST

#include <gtest/gtest.h>

#include "UniquePointer.h"

namespace cxx_memory
{
    TEST(cxx_memory, UniquePointer)
    {
        UniquePointer<int> uniquePointer(new int(10));

        EXPECT_EQ(*uniquePointer.GetValue(), 10);

        UniquePointer<int> uniquePointer2 = std::move(uniquePointer);
        EXPECT_EQ(*uniquePointer2.GetValue(), 10);

        EXPECT_EQ(uniquePointer.GetValue(), nullptr);
    }

} // namespace cxx_memory

#endif // CXX_MEMORY_UNIT_TEST
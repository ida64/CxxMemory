#ifdef CXX_MEMORY_UNIT_TEST

#include <gtest/gtest.h>

#include <SharedPointer.h>

namespace cxx_memory
{
    TEST(cxx_memory, SharedPointer)
    {
        SharedPointer<int> p1(new int(1));
        SharedPointer<int> p2(p1);
        SharedPointer<int> p3(new int(2));
        p3 = p2;
        EXPECT_EQ(p1.GetUseCount(), 3);
        EXPECT_EQ(p2.GetUseCount(), 3);
        EXPECT_EQ(p3.GetUseCount(), 3);
        EXPECT_EQ(*p1, 1);
        EXPECT_EQ(*p2, 1);
        EXPECT_EQ(*p3, 1);
    }

} // namespace cxx_memory

#endif // CXX_MEMORY_UNIT_TEST
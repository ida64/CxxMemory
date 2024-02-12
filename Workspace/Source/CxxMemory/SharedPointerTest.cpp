#ifdef CXX_MEMORY_UNIT_TEST

#include <gtest/gtest.h>

#include <CxxMemory/SharedPointer.h>

namespace cxx_memory
{
    TEST(cxx_memory, SharedPointer)
    {
        SharedPointer<int> p1(new int(1));
        SharedPointer<int> p2(p1);
        SharedPointer<int> p3(new int(2));
        
        p3 = p2;

        EXPECT_EQ(p1.GetReferenceCount(), 3);
        EXPECT_EQ(p2.GetReferenceCount(), 3);
        EXPECT_EQ(p3.GetReferenceCount(), 3);
        
        EXPECT_EQ(*p1, 1);
        EXPECT_EQ(*p2, 1);
        EXPECT_EQ(*p3, 1);
    }

    TEST(cxx_memory, MakeSharedPointer)
    {
        struct Foo
        {
            Foo(int value) : value(value) {}
            int value;

        }; // struct Foo

        auto p = MakeSharedPointer<Foo>(1);

        EXPECT_EQ(p.GetReferenceCount(), 1);
        EXPECT_EQ(p->value, 1);
    }

} // namespace cxx_memory

#endif // CXX_MEMORY_UNIT_TEST
#include "pch.h"
#include "Header.h"

////////////////////////////// Q1///////////////////////////
TEST(List, insert) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    ASSERT_EQ(false, obj1.insert(6));
    obj1.print();

}

TEST(List, insertat) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1)); //0
    ASSERT_EQ(true, obj1.insert(2)); //1
    ASSERT_EQ(true, obj1.insert(3)); //2
    ASSERT_EQ(true, obj1.insert(4)); //3

    bool f = obj1.insertAt(3, 1);
    EXPECT_EQ(3, obj1.ptr[1]);
    obj1.print();

}

TEST(List, insertafter) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));

    obj1.insertAfter(5, 4);
    EXPECT_EQ(5, obj1.ptr[4]);
    obj1.print();

}

TEST(List, insertbefore) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(5));

    obj1.insertBefore(4, 5);
    EXPECT_EQ(4, obj1.ptr[3]);
    obj1.print();

}


TEST(List, remove) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2)); //1
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    obj1.remove(1);
    int j = 2;
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(j++, obj1.ptr[i]);
        //cout << obj1.ptr[i] << endl;
    }
    obj1.print();
}

TEST(List, removeafter) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    obj1.removeAfter(3);
    EXPECT_EQ(5, obj1.ptr[3]);
    obj1.print();
}

TEST(List, removebefore) {
    List<int> obj1(4);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));

    obj1.removeBefore(3);
    EXPECT_EQ(3, obj1.ptr[1]);
    obj1.print();
}
TEST(List, ComparisonOperator) {
    List<int> obj1(4);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));

    List<int> obj2(4);
    ASSERT_EQ(true, obj2.insert(1));
    ASSERT_EQ(true, obj2.insert(2));
    ASSERT_EQ(true, obj2.insert(3));
    ASSERT_EQ(true, obj2.insert(4));

    List<int> obj3(4);
    ASSERT_EQ(true, obj3.insert(1));
    ASSERT_EQ(true, obj3.insert(5));
    ASSERT_EQ(true, obj3.insert(6));
    ASSERT_EQ(true, obj3.insert(9));

    ASSERT_EQ(true, obj1 == obj2);
    ASSERT_EQ(false, obj2 == obj3);

}

TEST(List, reverse) {
    List<int> obj1(5);
    ASSERT_EQ(true, obj1.insert(1));
    ASSERT_EQ(true, obj1.insert(2));
    ASSERT_EQ(true, obj1.insert(3));
    ASSERT_EQ(true, obj1.insert(4));
    ASSERT_EQ(true, obj1.insert(5));
    obj1.reverse();
    int j = 5;
    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(j--, obj1.ptr[i]);
    }
    obj1.print();
}

//---------------------------------------------------
//Q- 2


TEST(SafeArrayTest, WithinBounds) 
{
    safeArray list(2, 13);
    safeArray yourList(-5, 9);

    list[2] = 10;
    EXPECT_EQ(list[2], 10);

    yourList[-5] = 20;
    EXPECT_EQ(yourList[-5], 20);
}

TEST(SafeArrayTest, OutOfBounds) {
    safeArray list(2, 13);

    // Use ASSERT_THROW to check if out-of-bounds access throws an exception
    ASSERT_THROW({
        std::cout << list[1] << std::endl;
        }, std::out_of_range);
}
/*

*/



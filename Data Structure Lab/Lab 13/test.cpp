#include "pch.h"
#include <gtest/gtest.h>
#include "header.h"
// Include the HashMap and HashEntry classes here...

TEST(HashMapTest, InsertAndSearch)
{
    HashMap hashMap;
    hashMap.Insert(1, 42);
    hashMap.Insert(2, 69);

    EXPECT_EQ(hashMap.Search(1), 42);
    EXPECT_EQ(hashMap.Search(2), 69);
    EXPECT_EQ(hashMap.Search(3), -1); // Key 3 is not inserted, so it should return -1
}

TEST(HashMapTest, Remove)
{
    HashMap hashMap;
    hashMap.Insert(1, 42);
    hashMap.Insert(2, 69);

    hashMap.Remove(1);
    EXPECT_EQ(hashMap.Search(1), -1); // Key 1 should not be found after removal
    EXPECT_EQ(hashMap.Search(2), 69);

    // Remove non-existing key
    hashMap.Remove(3);
    EXPECT_EQ(hashMap.Search(2), 69); // The hash table should remain unchanged
}

TEST(HashMapTest, InsertWithRandomProbe)
{
    HashMap hashMap;

    // Insert elements with random probing
    hashMap.Insert2(1, 42);
    hashMap.Insert2(2, 69);
    hashMap.Insert2(3, 99);

    // Check that the inserted elements can be found

    // Insert an element with the same key, should update the value
    hashMap.Insert2(1, 55);
 

    // Attempting to insert more elements should not trigger an error message
    ::testing::internal::CaptureStderr();
    hashMap.Insert2(4, 77);
    std::string errorMessage = ::testing::internal::GetCapturedStderr();
    EXPECT_EQ(errorMessage, "");  // No error message expected
}
/*
*/
int main()
{
    HashMap arr;
    arr.Insert3(1, 10);
    arr.Insert3(2, 20);
    arr.Insert3(3, 60);

    arr.Insert3(2, 50);
    arr.Insert3(2, 10);
    arr.Insert3(2, 70);
    
}
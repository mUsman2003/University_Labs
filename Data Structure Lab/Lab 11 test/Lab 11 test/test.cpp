#include "pch.h"
#include "header.h"

TEST(TestCaseName, Insertion) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    // Test whether elements are correctly inserted
    EXPECT_TRUE(bst.search(50));
    EXPECT_TRUE(bst.search(30));
    EXPECT_TRUE(bst.search(20));
    EXPECT_TRUE(bst.search(40));
    EXPECT_TRUE(bst.search(70));
    EXPECT_TRUE(bst.search(60));
    EXPECT_TRUE(bst.search(80));
    
}

TEST(TestCaseName, Search) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Test search functionality
    EXPECT_TRUE(bst.search(60));
    EXPECT_FALSE(bst.search(90));
}
TEST(TestCaseName, Deletion) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    bst.insert(45);
    bst.insert(35);
    bst.insert(19);


    // Remove an element from the BST
    bst.remove(20);


    // Test whether elements are correctly removed
    EXPECT_FALSE(bst.search(20));
    EXPECT_TRUE(bst.search(30));
    EXPECT_TRUE(bst.search(70));
    EXPECT_TRUE(bst.search(50));
    EXPECT_TRUE(bst.search(40));
    EXPECT_TRUE(bst.search(60));
    EXPECT_TRUE(bst.search(80));
}

TEST(TestCaseName, Traversals) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Test pre-order traversal
    testing::internal::CaptureStdout();
    bst.preOrderTraversal();
    string preOrderOutput = testing::internal::GetCapturedStdout();
    string expectedPreOrder = "50 30 20 40 70 60 80 \n";
    EXPECT_EQ(preOrderOutput, expectedPreOrder);

    // Test post-order traversal
    testing::internal::CaptureStdout();
    bst.postOrderTraversal();
    string postOrderOutput = testing::internal::GetCapturedStdout();
    string expectedPostOrder = "20 40 30 60 80 70 50 \n";
    EXPECT_EQ(postOrderOutput, expectedPostOrder);
}

TEST(TestCaseName, Deletion2) {
    BST<int> bst;

    // Insert elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Remove nodes 30 and 70 from the BST
    bst.remove(30);
    bst.remove(70);

    // Test post-order traversal after deletion
    testing::internal::CaptureStdout();
    bst.postOrderTraversal();
    string postOrderOutput = testing::internal::GetCapturedStdout();
    string expectedPostOrder = "20 40 60 80 50 \n";
    EXPECT_EQ(postOrderOutput, expectedPostOrder);
}

TEST(TestCaseName, LevelWiseTraversal) {
    BST<int> bst;
    // Insert elements into the BST
    bst.insert(70);
    bst.insert(16);
    bst.insert(90);
    bst.insert(15);
    bst.insert(48);
    bst.insert(80);
    bst.insert(85);
    bst.insert(40);
    bst.insert(10);
    EXPECT_EQ(bst.LeafCount(), 3);
}

TEST(TestCaseName, LevelWiseTraversal2) {
    BST<int> bst;
    // Insert elements into the BST
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    EXPECT_EQ(bst.LeafCount(), 4);
}

/*
*/
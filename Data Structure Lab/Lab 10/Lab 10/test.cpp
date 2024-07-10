#include "pch.h"
#include "header.h"

TEST(BinaryTreeTest, InOrderTraversal) {
    BinaryTree tree;

    // Insert elements into the binary tree
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    // Check if the in-order traversal is correct
    testing::internal::CaptureStdout();
    tree.displayInorder();
    std::string output = testing::internal::GetCapturedStdout();

    // The expected output based on in-order traversal
    std::string expected_output = "1 2 3 4 5 6 7 ";

    ASSERT_EQ(output, expected_output);
}
/*
*/
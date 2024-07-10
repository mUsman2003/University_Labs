#include "pch.h"
#include "header.h"

// Include your AVLTree class definition and implementation here...
// Helper function to check if a tree is sorted
bool isSorted(AVLNode* node, int minValue, int maxValue) {
    if (node == nullptr) {
        return true;
    }

    if (node->data < minValue || node->data > maxValue) {
        return false;
    }

    return isSorted(node->left, minValue, node->data - 1) && isSorted(node->right, node->data + 1, maxValue);
}

class AVLTreeTest : public ::testing::Test
{
protected:
    AVLTree avlTree;
      
    void insertElements()
    {
        avlTree.insert(10);
        avlTree.insert(20);
        avlTree.insert(30);
        avlTree.insert(40);
        avlTree.insert(50);
        avlTree.insert(25);
    }

    AVLTree avlTree2;

    void insertElements2()
    {
        avlTree2.insert(1);
        avlTree2.insert(2);
        avlTree2.insert(2);
        avlTree2.insert(3);
        avlTree2.insert(4);
        avlTree2.insert(4);
        avlTree2.insert(3);
    }
};

// Test AVL tree insertion
TEST_F(AVLTreeTest, Insertion)
{
    insertElements();
    
    // Display the AVL tree after insertion
    testing::internal::CaptureStdout();
    avlTree.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "In-order traversal: 10 20 25 30 40 50 \n");
    
}

// Test AVL tree deletion
TEST_F(AVLTreeTest, Deletion)
{
    insertElements();

    // Remove elements
    avlTree.remove(30);
    avlTree.remove(40);

    // Display the AVL tree after deletion
    testing::internal::CaptureStdout();
    avlTree.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "In-order traversal: 10 20 25 50 \n");
}

// Test AVL tree in-order traversal
TEST_F(AVLTreeTest, InOrderTraversal)
{
    insertElements();

    // Display the AVL tree using in-order traversal
    testing::internal::CaptureStdout();
    avlTree.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "In-order traversal: 10 20 25 30 40 50 \n");
    
}

// Add more test cases as needed
// Test AVL tree getDiameter function
TEST_F(AVLTreeTest, GetDiameter)
{
    // Construct a tree
    insertElements();

    // Calculate the diameter
    int diameter = avlTree.getDiameter();

    // Expected diameter for the given tree
    int expectedDiameter = 4;

    EXPECT_EQ(diameter, expectedDiameter);
}

// Include your AVLTree class definition and implementation here...

TEST(SplitTreeTest, BasicSplit) {
    AVLTree avlTree;

    // Insert keys into the AVL tree
    avlTree.insert(30);
    avlTree.insert(20);
    avlTree.insert(40);
    avlTree.insert(10);
    avlTree.insert(25);
    //avlTree.display();

    // Threshold value for splitting
    int threshold = 30;

    // Create two AVL trees to store the split results
    AVLTree treeA;
    AVLTree treeB;

    // Split the AVL tree into TreeA and TreeB
    avlTree.splitTree(threshold, treeA, treeB);

    // Check if both resulting trees have a valid balance factor
    ASSERT_TRUE(avlTree.getBalanceFactor(avlTree.getRoot()) >= -1 && avlTree.getBalanceFactor(avlTree.getRoot()) <= 1);
    ASSERT_TRUE(treeA.getBalanceFactor(treeA.getRoot()) >= -1 && treeA.getBalanceFactor(treeA.getRoot()) <= 1);
    ASSERT_TRUE(treeB.getBalanceFactor(treeB.getRoot()) >= -1 && treeB.getBalanceFactor(treeB.getRoot()) <= 1);
    // Check if TreeA contains keys less than or equal to the threshold
    ASSERT_TRUE(isSorted(treeA.getRoot(), INT_MIN, threshold));

    // Check if TreeB contains keys greater than the threshold
    ASSERT_TRUE(isSorted(treeB.getRoot(), threshold + 1, INT_MAX));
}

// Additional test cases can be added as needed...
/*
*/
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


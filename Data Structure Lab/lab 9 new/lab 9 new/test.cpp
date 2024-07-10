#include"pch.h"
#include<iostream>
#include "header.h"
using namespace std;

// Question 1
TEST(StackTest, EmptyStack) {
    Stack<int> intStack;
    EXPECT_TRUE(intStack.isEmpty());
}
TEST(StackTest, PushAndPop) {
    Stack<int> intStack;
    intStack.push(42);
    EXPECT_FALSE(intStack.isEmpty());
    EXPECT_EQ(intStack.peek(), 42);

    intStack.pop();
    EXPECT_TRUE(intStack.isEmpty());
}

TEST(StackTest, ClearStack) {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    intStack.clear();
    EXPECT_TRUE(intStack.isEmpty());
}

/*
TEST(StackSortTest, SortsInAscendingOrder) {
    Stack<int> stack;
    stack.push(5);
    stack.push(2);
    stack.push(4);
    stack.push(1);
    stack.push(3);

    sortStack(stack);

    // Check if the stack is sorted in ascending order.
    EXPECT_EQ(stack.peek(), 1);
    stack.pop();
    EXPECT_EQ(stack.peek(), 2);
    stack.pop();
    EXPECT_EQ(stack.peek(), 3);
    stack.pop();
    EXPECT_EQ(stack.peek(), 4);
    stack.pop();
    EXPECT_EQ(stack.peek(), 5);
    stack.pop();
}
*/

// Question 2
TEST(IsValidTest, ValidCases)
{
    EXPECT_TRUE(isValid("()"));
    EXPECT_TRUE(isValid("()[]{}"));
    EXPECT_TRUE(isValid("{[()]}"));
    EXPECT_TRUE(isValid("({})"));
    EXPECT_TRUE(isValid("[{}]"));
    EXPECT_TRUE(isValid(""));
}

TEST(IsValidTest, InvalidCases)
{
    EXPECT_FALSE(isValid("(]"));
    EXPECT_FALSE(isValid("([)]"));
    EXPECT_FALSE(isValid("{[}]"));
    EXPECT_FALSE(isValid("{{"));
    EXPECT_FALSE(isValid("]"));
    EXPECT_FALSE(isValid("}"));
}


// Question-3



TEST(MazeSolverTest, PathFoundTest) {
    int maze[N][M] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1 },
        { 1, 1, 1, 1, 1 }
    };
    int fx = 2;
    int fy = 3;

    bool result = isReachable(maze,fx,fy);
    ASSERT_TRUE(result) << "Path should be found";
}

TEST(MazeSolverTest, NoPathFoundTest) {
    int maze[N][M] = {
        { 1, 0, 1, 1, 0 },
        { 1, 1, 0, 0, 1 },  // No valid path to (2, 3)
        { 1, 1, 0, 1, 1 },
        { 1, 0, 1, 1, 1 }
    };
    int fx = 2;
    int fy = 3;

    bool result = isReachable(maze,fx,fy);
    ASSERT_FALSE(result) << "No valid path should be found";
}

/*
*/
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
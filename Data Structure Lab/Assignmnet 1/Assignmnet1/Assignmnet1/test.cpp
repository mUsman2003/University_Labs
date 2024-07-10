#include <gtest/gtest.h>
#include "pch.h"
#include "source.h" // Include the actual implementation

//******************************************************
//***************** Question 1 *************************
//******************************************************

template<class T>
bool isSortedDescending(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] < arr[i]) {
            return false; // If any adjacent elements are out of order, return false.
        }
    }
    return true; // If all elements are in descending order, return true.
}

TEST(Array, Test1a) {
    float A[] = { 4.5, 10.2, 8.1 ,7.4, 2, 1, 0 };
    float result = ArrayBasics<float>::findMax(A, 0, 3);
    EXPECT_EQ(result, 10.2f);
}

TEST(Array, Test1b) {
    float A[] = { 8, 1, 3, 4.1, 5.1, 2.3, 0 };
    int result = ArrayBasics<float>::findMaxPos(A, 0, 2);
    EXPECT_EQ(result, 0);
}

TEST(Array, Test1c) {
    int A[] = { 3, 1, 4, 1, 5, 9, -1, 6, 5, 3 };
    int result = ArrayBasics<int>::findMin(A, 5, 9);
    EXPECT_EQ(result, -1);
}

TEST(Array, Test1d) {
    int A[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, -10 };
    int result = ArrayBasics<int>::findMinPos(A, 6, 9);
    EXPECT_EQ(result, 9); // Position of the minimum value (1) is 3.
}

TEST(Array, Test1e) {
    int A[] = { 0, 1, 4, 0, 5 };
    ArrayBasics<int>::swap(A, 1, 3);
    EXPECT_EQ(A[1], 0); // After swapping, A[1] should be 1.
    EXPECT_EQ(A[3], 1); // After swapping, A[3] should be 1.
}

TEST(Array, Test1f) {
    int* A = ArrayBasics<int>::createRandomArray(30, 25, 75);
    // Check if the array has the correct size and values within the specified range.
    for (int i = 0; i < 30; ++i) {
        EXPECT_GE(A[i], 25); // Values should be greater than or equal to 1.
        EXPECT_LE(A[i], 75); // Values should be less than or equal to 100.
    }
    delete[] A;
}

TEST(Array, Test1g) {
    int** matrix = ArrayBasics<int>::createRandomMatrix(10, 10, 25, 75);
    // Check if the matrix has the correct dimensions and values within the specified range.
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            EXPECT_GE(matrix[i][j], 25); // Values should be greater than or equal to 1.
            EXPECT_LE(matrix[i][j], 75); // Values should be less than or equal to 100.
        }
        delete[] matrix[i]; // Clean up inner arrays.
    }
    delete[] matrix; // Clean up the outer array.
}

TEST(Array, Test1h) {
    float A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(A) / sizeof(A[0]);
    float* copy = ArrayBasics<float>::copyArray(A, size);
    // Check if the copied array is equal to the original.
    for (int i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], A[i]);
    }
    delete[] copy;
}

TEST(Array, Test1i) {
    int rows = 3, cols = 4;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j;
        }
    }

    int** copy = ArrayBasics<int>::copyMatrix(matrix, rows, cols);
    // Check if the copied matrix is equal to the original.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            EXPECT_EQ(copy[i][j], matrix[i][j]);
        }
        delete[] copy[i]; // Clean up inner arrays.
    }
    delete[] copy; // Clean up the outer array.

    // Clean up the original matrix.
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

TEST(Array, Test1j) {
    float A[] = { 1, 2, 3, 4, 5.1, 6.5, 7.9, 8, 0 };
    int size = sizeof(A) / sizeof(A[0]);
    int result = ArrayBasics<float>::findInArray(A, 7.9f, size);
    EXPECT_EQ(result, 6);
}

TEST(Array, Test1k) {
    int A[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(A) / sizeof(A[0]);
    int result = ArrayBasics<int>::findInSortedArray(A, 1, size);
    EXPECT_EQ(result, 0); // Position of 3 in A is 2.
}

TEST(Array, Test1l) {
    float A[] = { 1, 2, 2, 3.3, 3.3, 3.3, 4, 4.5, 4.9, 5 };
    int size = sizeof(A) / sizeof(A[0]);
    int result = ArrayBasics<float>::findFirstInSortedArray(A, 4.9f, size);
    EXPECT_EQ(result, 8);
}

TEST(ArrayUtilityTest, Test1m) {
    float A[] = { 1.2, 2.3, 2.1, 2.0, 4.6, 4.5, 4.2, 4.8, 6.8, 6.7, 1.1, 0, -6.5, -8.9 };
    int size = sizeof(A) / sizeof(A[0]);

    ArrayUtility<float>::maxSortWithShiftRight(A, size);

    // Check if the array is sorted in descending order.
    EXPECT_TRUE(isSortedDescending(A, size));
}

TEST(ArrayUtilityTest, Test1n) {
    float A[] = { 1.2, 2.3, 2.1, 2.0, 4.6, 4.5, 4.2, 4.8, 6.8, 6.7, 1.1, 0, -6.5, -8.9 };
    int size = sizeof(A) / sizeof(A[0]);

    ArrayUtility<float>::maxSortWithSwap(A, size);

    // Check if the array is sorted in descending order.
    EXPECT_TRUE(isSortedDescending<float>(A, size));
}

//******************************************************
//***************** Question 2 *************************
//******************************************************

TEST(WarehouseAlgorithmTest, Test2a) {
    int B[] = { 3, 5, 2, 8, 10, 1, 7, 11, 12, 13, 14, 16, 18, 17, 19, 20, 21, 22, 23, 24, 25, 26, 28, 30, 32, 36, 35, 38, 39, 40, 42, 45, 46, 48, 50, 51, 52, 53, 54, 55, 57, 58, 60 };
    int n = sizeof(B) / sizeof(B[0]);
    int r = 58;
    EXPECT_TRUE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}

TEST(WarehouseAlgorithmTest, Test2b) {
    int B[] = { 3, 8, 2, 4, 0, 19, 18, 16, 14, 13, 20, 22, 24, 25, 27, 28, 29, 30, 31, 33, 34, 36, 38, 39, 40, 50, 60, 70 };
    int n = sizeof(B) / sizeof(B[0]);
    int r = 6;
    EXPECT_TRUE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}
//---------------------------------------------------------------------------------
TEST(WarehouseAlgorithmTest, Test2c) {
    int B[] = { 3, 5, 2, 8, 0, 19, 18, 16, 14, 13, 80, 67 };
    int n = sizeof(B) / sizeof(B[0]);
    int r = 10;
    EXPECT_FALSE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}

TEST(WarehouseAlgorithmTest, Test2d) {
    int B[] = { 3, 5, 2, 8, 10, 1, 7, 11, 12, 13, 14, 16, 18, 17, 19, 20, 21, 22, 23, 24, 25, 26, 28, 30, 32, 36, 35, 38, 39, 40, 42, 45, 46, 48, 50, 51, 52, 53, 54, 55, 57, 58, 60 };
    int n = sizeof(B) / sizeof(B[0]);
    int r = 21;
    EXPECT_TRUE(WarehouseAlgorithm<int>::hasClosePair(B, n, r));
}

//******************************************************
//***************** Question 3 *************************
//******************************************************

TEST(MaximizeProfitTest, Test3a) {
    int m = 10;
    int n = 5;
    int a[] = { 2, 3, 1, 4, 5 };
    int p[] = { 60, 30, 10, 40, 50 };
    int s = 0;

    int result = maximizeProfit<int>(m, n, a, p, s);

    EXPECT_EQ(result, 140);
}

TEST(MaximizeProfitTest, Test3b) {
    int m = 20;
    int n = 5;
    int a[] = { 2, 3, 1, 4, 5 };
    int p[] = { 20, 30, 10, 40, 50 };
    int s = 5;

    int result = maximizeProfit<int>(m, n, a, p, s);

    EXPECT_EQ(result, 125);
}

TEST(MaximizeProfitTest, Test3c) {
    int m = 15;
    int n = 5;
    int a[] = { 2, 3, 1, 4, 5 };
    int p[] = { 20, 30, 10, 40, 50 };
    int s = 10;

    int result = maximizeProfit<int>(m, n, a, p, s);

    EXPECT_EQ(result, 150);
    // Orders selected: {3, 4, 5}
}

TEST(MaximizeProfitTest, Test3d) {
    int m = 18;
    int n = 5;
    int a[] = { 5, 10, 15, 20, 25, 30 };
    int p[] = { 20, 20, 30, 40, 50, 60 };
    int s = 2;

    int result = maximizeProfit<int>(m, n, a, p, s);

    EXPECT_EQ(result, 34);
}

TEST(MaximizeProfitTest, Test3e) {
    int m = 0;
    int n = 5;
    int a[] = { 2, 3, 1, 4, 5 };
    int p[] = { 20, 30, 10, 40, 50 };
    int s = 0;

    int result = maximizeProfit<int>(m, n, a, p, s);

    EXPECT_EQ(result, 0);
    // Orders selected: {3, 4, 5}
}

//******************************************************
//***************** Question 4 *************************
//******************************************************

TEST(BookingScheduleTest, Test4a) {
    int R1[][2] = {
        {3, 5},
        {3, 8},
        {10,12}
    };
    int n1 = sizeof(R1) / sizeof(R1[0]);

    int R2[][2] = {
        {2, 4},
        {0, 6}
    };
    int n2 = sizeof(R2) / sizeof(R2[0]);

    int mergedSchedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    mergeBookingSchedules<int>(R1, n1, R2, n2, mergedSchedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = {
        {1, 0, 2},
        {2, 2, 3},
        {4, 3, 4},
        {3, 4, 5},
        {2, 5, 6},
        {1, 6, 8},
        {1, 10, 12}
    };

    // Check if the merged schedule matches the expected schedule

    ASSERT_EQ(m, 7);


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(mergedSchedule[i][j], expectedSchedule[i][j]);
        }
    }
}

TEST(BookingScheduleTest, Test4b) {
    int R[][2] = {
        {0, 2},
        {4, 6},
        {1, 7},
        {8, 9},
        {4, 10}
    };
    int n1 = sizeof(R) / sizeof(R[0]);

    int Schedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    makeBookingSchedules<int>(R, n1, Schedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = {
        {1, 0, 1},
        {2, 1, 2},
        {1, 2, 4},
        {3, 4, 6},
        {2, 6, 7},
        {1, 7, 8},
        {2, 8, 9},
        {1, 9, 10}
    };

    ASSERT_EQ(m, 8);

    // Check if the merged schedule matches the expected schedule
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(Schedule[i][j], expectedSchedule[i][j]);
        }
    }
}

TEST(BookingScheduleTest, Test4c) {
    int R1[][2] = {
        {1, 8},
        {2, 7}
    };
    int n1 = sizeof(R1) / sizeof(R1[0]);

    int R2[][2] = {
        {3, 6},
        {4, 5}
    };
    int n2 = sizeof(R2) / sizeof(R2[0]);

    int mergedSchedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    mergeBookingSchedules<int>(R1, n1, R2, n2, mergedSchedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = {
        {1, 1, 2},
        {2, 2, 3},
        {3, 3, 4},
        {4, 4, 5},
        {3, 5, 6},
        {2, 6, 7},
        {1, 7, 8}
    };

    ASSERT_EQ(m, 7);


    // Check if the merged schedule matches the expected schedule
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(mergedSchedule[i][j], expectedSchedule[i][j]);
        }
    }
}

TEST(BookingScheduleTest, Test4d) {
    int R[][2] = {
        {0, 2},
        {1, 3},
        {1, 5},
        {2, 5},
        {6, 11},
        {7, 11},
        {8, 11}
    };
    int n1 = sizeof(R) / sizeof(R[0]);

    int Schedule[50][3]; // Assuming a maximum of 50 bookings
    int m;

    makeBookingSchedules<int>(R, n1, Schedule, m);

    // Define the expected merged schedule (B)
    int expectedSchedule[][3] = {
        {1, 0, 1},
        {3, 1, 2},
        {3, 2, 3},
        {2, 3, 5},
        {1, 6, 7},
        {2, 7, 8},
        {3, 8, 11}
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cout << Schedule[i][j] << " ";
        }
        cout << endl;
    }
    ASSERT_EQ(m, 7);



    // Check if the merged schedule matches the expected schedule
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQ(Schedule[i][j], expectedSchedule[i][j]);
        }
    }
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


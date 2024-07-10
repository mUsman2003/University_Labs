#include "pch.h"
#include "source.h"
#include <cstring>

TEST(StudentSortTest, SortingTest) {
    StudentRecord students[] = {
        {101, "Alice", 3.8},
        {102, "Bob", 3.6},
        {103, "Charlie", 3.9},
        {104, "David", 3.5},
        {105, "Eve", 4.0}
    };

    int size = sizeof(students) / sizeof(students[0]);

    insertionSortStudents(students, size);

    // Check if the students are sorted by GPA in non-decreasing order

    for (int i = 1; i < size; ++i) {
        ASSERT_LE(students[i - 1].GPA, students[i].GPA);
    }
}



TEST(QuickSortTest, SortingTest) {
    EmployeeRecord employees[] = {
        {101, "Alice", 3000.0},
        {102, "Bob", 2500.0},
        {103, "Charlie", 3500.0},
        {104, "David", 2800.0},
        {105, "Eve", 3200.0}
    };

    int size = sizeof(employees) / sizeof(employees[0]);

    iterativeQuickSortEmployees(employees, size);

    // Check if the employees are sorted by salary in non-decreasing order
    for (int i = 1; i < size; ++i) {
        ASSERT_LE(employees[i - 1].salary, employees[i].salary);
    }
}

TEST(QuickSortTest, AlreadySortedTest) {
    EmployeeRecord employees[] = {
        {101, "Alice", 2500.0},
        {102, "Bob", 2800.0},
        {103, "Charlie", 3000.0},
        {104, "David", 3200.0},
        {105, "Eve", 3500.0}
    };

    int size = sizeof(employees) / sizeof(employees[0]);

    iterativeQuickSortEmployees(employees, size);

    // Check if the employees are still sorted by salary in non-decreasing order
    for (int i = 1; i < size; ++i) {
        ASSERT_LE(employees[i - 1].salary, employees[i].salary);
    }
}
/*

*/
TEST(GradeSortSearchTest, BubbleSortAndBinarySearchTest) {
    int studentGrades[] = { 88, 76, 92, 95, 85, 78, 89, 91, 87 };
    int numStudents = sizeof(studentGrades) / sizeof(studentGrades[0]);

    // Sort the student grades using bubble sort
    bubbleSort(studentGrades, numStudents);

    // Perform binary searches
    int grade102 = binarySearch(studentGrades, numStudents, 102);
    int grade91 = binarySearch(studentGrades, numStudents, 91);
    int grade77 = binarySearch(studentGrades, numStudents, 77);

    // Check the results of binary searches
    ASSERT_EQ(grade102, -1); // Student ID 102 not found
    ASSERT_EQ(grade91, 91);  // Student ID 91 found with grade 91
    ASSERT_EQ(grade77, -1);  // Student ID 77 not found
}
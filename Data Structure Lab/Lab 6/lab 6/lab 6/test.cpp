#include "pch.h"
#include "header.h"
TEST(Insert, T1) {
    SLinkedList<int> obj;
    int arr[] = { 0,1,2,3,4,5,6,7 };
    for (int i = 0; i < 8; i++)
    {
        obj.insert(arr[i]);
    }
    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(arr[i], temp->data);
        temp = temp->next;
        i++;
    }

}

TEST(InsertatHead, T2) {
    SLinkedList<int> obj;
    int arr[] = { 0,1,2,3,4 };
    for (int i = 0; i < 5; i++)
    {
        obj.insert(arr[i]);
    }

    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr[i]);
        temp = temp->next;
        i++;
    }
    temp = obj.head;
    obj.insertAtHead(66);
    EXPECT_EQ(66, obj.head->data);
    temp = obj.head->next;
    int j = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr[j]);
        temp = temp->next;
        j++;
    }
}

TEST(InsertAtIndex, T3) {
    int arr[] = { 0, 1, 2, 3 };
    SLinkedList<int> obj1;
    for (int i = 0; i < 4; i++)
    {
        obj1.insert(arr[i]);
    }

    obj1.InsertAtIndex(5, 4); // InsertAtIndex(5 is the value to be inserted, 4 is the Index.no);

    Node<int>* temp = obj1.head;
    int j = 0;

    while (temp->next != nullptr) {
        EXPECT_EQ(temp->data, arr[j]);
        temp = temp->next;
        j++;
    }
}

TEST(Search, T4) {

    SLinkedList<int> obj1;
    for (int i = 0; i < 3; i++)
    {
        obj1.insert(i);
    }
    EXPECT_EQ(2, obj1.search(2));
    ASSERT_NE(3, obj1.search(2));
}


TEST(Update, T5) {
    SLinkedList<int> obj;
    for (int i = 0; i < 5; i++)
    {

        obj.insert(i);
    }
    obj.update(3, 67);
    obj.print();
    Node<int>* temp = obj.head;
    int i = 0;
    int arr[] = { 0,1,2,67,4 };
    while (temp->next != NULL) {
        EXPECT_EQ(arr[i], temp->data);
        temp = temp->next;
        i++;
    }

}
TEST(Delete, T6) {
    SLinkedList<int> obj;

    for (int i = 0; i < 5; i++)
    {
        obj.insert(i);
    }
    obj.remove(3);
    int arr[] = { 0,1,2,4 };
    obj.print();
    Node<int>* temp = obj.head;
    int i = 0;
    while (temp->next != NULL) {
        EXPECT_EQ(temp->data, arr[i]);
        temp = temp->next;
        i++;
    }
}

//Task Two test cases :

TEST(SwapAdjacentNodes, T1) {
    SLinkedList<int> obj;
    int arr[] = { 0, 3, 1, 2, 2, 0 };

    // Create the linked list from the given array.
    for (int i = 0; i < 6; i++) {
        obj.insert(arr[i]);
    }

    // Call the function to swap adjacent nodes.
    obj.head = swapAdjacentNodes(obj.head);

    // Verify the modified list.
    int expected[] = { 3, 0, 2, 1, 0, 2 };
    Node<int>* temp = obj.head;
    int i = 0;

    while (temp != nullptr) {
        EXPECT_EQ(expected[i], temp->data);
        temp = temp->next;
        i++;
    }
    obj.print();
}

TEST(SwapAdjacentNodes, T2) {
    SLinkedList<int> obj;
    int arr[] = { 0, 1, 2, 3 };

    // Create the linked list from the given array.
    for (int i = 0; i < 4; i++) {
        obj.insert(arr[i]);
    }

    // Call the function to swap adjacent nodes.
    obj.head = swapAdjacentNodes(obj.head);

    // Verify the modified list.
    int expected[] = { 1, 0, 3, 2 };
    Node<int>* temp = obj.head;
    int i = 0;

    while (temp != nullptr) {
        EXPECT_EQ(expected[i], temp->data);
        temp = temp->next;
        i++;
    }
}
/*
*/


#include <iostream>
#include "node.h"
#include "supplementarySearchingAlgo.h"

int main() {

    int list1[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size1 = sizeof(list1) / sizeof(list1[0]);

    Node<int>* head = new_node(list1[0]);
    Node<int>* temp = head;
    for (int i = 1; i < size1; i++) {
        temp->next = new_node(list1[i]);
        temp = temp->next;
    }

    //Problem 1

    std::cout << "Array approach: ";
    linearSearchArrCount(size1, 18, list1);

    std::cout << "Linked list approach: ";
    linearSearchLLCount(head, 18);

    //Problem 2
    std::cout << "Array approach: ";
    countRepeatArr(size1, 18, list1);

    std::cout << "Linked list approach: ";
    countRepeatLL(head, 18);

    //Problem 3
    int list2[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size2 = sizeof(list2) / sizeof(list2[0]);

    binarySearchArr(size2, 8, list2);

    //Problem 4
    std::cout << std::endl;
    binarySearchArrRecursive(list2, 0, size2 - 1, 8);



    Node<int>* curr = head;
    while (curr != nullptr) {
        Node<int>* next = curr->next;
        delete curr;
        curr = next;
    }
}
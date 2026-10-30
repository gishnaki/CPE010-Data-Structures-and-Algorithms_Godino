#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

#include <iostream>
#include "node.h"

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]) {

    // Step 1: I := 0
    int i = 0;

    // Repeat while I <= n
    while (i < arrSize) {

        // If (item = data[i])
        if (dataFind == list[i]) {

            // Print "Searching is successful"
            std::cout << "Searching is successful. \n";
            return;
        }

        i++;
    }

    // Print "Searching is Unsuccessful"
    std::cout << "Searching is unsuccessful." << std::endl;
}

template <typename T>
void linearSearchLL(Node<T>* head, T dataFind) {

    while (head != nullptr) {

        if (head->data == dataFind) {
            std::cout << "Searching is successful.\n";
            return;
        }

        head = head->next;
    }

    std::cout << "Searching is unsuccessful." << std::endl;
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]) {

    // Define low, high, and middle
    int low = 0, up = arrSize - 1, middle;

    // Loop while low is less than or equal to high
    while (low <= up) {

        // Compute for middle
        middle = (int)((low + up) / 2);

        // If data found is middle -> data found -> return
        if (dataFind == list[middle]) {
            std::cout << "Searching is successful.\n";
            return;
        }

        // If data find < data middle -> new high
        else if (dataFind < list[middle]) {
            up = middle - 1;
        }

        else {

            // Else update low = middle + 1
            low = middle + 1;
        }
    }

    // Search is not found
    std::cout << "Searching is unsuccessful.\n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) {

    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != last && fast->next != last) {

        // Move slow one step
        slow = slow->next;

        // Move fast two steps
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {

    // Step 1: Set start to the head of the list, set last to null
    Node<T>* last = nullptr;

    // Continue searching while the search range is valid (not yet last)
    while (start != last) {

        // Step 2: Find the middle node using getMiddle()
        Node<T>* middle = getMiddle(start, last);

        // Step 3: If middle element is equal to the key -> search is successful
        if (middle->data == dataFind) {
            std::cout << "Searching is successful.\n";
            return;
        }

        // Step 4: If the middle element is greater than the key -> search the left side
        else if (middle->data > dataFind) {
            last = middle;
        }

        // Step 5: If the middle element is less than the key, search the right side
        else {
            start = middle->next;
        }
    }

    // Step 6: If the search range was traversed without finding the key
    std::cout << "Searching is unsuccessful.\n";
}

#endif
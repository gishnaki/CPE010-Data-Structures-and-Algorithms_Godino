    #include <iostream>
    #include <cstdlib> // for generating random integers
    #include <time.h> // will be used for our seeding function
    #include "node.h"
    #include "searchingAlgo.h"

    const int max_size = 50;

    int main() {

        //generate
        int dataset[max_size];
        srand(time(0));
        for (int i = 0; i < max_size; i++) {
            dataset[i] = rand() % 100;
        }
        for (int i = 0; i < max_size; i++) {
            std::cout << dataset[i] << " ";
        }
        std::cout << std::endl;
        int userInput;
        std::cout << "What number to search? ";
        std::cin >> userInput;
        linearSearchArr(max_size, userInput, dataset);

        // create linked list:
        Node<char>* name1 = new_node('J');
        Node<char>* name2 = new_node('A');
        Node<char>* name3 = new_node('I');
        Node<char>* name4 = new_node('M');
        Node<char>* name5 = new_node('E');

        name1->next = name2;
        name2->next = name3;
        name3->next = name4;
        name4->next = name5;
        name5->next = nullptr;
        
        std::cout << "Linked list result LS: ";
        linearSearchLL(name1, 'A');
        linearSearchLL(name2, 'r');

        std::cout<< "Linked list result BS: ";
        binarySearchLL(name1, 'I');

        //array binary search
        binarySearchArr(max_size, userInput, dataset);

    }

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "node.h"
#include "searchingAlgo.h"

// Measure the execution time of a searching algorithm
template <typename SearchFunction>
double measureSearch(const std::vector<int>& data,
                     int target,
                     SearchFunction searchFunction){

    int size = static_cast<int>(data.size());
    int arr[size];

    for(int i = 0; i < size; i++){
        arr[i] = data[i];
    }

    // Start the timer
    auto begin = std::chrono::steady_clock::now();

    searchFunction(size, target, arr);

    // Stop the timer
    auto end = std::chrono::steady_clock::now();

    // Return the execution time in microseconds
    return std::chrono::duration<double, std::micro>(
        end - begin
    ).count();
}

// Perform linear search for experimental analysis
bool linearSearchTest(int size, int target, int arr[]){

    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return true;
        }
    }

    return false;
}

// Perform binary search for experimental analysis
bool binarySearchTest(int size, int target, int arr[]){

    int low = 0;
    int high = size - 1;

    while(low <= high){

        int middle = low + (high - low) / 2;

        if(arr[middle] == target){
            return true;
        }
        else if(arr[middle] > target){
            high = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }

    return false;
}

// Compare Linear Search and Binary Search using the same input
void compareAlgorithms(const std::vector<int>& data,
                       int target,
                       const std::string& testName){

    // Measure Linear Search execution time
    double linearTime = measureSearch(
        data,
        target,
        linearSearchTest
    );

    // Measure Binary Search execution time
    double binaryTime = measureSearch(
        data,
        target,
        binarySearchTest
    );

    // Display the experimental results
    std::cout << std::left << std::setw(20) << testName
              << std::right << std::setw(18) << linearTime
              << std::setw(18) << binaryTime
              << std::endl;
}

// Perform searching demonstrations
void searchingDemonstration(){

    const int maxSize = 50;

    int dataset[maxSize];

    // Generate random values
    for(int i = 0; i < maxSize; i++){
        dataset[i] = rand() % 100;
    }

    // Display the original array
    std::cout << "\nArray:" << std::endl;
    std::cout << "-------------------------------------------------------------"
              << std::endl;

    for(int i = 0; i < maxSize; i++){
        std::cout << dataset[i] << " ";

        if((i + 1) % 10 == 0){
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;

    // Perform Linear Search for arrays
    int userInput;

    std::cout << "Linear Search for Arrays:" << std::endl;
    std::cout << "-------------------------------------------------------------"
              << std::endl;

    std::cout << "What number to search? ";
    std::cin >> userInput;

    linearSearchArr(maxSize, userInput, dataset);
    std::cout << std::endl;

    // Create a linked list for Linear Search
    Node<char>* name1 = new_node('C');
    Node<char>* name2 = new_node('A');
    Node<char>* name3 = new_node('R');
    Node<char>* name4 = new_node('L');
    Node<char>* name5 = new_node('O');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = nullptr;

    // Perform Linear Search for linked lists
    std::cout << "Linear Search for Linked List:" << std::endl;
    std::cout << "-------------------------------------------------------------"
              << std::endl;

    linearSearchLL(name1, 'R');
    linearSearchLL(name2, 'r');
    std::cout << std::endl;

    // Perform Binary Search for arrays
    int numbers[] = {15, 20, 25, 35, 40, 45, 55, 60, 65, 75};

    std::cout << "Binary Search for Arrays:" << std::endl;
    std::cout << "-------------------------------------------------------------"
              << std::endl;

    binarySearchArr(10, 45, numbers);
    binarySearchArr(10, 50, numbers);
    std::cout << std::endl;

    // Create a sorted linked list for Binary Search
    Node<int>* value1 = new_node(12);
    Node<int>* value2 = new_node(24);
    Node<int>* value3 = new_node(36);
    Node<int>* value4 = new_node(48);
    Node<int>* value5 = new_node(60);

    value1->next = value2;
    value2->next = value3;
    value3->next = value4;
    value4->next = value5;
    value5->next = nullptr;

    // Perform Binary Search for linked lists
    std::cout << "Binary Search for Linked List:" << std::endl;
    std::cout << "-------------------------------------------------------------"
              << std::endl;

    binarySearchLL(value1, 36);
    binarySearchLL(value1, 12);
    binarySearchLL(value1, 30);

    // Delete the allocated linked-list nodes
    delete name1;
    delete name2;
    delete name3;
    delete name4;
    delete name5;

    delete value1;
    delete value2;
    delete value3;
    delete value4;
    delete value5;
}


 // Perform experimental analysis using different input sizes
void experimentalAnalysis(){

    int sizes[] = {1000, 10000, 100000};

    std::cout << "\n\nEXPERIMENTAL ANALYSIS:"
              << std::endl;

    std::cout << "-------------------------------------------------------------"
              << std::endl;

    std::cout << std::fixed << std::setprecision(3);

    // Test the algorithms using different input sizes
    for(int size : sizes){

        // Generate ascending input
        std::vector<int> ascendingData(size);

        for(int i = 0; i < size; i++){
            ascendingData[i] = i;
        }

        // Set a target that is not present in the dataset
        int target = size;

        // Measure Linear Search execution time
        double linearTime = measureSearch(
            ascendingData,
            target,
            linearSearchTest
        );

        // Measure Binary Search execution time
        double binaryTime = measureSearch(
            ascendingData,
            target,
            binarySearchTest
        );

        // Display the input size
        std::cout << "\nInput Size: " << size << std::endl;

        std::cout << "-------------------------------------------------------------"
                  << std::endl;

        // Display the table headings
        std::cout << std::left << std::setw(20) << "Test Case"
                  << std::right << std::setw(20)
                  << "Linear Search (us)"
                  << std::setw(20) << "Binary Search (us)"
                  << std::endl;

        std::cout << "-------------------------------------------------------------"
                  << std::endl;

        // Display the experimental results
        std::cout << std::left << std::setw(20) << "Ascending"
                  << std::right << std::setw(20) << linearTime
                  << std::setw(20) << binaryTime
                  << std::endl;
    }
}

int main(){

    // Initialize the random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Perform the searching demonstration
    std::cout << "\nSEARCHING ALGORITHM:"
              << std::endl;

    std::cout << "-------------------------------------------------------------"
              << std::endl;

    searchingDemonstration();

    // Perform experimental analysis
    experimentalAnalysis();

    std::cout << std::endl;

    return 0;
}
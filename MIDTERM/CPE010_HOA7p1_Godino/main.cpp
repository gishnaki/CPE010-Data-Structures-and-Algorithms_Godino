#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

int main() {
    const int maxSize = 100;
    int arr[maxSize];

    // Seed for random values
    srand(time(0));

    // Generate 100 random values
    generateArray(arr, maxSize);

    std::cout << "Unsorted Array:" << std::endl;
    displayArray(arr, maxSize);

    std::cout << "\nBubble Sort:" << std::endl;
    bubbleSort(arr, maxSize);
    displayArray(arr, maxSize);

    std::cout << "\nSelection Sort:" << std::endl;
    selectionSort(arr, maxSize);
    displayArray(arr, maxSize);

    std::cout << "\nInsertion Sort:" << std::endl;
    insertionSort(arr, maxSize);
    displayArray(arr, maxSize);
}
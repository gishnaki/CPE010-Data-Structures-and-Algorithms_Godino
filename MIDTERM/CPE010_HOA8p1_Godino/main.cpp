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

    std::cout << "\nShell Sort:" << std::endl;
    shellSort(arr,maxSize);
    displayArray(arr, maxSize);

    std::cout << "\nMerge Sort:" << std::endl;
    mergeSort(arr, maxSize);
    displayArray(arr, maxSize);
    
    std::cout << "\nQuick Sort:" << std::endl;
    quickSort(arr, maxSize);
    displayArray(arr, maxSize);
    
}
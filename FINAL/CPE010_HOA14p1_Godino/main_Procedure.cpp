#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "sortingAlgo.h"

// Display all elements in the array
void displayArr(int arr[], int size){

    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";

        if((i + 1) % 10 == 0){
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}

// Measure the execution time of a sorting algorithm
template <typename SortFunction>
double measureSort(const std::vector<int>& data,
                   SortFunction sortFunction){

    int size = static_cast<int>(data.size());
    std::vector<int> arr = data;

    // Start the timer
    auto begin = std::chrono::steady_clock::now();

    sortFunction(arr.data(), size);

    // Stop the timer
    auto end = std::chrono::steady_clock::now();

    // Verify that the array is sorted
    bool correct = std::is_sorted(arr.begin(), arr.end());

    if(!correct){
        std::cout << "Error: Sorting failed!" << std::endl;
    }

    // Return the execution time in microseconds
    return std::chrono::duration<double, std::micro>(
        end - begin
    ).count();
}

// Compare Merge Sort and Quick Sort using the same input
void compareAlgorithms(const std::vector<int>& data,
                       const std::string& testName){

    // Measure Merge Sort execution time
    double mergeTime = measureSort(
        data,
        [](int arr[], int size){
            mergeSort(arr, size);
        }
    );

    // Measure Quick Sort execution time
    double quickTime = measureSort(
        data,
        [](int arr[], int size){
            quickSort(arr, size);
        }
    );

    // Display the experimental results
    std::cout << std::left << std::setw(20) << testName
              << std::right << std::setw(18) << mergeTime
              << std::setw(18) << quickTime
              << std::endl;
}

// Demonstrate Merge Sort and Quick Sort using 100 elements
void sortingDemonstration(){

    const int maxSize = 100;

    int unsortedArr[maxSize];
    int mergeArr[maxSize];
    int quickArr[maxSize];

    // Generate random values
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }

    // Copy the original array for each algorithm
    for(int i = 0; i < maxSize; i++){
        mergeArr[i] = unsortedArr[i];
        quickArr[i] = unsortedArr[i];
    }

    // Display the original array
    std::cout << "\nArray:" << std::endl;
    std::cout << "--------------------------------------------------------"
              << std::endl;

    displayArr(unsortedArr, maxSize);

    // Sort the array using Merge Sort
    std::cout << "Merge Sort:" << std::endl;
    std::cout << "--------------------------------------------------------"
              << std::endl;

    mergeSort(mergeArr, maxSize);
    displayArr(mergeArr, maxSize);

    // Sort the array using Quick Sort
    std::cout << "Quick Sort:" << std::endl;
    std::cout << "--------------------------------------------------------"
              << std::endl;

    quickSort(quickArr, maxSize);
    displayArr(quickArr, maxSize);
}

// Perform experimental analysis using different input sizes
void experimentalAnalysis(){

    int sizes[] = {100, 1000, 10000};

    // Initialize the random number generator
    std::mt19937 generator(
        static_cast<unsigned int>(std::time(nullptr))
    );

    std::cout << "\nEXPERIMENTAL ANALYSIS:"
              << std::endl;

    std::cout << "--------------------------------------------------------"
              << std::endl;

    std::cout << std::fixed << std::setprecision(3);

    // Test the algorithms using different input sizes
    for(int size : sizes){

        // Generate randomized input
        std::vector<int> randomData(size);

        for(int i = 0; i < size; i++){
            randomData[i] = i + 1;
        }

        std::shuffle(
            randomData.begin(),
            randomData.end(),
            generator
        );

        // Generate ascending input
        std::vector<int> ascendingData(size);

        for(int i = 0; i < size; i++){
            ascendingData[i] = i + 1;
        }

        // Generate descending input
        std::vector<int> descendingData = ascendingData;

        std::reverse(
            descendingData.begin(),
            descendingData.end()
        );

        // Display the input size
        std::cout << "\nInput Size: " << size << std::endl;

        std::cout << "--------------------------------------------------------"
                    << std::endl;

        // Display the table headings
        std::cout << std::left << std::setw(20) << "Test Case"
                  << std::right << std::setw(18)
                  << "Merge Sort (us)"
                  << std::setw(18) << "Quick Sort (us)"
                  << std::endl;

        std::cout << "--------------------------------------------------------" 
                    << std::endl;

        // Test randomized input
        compareAlgorithms(randomData, "Randomized");

        // Test ascending input
        compareAlgorithms(ascendingData, "Ascending");

        // Test descending input
        compareAlgorithms(descendingData, "Descending");
    }
}

int main(){

    // Initialize the random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Perform the sorting demonstration
    std::cout << "\nSORTING ALGORITHM:" << std::endl;
    std::cout << "--------------------------------------------------------"
                << std::endl;
    sortingDemonstration();

    // Perform experimental analysis
    experimentalAnalysis();
    std::cout << std::endl;

    return 0;
}
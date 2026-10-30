#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <chrono>
#include <random>
#include <algorithm>

// Merge two sorted parts of the array
void merge(std::vector<int>& arr, int left, int mid, int right){

    std::vector<int> temp;
    int i = left;
    int j = mid + 1;

    // Compare and merge elements in sorted order
    while (i <= mid && j <= right){
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    // Copy the remaining elements
    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    // Copy the merged elements back to the array
    for (int k = 0; k < static_cast<int>(temp.size()); k++)
        arr[left + k] = temp[k];
}

// Sort the array using Multithreaded Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right){

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Use multithreading for larger sections
    if (right - left >= 1000){

        // Sort the left half using a separate thread
        std::thread T1(
            mergeSort, std::ref(arr), left, mid
        );

        // Sort the right half using the current thread
        mergeSort(arr, mid + 1, right);

        // Wait for the left half to finish
        T1.join();
    }
    else{

        // Sort smaller sections without creating threads
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
    }

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Display the first 10 elements of the array
void displayArr(const std::vector<int>& arr){

    int limit = std::min(10, static_cast<int>(arr.size()));

    for (int i = 0; i < limit; i++){
        std::cout << arr[i] << " ";

        // Display five values per line
        if ((i + 1) % 5 == 0)
            std::cout << std::endl;
    }

    if (limit % 5 != 0)
        std::cout << std::endl;
}

// Test the execution time of Multithreaded Merge Sort
void testMergeSort(int testNumber, const std::vector<int>& originalArr){

    // Create a copy of the original array
    std::vector<int> testArr = originalArr;

    // Start the timer
    auto start = std::chrono::steady_clock::now();

    // Sort the array
    mergeSort(testArr, 0, static_cast<int>(testArr.size()) - 1);

    // Stop the timer
    auto end = std::chrono::steady_clock::now();

    // Calculate the execution time
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start
        );

    // Display the test number
    std::cout << "\nTest Number: " << testNumber << std::endl;

    // Display the execution time
    std::cout << "Execution Time: " << duration.count()
            << " microseconds" << std::endl;

    // Check if the array is sorted correctly
    bool sorted = std::is_sorted(testArr.begin(), testArr.end());

    std::cout << "Array Sorted Correctly: " << (sorted ? "Yes" : "No") 
            << std::endl;
}

int main(){

    const int SIZE = 100000;
    std::vector<int> arr(SIZE);

    // Generate random numbers for the array
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(1, 1000000);

    for (int i = 0; i < SIZE; i++)
        arr[i] = dist(gen);

    // Preserve the original array for experimental testing
    std::vector<int> originalArr = arr;

    // Display the algorithm name
    std::cout << "\nMultithreaded Merge Sort:" << std::endl;
    std::cout << "----------------------------------------------" 
            << std::endl;

    // Display the original array
    std::cout << "\nOriginal Array (first 10 values):" << std::endl;
    std::cout << "----------------------------------------------" 
            << std::endl;
    displayArr(arr);

    // Sort the array using Multithreaded Merge Sort
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    // Display the sorted array
    std::cout << "\nSorted Array (first 10 values):" << std::endl;
    std::cout << "----------------------------------------------" 
            << std::endl;
    displayArr(arr);

    // Check if the array is sorted correctly
    bool sorted = std::is_sorted(arr.begin(), arr.end());

    std::cout << "\nArray Sorted Correctly: " << (sorted ? "Yes" : "No") 
            << std::endl;

    // Perform experimental analysis
    std::cout << "\n\nExperimental Analysis:" << std::endl;
    std::cout << "----------------------------------------------" 
            << std::endl;

    // Display the input size
    std::cout << "Input Size: " << SIZE << std::endl;

    // Test the algorithm three times using the same input
    testMergeSort(1, originalArr);
    testMergeSort(2, originalArr);
    testMergeSort(3, originalArr);

    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int globalValue = 0;
std::mutex mtx;

// Add a value to the global variable
void add(int value){

    // Prevent simultaneous access to the global variable
    std::lock_guard<std::mutex> lock(mtx);
    globalValue += value;
}

// Display the global variable
void display(){

    // Prevent simultaneous access while displaying
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Global Variable: " << globalValue << std::endl;
}

// Test the execution time of multithreading
void testMultithreading(int testNumber){

    // Reset the global variable
    globalValue = 0;

    // Start the timer
    auto begin = std::chrono::steady_clock::now();

    // Create three threads
    std::thread T1(add, 100);
    std::thread T2(add, 200);
    std::thread T3(add, 300);

    // Wait for all threads to finish
    T1.join();
    T2.join();
    T3.join();

    // Stop the timer
    auto end = std::chrono::steady_clock::now();

    // Display the test number
    std::cout << "\nTest Number: " << testNumber << std::endl;

    // Display the execution time
    std::cout << "Execution Time: "
              << std::chrono::duration_cast<
                 std::chrono::microseconds>(end - begin).count()
              << " microseconds" << std::endl;

    // Display the final value
    std::cout << "Final Value: " << globalValue << std::endl;
}

int main(){

    // Display the algorithm name
    std::cout << "\nMultithreading:";
    std::cout << "\n----------------------------------------------";

    // Create three threads
    std::thread T1(add, 100);
    std::thread T2(add, 200);
    std::thread T3(add, 300);

    // Display the initial global variable
    std::cout << "\nInitial Display:" << std::endl;
    display();

    // Wait for Thread 1 to finish
    T1.join();

    // Display the value after Thread 1 finishes
    std::cout << "\nAfter T1.join():" << std::endl;
    display();

    // Wait for Thread 2 to finish
    T2.join();

    // Display the value after Thread 2 finishes
    std::cout << "\nAfter T2.join():" << std::endl;
    display();

    // Wait for Thread 3 to finish
    T3.join();

    // Display the value after Thread 3 finishes
    std::cout << "\nAfter T3.join():" << std::endl;
    display();

    // Perform experimental analysis
    std::cout << "\n\nExperimental Analysis:";
    std::cout << "\n----------------------------------------------";

    // Test multithreading three times
    testMultithreading(1);
    testMultithreading(2);
    testMultithreading(3);

    std::cout << std::endl;

    return 0;
}
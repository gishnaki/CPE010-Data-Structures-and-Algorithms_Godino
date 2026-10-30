#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Store the previously calculated results
std::vector<int> memo;

// Find the minimum steps to reach 1
int getMinStepsMemo(int n){

    // Check if the number reaches 1
    if(n == 1){
        return 0;
    }

    // Check if the result is already stored
    if(memo[n] != -1){
        return memo[n];
    }

    // Calculate the steps by subtracting 1
    int r = 1 + getMinStepsMemo(n - 1); // '-1' step

    // Check if the number can be divided by 2
    if(n % 2 == 0){
        r = std::min(r, 1 + getMinStepsMemo(n / 2)); // '/2' step
    }

    // Check if the number can be divided by 3
    if(n % 3 == 0){
        r = std::min(r, 1 + getMinStepsMemo(n / 3)); // '/3' step
    }

    // Save the minimum steps
    memo[n] = r; // Save the result

    return r;
}

// Test the execution time of memoization
void testMemoization(int size){

    // Initialize the memoization array
    memo.assign(size + 1, -1);
    memo[1] = 0;

    // Start the timer
    auto begin = std::chrono::steady_clock::now();
    int result = getMinStepsMemo(size);

    // Stop the timer
    auto end = std::chrono::steady_clock::now();

    // Display the input size
    std::cout << "\nInput Size: " << size << std::endl;

    // Display the execution time
    std::cout << "Execution Time: " << std::chrono::duration_cast<
                std::chrono::microseconds>(end - begin).count()
                << " microseconds" << std::endl;

    // Display the minimum steps required
    std::cout << "Minimum Steps Required: "
              << result << std::endl;
}

int main(){

    int n;

    // Display the algorithm name
    std::cout << "\nMemoization:";

    // Get a valid number from the user
    while(true){

        std::cout << "\n----------------------------------------------" 
                    << std::endl;
        std::cout << "Enter a number (1-10000): ";

        // Check if the input is valid
        if(std::cin >> n && n >= 1 && n <= 10000){
            break; // Valid input
        }

        // Display an error message
        std::cout << "Invalid input. Enter a number from 1 to 10000." 
                    << std::endl;

        // Clear the input error and remove the invalid input
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    // Initialize the memoization array
    memo.assign(n + 1, -1);
    memo[1] = 0;

    // Display the result for user input
    std::cout << "Memoization Result: "
              << getMinStepsMemo(n) << std::endl;

    // Perform experimental analysis
    std::cout << "\nExperimental Analysis:";
    std::cout << "\n----------------------------------------------";

    // Test the algorithm with different input sizes
    testMemoization(1000);
    testMemoization(5000);
    testMemoization(10000);

    std::cout << std::endl;

    return 0;
}
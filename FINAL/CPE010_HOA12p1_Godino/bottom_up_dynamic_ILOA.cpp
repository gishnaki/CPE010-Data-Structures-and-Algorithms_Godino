#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// Store the calculated results
std::vector<int> dp;

// Find the minimum steps to reach 1
int getMinStepsDP(int n){

    // Initialize the first result
    dp.assign(n + 1, 0);
    dp[1] = 0;

    // Calculate the minimum steps for each number
    for(int i = 2; i <= n; i++){

        // Calculate the steps by subtracting 1
        dp[i] = 1 + dp[i - 1];

        // Check if the number can be divided by 2
        if(i % 2 == 0){
            dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        }

        // Check if the number can be divided by 3
        if(i % 3 == 0){
            dp[i] = std::min(dp[i], 1 + dp[i / 3]);
        }
    }

    return dp[n];
}

// Test the execution time of Bottom-Up DP
void testBottomUpDP(int size){

    // Start the timer
    auto begin = std::chrono::steady_clock::now();
    int result = getMinStepsDP(size);

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
    std::cout << "\nBottom-Up Dynamic Programming:";

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

    // Display the result for user input
    std::cout << "Bottom-Up DP Result: "
              << getMinStepsDP(n) << std::endl;

    // Perform experimental analysis
    std::cout << "\nExperimental Analysis:";
    std::cout << "\n----------------------------------------------";

    // Test the algorithm with different input sizes
    testBottomUpDP(1000);
    testBottomUpDP(5000);
    testBottomUpDP(10000);

    std::cout << std::endl;

    return 0;
}
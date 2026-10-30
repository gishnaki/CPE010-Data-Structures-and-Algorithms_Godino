#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include <tuple>

// Count paths using recursion
long long countPathsRecursive(
    const std::vector<std::vector<int>>& matrix,
    int row,
    int col,
    int remaining
){

    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());

    // Check if the position is outside the matrix
    if(row >= m || col >= n){
        return 0;
    }

    // Check if the remaining cost is insufficient
    if(remaining < matrix[row][col]){
        return 0;
    }

    // Subtract the current cell cost
    remaining -= matrix[row][col];

    // Check if the destination is reached
    if(row == m - 1 && col == n - 1){
        return (remaining == 0) ? 1 : 0;
    }

    // Count paths by moving right and down
    return countPathsRecursive(
               matrix, row, col + 1, remaining)
         + countPathsRecursive(
               matrix, row + 1, col, remaining);
}

// Count paths using memoization
long long countPathsMemo(
    const std::vector<std::vector<int>>& matrix,
    int row,
    int col,
    int remaining,
    std::map<std::tuple<int, int, int>, long long>& memo
){

    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());

    // Check if the position is outside the matrix
    if(row >= m || col >= n){
        return 0;
    }

    // Check if the remaining cost is insufficient
    if(remaining < matrix[row][col]){
        return 0;
    }

    // Check if the result is already stored
    auto key = std::make_tuple(row, col, remaining);
    auto found = memo.find(key);

    if(found != memo.end()){
        return found->second;
    }

    // Subtract the current cell cost
    int newRemaining = remaining - matrix[row][col];

    // Check if the destination is reached
    if(row == m - 1 && col == n - 1){
        memo[key] = (newRemaining == 0) ? 1 : 0;
        return memo[key];
    }

    // Count paths by moving right
    long long right = countPathsMemo(
        matrix, row, col + 1, newRemaining, memo);

    // Count paths by moving down
    long long down = countPathsMemo(
        matrix, row + 1, col, newRemaining, memo);

    // Save the total number of valid paths
    memo[key] = right + down;

    return memo[key];
}

// Display the matrix
void displayMatrix(
    const std::vector<std::vector<int>>& matrix
){

    for(const auto& row : matrix){
        for(int value : row){
            std::cout << value << '\t';
        }

        std::cout << std::endl;
    }
}

// Test the execution time of both algorithms
void testPathCount(
    const std::vector<std::vector<int>>& matrix,
    int target
){

    // Start the recursive timer
    auto beginRecursive = std::chrono::steady_clock::now();

    long long recursiveResult =
        countPathsRecursive(matrix, 0, 0, target);

    // Stop the recursive timer
    auto endRecursive = std::chrono::steady_clock::now();

    // Calculate the recursive execution time
    double recursiveTime =
        std::chrono::duration<double, std::milli>(
            endRecursive - beginRecursive).count();

    // Initialize the memoization storage
    std::map<std::tuple<int, int, int>, long long> memo;

    // Start the memoization timer
    auto beginMemo = std::chrono::steady_clock::now();

    long long memoResult =
        countPathsMemo(matrix, 0, 0, target, memo);

    // Stop the memoization timer
    auto endMemo = std::chrono::steady_clock::now();

    // Calculate the memoization execution time
    double memoTime =
        std::chrono::duration<double, std::milli>(
            endMemo - beginMemo).count();

    // Display the recursive result
    std::cout << "\nRecursive Path Count: "
              << recursiveResult << std::endl;

    // Display the memoization result
    std::cout << "Memoized Path Count: "
              << memoResult << std::endl;

    // Display the recursive execution time
    std::cout << "Recursive Execution Time: "
              << recursiveTime << " ms" << std::endl;

    // Display the memoization execution time
    std::cout << "Memoization Execution Time: "
              << memoTime << " ms" << std::endl;

    // Verify that both results match
    std::cout << "Verification: "
              << (recursiveResult == memoResult
                  ? "Both results match."
                  : "Results do not match.")
              << std::endl;
}

int main(){

    // Store the matrix from the problem
    std::vector<std::vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int target = 25;

    std::cout << "\nCount Paths with a Given Cost:";

    // Display the matrix
    std::cout << "\n-----------------------------------------"
              << std::endl;
    std::cout << "Matrix:" << std::endl << std::endl;
    displayMatrix(matrix);

    // Display the target cost
    std::cout << "\nTarget Cost: "
              << target << std::endl;

    // Perform experimental analysis
    std::cout << "\nExperimental Analysis:";
    std::cout << "\n-----------------------------------------";

    // Test recursion and memoization
    testPathCount(matrix, target);

    std::cout << std::endl;

    return 0;
}
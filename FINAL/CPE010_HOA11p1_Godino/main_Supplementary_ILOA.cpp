#include <iostream>
#include <vector>
#include <chrono>

// PROBLEM 1: UNIQUE
bool Unique(std::vector<int> A){

    int n = A.size();

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i] == A[j]){
                return false;
            }
        }
    }

    return true;
}

// Experimental Analysis for UNIQUE
void testUnique(int size){

    std::vector<int> A;

    // Create an array with unique values
    for(int i = 0; i < size; i++){
        A.push_back(i);
    }

    // Start the timer
    auto begin = std::chrono::steady_clock::now();
    bool result = Unique(A);

    // Stop the timer
    auto end = std::chrono::steady_clock::now();

    std::cout << "\nInput Size: " << size << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Execution Time: " << std::chrono::duration_cast<
                std::chrono::microseconds>(end - begin).count() 
                << " microseconds" << std::endl;

    if(result){
        std::cout << "Result: All elements are unique." << std::endl;
    }
    else{
        std::cout << "Result: Duplicate element found." << std::endl;
    }
}

// PROBLEM 2: RPOWER
long long rpower(long long x, int n){

    if(n == 0){
        return 1;
    }

    return x * rpower(x, n - 1);
}

// PROBLEM 2: BRPOWER
long long brpower(long long x, int n){

    if(n == 0){
        return 1;
    }

    if(n % 2 != 0){
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    long long y = brpower(x, n / 2);

    return y * y;
}

// Experimental Analysis for Power
void testPower(int size){

    std::cout << "\nInput Size: " << size << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    // Test rpower
    auto begin1 = std::chrono::steady_clock::now();
    volatile long long result1 = rpower(2, size);
    auto end1 = std::chrono::steady_clock::now();

    std::cout << "rpower Execution Time: " << std::chrono::duration_cast<
                std::chrono::microseconds>(end1 - begin1).count() 
                << " microseconds" << std::endl;

    // Test brpower
    auto begin2 = std::chrono::steady_clock::now();
    volatile long long result2 = brpower(2, size);
    auto end2 = std::chrono::steady_clock::now();

    std::cout << "brpower Execution Time: " << std::chrono::duration_cast<
                std::chrono::microseconds>(end2 - begin2).count() 
                << " microseconds" << std::endl;
}

int main(){

    // Problem 1
    std::cout << "\nPROBLEM 1: UNIQUE" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    testUnique(1000);
    testUnique(10000);
    testUnique(100000);

    // Problem 2
    std::cout << "\nPROBLEM 2: POWER" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    testPower(1000);
    testPower(10000);
    testPower(100000);

    return 0;
}
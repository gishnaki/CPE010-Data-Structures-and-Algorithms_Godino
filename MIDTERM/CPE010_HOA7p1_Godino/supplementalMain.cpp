#include <iostream>
#include <cstdlib>
#include <time.h>
#include "supplementalSortingAlgo.h"

using namespace std;

int main() {

    const int SIZE = 101;

    //array for the votes
    int A[SIZE];

    //array for counting votes
    //index 1 to 5 represents the five candidates
    int voteCount[6] = {0};

    srand(time(0));

    //generate random votes from 1 to 5
    generateVotes(A, SIZE);

    cout << "===== UNSORTED VOTES =====\n";
    displayArray(A, SIZE);

    //sort the votes using Insertion Sort
    insertionSort(A, SIZE);

    cout << "\n===== SORTED VOTES =====\n";
    displayArray(A, SIZE);

    //count the votes
    countVotes(A, SIZE, voteCount);

    //display the results and winner
    displayResults(voteCount);

    return 0;
}
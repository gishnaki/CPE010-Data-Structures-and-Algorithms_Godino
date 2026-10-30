#ifndef SORTING_H
#define SORTING_H

//generate an array of random votes from 1 to 5
template <typename T>
void generateVotes(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 5 + 1;
    }
}

//display the array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";

        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }

    if (size % 10 != 0) {
        std::cout << std::endl;
    }
}

// Insertion Sort
template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

//count the votes
template <typename T>
void countVotes(T arr[], int size, int voteCount[]) {
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 1 && arr[i] <= 5) {
            voteCount[arr[i]]++;
        }
    }
}

//display voting results and determine winner
void displayResults(int voteCount[]) {

    std::string candidates[6] = {
        "",
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    std::cout << "\n===== VOTING RESULTS =====\n";

    for (int i = 1; i <= 5; i++) {
        std::cout << "Candidate " << i << " - "
                  << candidates[i] << ": "
                  << voteCount[i] << " votes"
                  << std::endl;
    }

    int winner = 1;

    for (int i = 2; i <= 5; i++) {
        if (voteCount[i] > voteCount[winner]) {
            winner = i;
        }
    }

    std::cout << "\n===== WINNER =====\n";
    std::cout << candidates[winner]
              << " with " << voteCount[winner]
              << " votes!"
              << std::endl;
}

#endif
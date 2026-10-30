#ifndef SORTINGALGO_H
#define SORTINGALGO_H

//generate an array of elements containing 100 
template <typename T>
void generateArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

//display all elements inside the array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";

        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
}

template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    T* leftArr = new T[leftSize];
    T* rightArr = new T[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0; //pointer into leftArr
    int j = 0; //pointer into rightArr
    int k = left; //pointer into arr (merged output)

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //copy any remaining elements
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
void mergeSortHelper(T arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = (left + right) / 2;

    mergeSortHelper(arr, left, middle); //sort first half
    mergeSortHelper(arr, middle + 1, right); //sort second half
    merge(arr, left, middle, right); //merge sorted halves
}

template <typename T>
void mergeSort (T arr[], int maxSize) {
    if (maxSize <= 1) return;
    mergeSortHelper(arr, 0, maxSize - 1);
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high]; //choose last element as pivot
    int i = low - 1; //index of the last element <= pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        } 
    }
    
    std::swap(arr[i + 1], arr[high]);; //place pivot in its correct position
    return i + 1; //return pivot's final index
}

template <typename T>
void quickSortHelper(T arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSortHelper(arr, low, pivot - 1); //sort left of pivot 
        quickSortHelper(arr, pivot + 1,  high); //sort right of pivot
    }
}

template <typename T>
void quickSort(T arr[], int maxSize) {
    if (maxSize <= 1) return;
    quickSortHelper(arr, 0, maxSize - 1);
}

#endif
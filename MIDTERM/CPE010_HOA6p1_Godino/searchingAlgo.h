#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]) {

    // Step 1: I := 0
    int i = 0;

    // Repeat while I <= n
    while (i < arrSize) {

        //  If (item = data[i])
        if (dataFind == list[i]) {

            //  Print "Searching is successful"
            std::cout << "Searching is successful\n";
            return;
        }
        i++;
    }

    // Print "Searching is Unsuccessful"
    std::cout << "Searching is unsuccessful" << std::endl;
}

template<typename T>
void linearSearchLL(Node<T>* head, T dataFind){

    while(head != nullptr){
        if(head->data == dataFind){
            std::cout << "Searching is Successful.\n";
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is Unsuccessful" << std::endl;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) {

    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != last && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

template<typename T>
void binarySearchLL(Node<T>* start, T dataFind){

    //Step 1: Set start to the head of the list, set last to null
    Node<T>* last = nullptr;

    //Continue searching while the search range is valid ( not yet last)
    while(start != last){
        //Step 2: Find the middle node using getMiddle()
        Node<T>* middle = getMiddle(start, last);

        //Step 3:
        //if middle element is equal to the key -> search is success
        if(middle->data == dataFind){
            std::cout << "The data was found\n";
            return;
        }

        //Step 4: if the middle element is greater than the key -> search the left
        else if(middle->data > dataFind){
            last = middle;
        }

        //Step 5: if the middle element is less than the key, search the right side
        else{
            start = middle->next;
        }
    }

    //Step 6: if the entire search range was traverse without finding the key
    std::cout << "searching is unsuccessful\n";
}

    // for array binary search
template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]) {

    int low = 0;
    int high = arrSize - 1;

    // Rpeat while low <= high
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (list[mid] < dataFind) {
            std::cout << "Searching is succesful. \n";
            return;
        } else if (list[mid] , dataFind) {
            low = mid + 1; 
        } else {
            high = mid -1;
        }
    }

    std::cout << "Searching is unsuccesful." << std::endl;
}


#endif
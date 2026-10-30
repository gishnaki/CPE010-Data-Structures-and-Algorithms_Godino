#ifndef CIRCULAR_DLL_H
#define CIRCULAR_DLL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;

};

// create a new node;

template <typename T>
DoubleList<T>* createNode(T newData) {
    //dynamically allocate memory
    DoubleList<T>* newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    //return the address
    return newNode;
}
template <typename T>
void cdllTraversal(DoubleList<T>* head) {
    //checking if the list empty
    if (head == nullptr) {
        std::cout<<"Empty Playlist"<<std::endl;
        return;
    }
    DoubleList<T>* current = head;
    do {
        std::cout<<current->data<<"->";
        current = current->next;

    }
    while (current != head);
    std::cout<<"Playlist Restarted"<<std::endl;

}

template <typename T>
void cdllInsertEnd(T newData, DoubleList<T>** head) {
    DoubleList<T>* newNode = createNode(newData);
    if (*head == nullptr) {
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
        return;

    }
    DoubleList<T>* tail = (*head)->prev;
    newNode->next = *head;
    newNode->prev = tail;
    tail->next = newNode;
    (*head)->prev = newNode;

}

template <typename T>
void cdllDeleteNode(T findData, DoubleList<T>** head) {
    if (*head == nullptr) return;
    DoubleList<T>* currNode = *head;

    do {
        if (currNode->data == findData) break;
        currNode = currNode->next;
    }
    while (currNode != *head);

    if (currNode->data != findData) return;

    if (currNode->next == currNode) {
        delete currNode;
        *head = nullptr;
        return;
    }

    if (currNode == *head) {
        *head = currNode->next;
    }

    currNode->prev->next = currNode->next;
    currNode->next->prev = currNode->prev;
    delete currNode;
}

template <typename T>
void cdllDeleteList(DoubleList<T>** head) {
    if (head == nullptr || *head == nullptr) return;
    DoubleList<T>* current = *head;
    (*head)->prev->next = nullptr;

    while (current != nullptr) {
        DoubleList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

template <typename T>
void next(DoubleList<T>** currTrack) {
    if (currTrack == nullptr || *currTrack == nullptr){
        std::cout<<"Empty Playlist"<<std::endl;
        return;
    }
    *currTrack = (*currTrack)->next;
    std::cout<<(*currTrack)->data<<" is now playing"<<std::endl;
}

template <typename T>
void previous(DoubleList<T>** currTrack) {
    if (currTrack == nullptr || *currTrack == nullptr) {
        std::cout<<"Empty Playlist"<<std::endl;
        return;
    }
    *currTrack = (*currTrack)->prev;
    std::cout<<(*currTrack)->data<<" is now playing"<<std::endl;
}

#endif




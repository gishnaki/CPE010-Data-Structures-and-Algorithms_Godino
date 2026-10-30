#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

//TEMPLATING
template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T> *next = nullptr;
        DoubleList<T> *prev = nullptr;

};

// Function to Create a new node
template <typename T>
DoubleList<T>* createNode(T newData) {
    // Dynamically allocate memory for the new node
    DoubleList<T>* newNode = new DoubleList<T>;
    
    newNode->data = newData; 
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Return the address of the new node
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode) {

    DoubleList<T> *tail;

    //checking if the list empty
    if (currentNode == nullptr) {
        std::cout << "The list is empty";
        return;
    }

    //forward traversing:
    std::cout << "Forward: " << std::endl;
    //move towards the last node (till it becomes nullptr)
    while (currentNode != nullptr) {
        //print the data
        std::cout << currentNode->data << " ";
        //save the current node as the last visited node
        tail = currentNode;
        //move to the next node
        currentNode = currentNode->next;
    }
    std::cout << std::endl;

    //backward traversing:
    std::cout << "Backward: " << std::endl;
    //move toward the head
    while (tail != nullptr) {
        //print the data
        std::cout << tail->data << " ";
        //move to the previous node
        tail = tail->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    //create a node
    DoubleList<T>* newNode = createNode(newData);
    //new node should point to the current head
    newNode->next = *currentHead;

    //current head should point back to the new
    (*currentHead)->prev = newNode;

    //update header pointer
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T> *currentHead){
    
    //create a new node
    DoubleList<T> *newNode = createNode(newData);
    //traverse to the last node
    while(currentHead->next !=nullptr){
        currentHead = currentHead->next;
    }
    //connect the last node to the new node
    currentHead->next = newNode;
    //connect the new node back to the last node
    newNode->prev = currentHead;
}

template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* currentNode) {
    DoubleList<T>* newNode = createNode(newData);

    newNode->next = currentNode->next;
    newNode->prev = currentNode;

    currentNode->next = newNode;

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head) {

    if (*head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    DoubleList<T>* currentNode = *head;

    while (currentNode != nullptr && currentNode->data != findData) {
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr) {
        std::cout << "Data not found" << std::endl;
        return;
    }

    if (currentNode->prev != nullptr) {
        currentNode->prev->next = currentNode->next;
    } else {
        *head = currentNode->next;
    }

    if (currentNode->next != nullptr) {
        currentNode->next->prev = currentNode->prev;
    }

    delete currentNode;
}  

template <typename T>
void dllDeleteAll(DoubleList<T>** currentHead) {
    DoubleList<T>* temp;

    while (*currentHead != nullptr) {
        temp = *currentHead;
        *currentHead = (*currentHead)->next;
        delete temp;
    }
}

#endif
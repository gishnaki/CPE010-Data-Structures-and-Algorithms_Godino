#ifndef QUEUELL_H
#define QUEUELL_H


//create a class the node
template <typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;
};

//create the new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

//enqueue operation
template<typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    //create the new node
    qNode<T>* newNode = new_node(newData);

    //inserting an item into a non empty queue
    if((*frontPtr)==nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }
    //inserting an itme into a non empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //create a temporary node
    qNode<T>* deleteNode = nullptr; //temp variable
    deleteNode = (*frontPtr);

    //check if the queue has only one node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }
    //delete the node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

//check the front
template <typename T>
void checkFront(qNode<T>* frontPtr){
    if(frontPtr == nullptr){
        std::cout << "Queue is empty\n";
        return;
    }

    std::cout << "Front: " << frontPtr->data << std::endl;
}
//check the back
template <typename T>
void checkBack(qNode<T>* backPtr) {
    if(backPtr == nullptr){
        std::cout << "Queue is empty\n";
        return;
    }

    std::cout << "Back: " << backPtr->data << std::endl;
}
//display all
template <typename T>
void displayAll(qNode<T>* frontPtr) {
    if(frontPtr == nullptr) {
        std::cout << "Queue is empty \n";
        return; 
    }

    qNode<T>* current = frontPtr;

    std::cout << "Queue: ";

    while(current != nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
#endif
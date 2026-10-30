#ifndef LIST_STACK_H
#define LIST_STACK_H

//class node with dat and next members
template <typename T>
class Node{
    public:
        T data;
        Node<T>* next = nullptr;
};

//create a pointer/reference tip that always point to current top node of the

//global
template <typename T>
Node<T>* head= nullptr;

//pushing operation:
template <typename T>
void push(T newData){
    //create a new node
    Node<T>* newNode = new Node<T>;
    //assign the data to the new node
    newNode->data = newData;
    //link the new node to the current head
    newNode->next = head <T>; 
    //make the new node the new top
    head<T> = newNode;
}

//isEmpty()
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

//popping operation:
template <typename T>
T pop(){
    //if the stack is empty error catch:
    if(isEmpty<T>()){
        std::cout<<"Stack underflow"<<std:: endl;
        
    }
    //saving a current top node to a temporary variable
    Node<T>* temp = head<T>;
    //store the data to a temporary variable
    T tempVal = temp->data;
    //move the head to next node
    head<T> = head<T>->next;
    //free up the memory
    delete temp;
    //return the temprary variable data
    return tempVal;
}

template <typename T>
void Top(){
    //what if the stack is empty
    if(isEmpty<T>()) return;

    std::cout<<"the top is: " << head<T> ->data << std::endl;
}

//display all
template <typename T>
void displayAll(){
    //stack is empty
    if (isEmpty<T>()) return;
    //store the head with temp
    Node<T>* temp = head<T>;
    while (head<T> != nullptr){
        std::cout<< head<T>->data <<std::endl;
        head<T> = head<T>->next;

    }
    //ensure the head does not change its value
    head<T> = temp;
    std::cout << std::endl;
}

#endif
#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>

class SinglyList{
    public:
        T data;
        SinglyList<T> *next = nullptr;
};

template <typename T>
void listTraversal(SinglyList<T>* head){
    
    if(head == nullptr){
        std::cout<<"List is empty"<<std::endl;
        return;
    }
    while(head != nullptr){
        std::cout<< head->data;
        if(head->next != nullptr){
            std::cout<<"->";
        }

        head = head->next;
    } 
    std::cout<< std::endl;
}

//insertion
template <typename T>
void sllinsertHead(T newData, SinglyList<T>** currentHead){
    //1
    SinglyList<T>* newNode = new SinglyList<T>;
    //2
    newNode->data = newData;
    //3
    newNode->next = *currentHead;
    //4
    *currentHead = newNode;
}
template <typename T>
void sllGeneralInsert(T newData, SinglyList<T>* prevNode){
    if(prevNode == nullptr){
        std::cout<<"Previous Node cannot be Null"<<std::endl;
        return;
    }
    SinglyList<T>* newNode = new SinglyList<T>;
    
    newNode->data = newData;

    newNode->next = prevNode->next;

    prevNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SinglyList<T>** head){

    SinglyList<T>* newNode= new SinglyList<T>;
    
    SinglyList<T>* currentNode = *head;

    newNode->data = newData;

    newNode->next = nullptr;

    while(currentNode->next !=nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SinglyList<T>** head){
    //check
    if(*head == nullptr) return;

    SinglyList<T>* currNode = *head;
    SinglyList<T>* prevNode = nullptr;

    //search loop
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    //data was found:
    if(currNode == nullptr) return;

    //what if
    if(prevNode ==nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    //delete
    delete currNode;

}

template <typename T>
void sllDeleteList(SinglyList<T>** head){
    SinglyList<T>* current = *head;

    while(current != nullptr){
        SinglyList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

#endif
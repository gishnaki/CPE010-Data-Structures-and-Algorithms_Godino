#ifndef LIST_STACK_H
#define LIST_STACK_H

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next = nullptr;
        Node(T val) : data(val), next(nullptr){}
    };

template <typename T>
class ListStack {
    private:
        Node<T>* head;
    public:
        ListStack() : head(nullptr){}

        ~ListStack() {
            clear();
        }

    bool isEmpty() const {
        return head == nullptr;
    }

    void push(T newData) {
        Node<T>* newNode = new Node<T>(newData);
        newNode->next = head;
        head = newNode;
    }

    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack Underflow" << std::endl;
            return T();
        }
        Node<T>* temp = head;
        T tempVal = temp->data;
        head = head ->next;
        delete temp;
        return tempVal;
    }

    T peak () const {
        if(!isEmpty()) return head-> data;
        return T();
    }

    void clear() {
        while(!isEmpty()) {
            pop();
        }
    }
};


#endif
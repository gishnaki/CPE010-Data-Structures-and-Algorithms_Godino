#ifndef BST_H
#define BST_H

template<typename T>
class BinarySearchTree{
    private:
        T key;
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right; 
    public:
    //constructor
    BinarySearchTree(T value);
    // insertion:
    void insert(T value);

    //traversal:
    void preOrder();
    void inOrder();
    void postOrder();
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
}

template<typename T>
void BinarySearchTree<T>::insert(T value){
    // go to left if: value is < key
    if(value < key){

        if(left == nullptr){
            left = new BinarySearchTree(value);
        } else{
            left->insert(value);
        }
    }
    else if(value > key){
        if (right == nullptr){
            right = new BinarySearchTree<T>(value);
        } else{
            right->insert(value);
        }
    }
    // go to right if: value > key
}

template<typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout << key << " ";
    if(left != nullptr){
        left->preOrder();
    }
    if (right != nullptr){
        right->preOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::inOrder(){
    if(left != nullptr){
        left->inOrder();
    }
    std::cout << key << " ";
    
    if (right != nullptr){
        right->inOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::postOrder(){
    if(left != nullptr){
        left->postOrder();
    }
    
    if (right != nullptr){
        right->postOrder();
    }
    std::cout << key << " ";
}
#endif
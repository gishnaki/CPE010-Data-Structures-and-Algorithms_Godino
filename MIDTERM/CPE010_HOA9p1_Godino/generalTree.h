#ifndef GENERALTREE_H
#define GENERALTREE_H

template<typename T>
class BinarySearchTree {
protected:
    T key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

    //helper findData
    bool searchHelper(int choice, T targetKey) {
        if (choice == 1) { //Preorder: Root -> Left -> Right
            if (this->key == targetKey) return true;
            if (left != nullptr && left->searchHelper(choice, targetKey)) return true;
            if (right != nullptr && right->searchHelper(choice, targetKey)) return true;
        }
        else if (choice == 2) { //Inorder: Left -> Root -> Right
            if (left != nullptr && left->searchHelper(choice, targetKey)) return true;
            if (this->key == targetKey) return true;
            if (right != nullptr && right->searchHelper(choice, targetKey)) return true;
        }
        else if (choice == 3) { // Postorder: Left -> Right -> Root
            if (left != nullptr && left->searchHelper(choice, targetKey)) return true;
            if (right != nullptr && right->searchHelper(choice, targetKey)) return true;
            if (this->key == targetKey) return true;
        }
        return false;
    }

public:
    //Constructor
    BinarySearchTree(T value);

    //BST Insertion
    void insert(T value);

    //for Binary Tree and General Tree linking
    void setLeft(BinarySearchTree<T>* node);
    void setRight(BinarySearchTree<T>* node);
    BinarySearchTree<T>* getLeft() const;
    BinarySearchTree<T>* getRight() const;
    T getKey() const;

    //for General Tree LeftChild / RightSibling
    void addChild(BinarySearchTree<T>* child);

    //traversal:
    void preOrder();
    void inOrder();
    void postOrder();

    //findData function
    void findData(int choice, T targetKey);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

template<typename T>
void BinarySearchTree<T>::insert(T value) {
    if (value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree(value);
        } else {
            left->insert(value);
        }
    }
    else if (value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree(value);
        } else {
            right->insert(value);
        }
    }
}

template<typename T>
void BinarySearchTree<T>::setLeft(BinarySearchTree<T>* node) {
    left = node;
}

template<typename T>
void BinarySearchTree<T>::setRight(BinarySearchTree<T>* node) {
    right = node;
}

template<typename T>
BinarySearchTree<T>* BinarySearchTree<T>::getLeft() const {
    return left;
}

template<typename T>
BinarySearchTree<T>* BinarySearchTree<T>::getRight() const {
    return right;
}

template<typename T>
T BinarySearchTree<T>::getKey() const {
    return key;
}

//attach a child node using Left-Child (child) / Right-Sibling (sibling)
template<typename T>
void BinarySearchTree<T>::addChild(BinarySearchTree<T>* child) {
    if (!child) return;

    if (this->left == nullptr) {
        this->left = child;
    } else {
        BinarySearchTree<T>* sibling = this->left;
        while (sibling->right != nullptr) {
            sibling = sibling->right;
        }
        sibling->right = child;
    }
}

template<typename T>
void BinarySearchTree<T>::preOrder() {
    std::cout << key << " ";
    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::inOrder() {
    if (left != nullptr) {
        left->inOrder();
    }
    std::cout << key << " ";
    if (right != nullptr) {
        right->inOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::postOrder() {
    if (left != nullptr) {
        left->postOrder();
    }
    if (right != nullptr) {
        right->postOrder();
    }
    std::cout << key << " ";
}

//find data
template<typename T>
void BinarySearchTree<T>::findData(int choice, T targetKey) {
    if (searchHelper(choice, targetKey)) {
        std::cout << targetKey << " was found!" << std::endl;
    }
}

#endif
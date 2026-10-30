#include <iostream>
#include "BST.h"

int main(){

    BinarySearchTree<int>* tree = new BinarySearchTree(2);

    tree->insert(3);
    tree->insert(9);
    tree->insert(18);
    tree->insert(0);
    tree->insert(1);
    tree->insert(4);
    tree->insert(5);
    

    std::cout << "preOrder output: \n";
    tree->preOrder();
    std::cout<<std::endl;

    std::cout<<"inOrder output: \n";
    tree->inOrder();
    std::cout<<std::endl;

    std::cout<<"postOrder output: \n";
    tree->postOrder();
    
    return 0;
}
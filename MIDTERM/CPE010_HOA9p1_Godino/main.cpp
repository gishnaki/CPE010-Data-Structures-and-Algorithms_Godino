#include <iostream>
#include "generalTree.h"

int main() {
    //creating nodes
    BinarySearchTree<char>* A = new BinarySearchTree<char>('A');
    BinarySearchTree<char>* B = new BinarySearchTree<char>('B');
    BinarySearchTree<char>* C = new BinarySearchTree<char>('C');
    BinarySearchTree<char>* D = new BinarySearchTree<char>('D');
    BinarySearchTree<char>* E = new BinarySearchTree<char>('E');
    BinarySearchTree<char>* F = new BinarySearchTree<char>('F');
    BinarySearchTree<char>* G = new BinarySearchTree<char>('G');
    BinarySearchTree<char>* H = new BinarySearchTree<char>('H');
    BinarySearchTree<char>* I = new BinarySearchTree<char>('I');
    BinarySearchTree<char>* J = new BinarySearchTree<char>('J');
    BinarySearchTree<char>* K = new BinarySearchTree<char>('K');
    BinarySearchTree<char>* L = new BinarySearchTree<char>('L');
    BinarySearchTree<char>* M = new BinarySearchTree<char>('M');
    BinarySearchTree<char>* N = new BinarySearchTree<char>('N');
    BinarySearchTree<char>* P = new BinarySearchTree<char>('P');
    BinarySearchTree<char>* Q = new BinarySearchTree<char>('Q');

    // Link root children
    A->addChild(B);
    A->addChild(C);
    A->addChild(D);
    A->addChild(E);
    A->addChild(F);
    A->addChild(G);

    // Link Level 1 children
    D->addChild(H);
    E->addChild(I);
    E->addChild(J);
    F->addChild(K);
    F->addChild(L);
    F->addChild(M);
    G->addChild(N);

    // Link Level 2 children
    J->addChild(P);
    J->addChild(Q);

    std::cout << "Tree successfully created" << std::endl;

    std::cout << "Pre-order:  ";
    A->preOrder();
    std::cout << std::endl;

    std::cout << "Post-order: ";
    A->postOrder();
    std::cout << std::endl;

    std::cout << "In-order:   ";
    A->inOrder();
    std::cout << std::endl;

    std::cout << "\ntesting findData" << std::endl;
    A->findData(1, 'J'); //J was found!
    A->findData(1, 'Z'); //No output

    std::cout << "\nadding O" << std::endl;
    BinarySearchTree<char>* O = new BinarySearchTree<char>('O');
    G->addChild(O);
    A->findData(1, 'O'); // O was found!

    return 0;
}   
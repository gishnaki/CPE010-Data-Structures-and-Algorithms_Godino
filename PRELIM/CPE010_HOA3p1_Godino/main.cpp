#include <iostream>
#include "singly_LL.h"
#include "double_LL.h"

int main() {

    //creating the first node 'C' 'P' 'E'
    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    //Link the nodes together
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Traversal Testing: " << std::endl;
    dllTraverse(head);

    std::cout << "Insert Head Testing: " << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout << "Insert End Testing: " << std::endl;
    dllInsertHead('1', &head);
    dllTraverse(head);

    std::cout << "Insert General Testing: " << std::endl;
    dllGeneralInsert('B', head->next->next);
    dllTraverse(head);
    
    std::cout<<"Delete Node Testing: " << std::endl;
    dllGeneralInsert('B', head->next->next);
    dllTraverse(head);
   
    return 0;
}
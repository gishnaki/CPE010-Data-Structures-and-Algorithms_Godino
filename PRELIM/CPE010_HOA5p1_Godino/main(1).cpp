#include <iostream>
#include "queueLL.h"


int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('J', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    enqueue('A', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    enqueue('I', &front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    
    dequeue(&front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    dequeue(&front, &back);
    std::cout<< front->data << " " << back->data <<std::endl;
    
    checkFront(front);
    checkBack(back);
    displayAll(front);
    return 0;
}
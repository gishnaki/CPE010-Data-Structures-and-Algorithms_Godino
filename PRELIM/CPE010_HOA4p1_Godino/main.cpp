#include <iostream>
#include <iostream>
#include "listStack.h"

int main(){
    std::cout<<"------- Pushing 'I' 'E' 'E' 'E' ------ \n";

    //pushing
    push('I');
    push('E');
    push('E');
    push('E');

    //display top
    Top<char>();

    //display all elements in the stack
    std::cout<<"Display all: \n";
    displayAll<char>();

    //pop and print each element
    std::cout<<"------ popping 'E' 'E' 'E' 'I' ----- \n";
    while(!isEmpty<char>()){
        std::cout<<"popping: "<<pop<char>()<<std::endl;
    }
    //test stack underflow
    pop<char>();

    return 0;
}
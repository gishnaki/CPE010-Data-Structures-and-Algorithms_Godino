#include<iostream>
#include <stack> //call the stack form the STL

main(){
    std::stack<int> newStack; //created an object

    std::cout<<"Is the stack empty? " << newStack.empty()<< std::endl;

    //insert a 3 elements:
    newStack.push(3);
    std::cout<<"Top of stack: " << newStack.top()<< std::endl;
    newStack.push(2);
    std::cout<<"Top of stack: " << newStack.top()<< std::endl;
    newStack.push(1);
    std::cout<<"Top of stack: " << newStack.top()<< std::endl;

    std::cout<<"Is the stack empty " << newStack.empty()<< std::endl;
    newStack.push(6);
    newStack.push(7);
    newStack.push(8);

    std::cout<<"Size of the stack is: " << newStack.size()<< std::endl;
    
    //Swap?? -? swap the content of the public member functions
    std::cout<<"\nswap"<< std::endl;
    std::stack<int> secondStack;
    secondStack.push(9);
    secondStack.push(8);
    
    newStack.swap(secondStack);

    std::cout << "newStack top: " << newStack.top() << std::endl;
    //emplace -> construct and insert element -> public member function
    std::cout<<"\nemplace"<< std::endl;
    newStack.emplace(6);
    
    std::cout<<"new top of the stack: "<< newStack.top() << std::endl;
    return 0;
}
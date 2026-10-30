#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);


int main(){
    //create an object
    std::queue<char> myQ;

    myQ.push('J');
    myQ.push('A');
    myQ.push('I');
    myQ.push('M');
    myQ.push('E');
    display(myQ);
    //try all member functions:
    //empty
    if (myQ.empty()){
        std::cout << "Queue is empty" << std::endl;
    }else{
        std::cout << "Queue is not empty" << std::endl;
    } 
    //size
    std::cout << "Size of queue: " << myQ.size() <<std::endl;
    //front
    std::cout <<myQ.front() << std::endl;
    //back
    std::cout <<myQ.back() << std::endl;
    //pop
    myQ.pop();
    //display
    display(myQ);
    //push
    myQ.push('G');
    //display
    display(myQ);

    return 0;
}
void display(std::queue<char> copyQ){
    //creates a copy of the queue that was passed
    std::queue<char> c = copyQ;

    while(!c.empty()){
        std::cout<<" " <<c.front();
        c.pop();
    }
    std::cout<<"\n";
}

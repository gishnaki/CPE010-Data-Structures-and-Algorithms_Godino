#include <iostream>
#include <string>

const int maxCap = 100;
char stack[maxCap];
int top = -1;

void push(char c);
char pop();
char Top();
bool isFull();
bool isEmpty();
bool isMatching(char a, char b);
bool balanceCheck(const std::string& expression);

int main(){
    std::string inpExpression;
    std::cout<<"Balance Checker (Type stop to exit)" <<std::endl;

    while(true) {
        std::cout<<"Enter Expression: ";
        std::getline(std::cin, inpExpression);
        if (inpExpression == "" || inpExpression == "stop") break;

        top = -1;
        bool isValidExpression = balanceCheck(inpExpression);
        std::cout <<"Valid (Y/N) : " << (isValidExpression ? "Y" : "N") << std::endl;
    
    }
    return 0;
}

bool isMatching(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '{' && b == '}') return true;
    if (a == '[' && b == ']') return true;
    return false;
}

bool balanceCheck(const std::string& expression) {
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) return false;
            char topChar = pop();
            if (!isMatching(topChar, ch)) {
                return false;
            }
        }
    }
    return isEmpty();
}

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top >=maxCap -1;
}

void push(char c){
    if (isFull()) {
        std::cout << "Stack Overflow!\n";
        return;
    }
    stack[++top] = c;
}

char pop(){
    if(isEmpty()) return '\0';
    return stack[top--];
}

char Top(){
    if(isEmpty()) return '\0';
    return stack[top];
}
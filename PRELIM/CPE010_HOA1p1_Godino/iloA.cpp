#include <iostream>

//Create a function that will take two numbers and display the sum

int sumOfTwoNum(int fNum, int sNum);
void sumOfThreeNum(int fNum, int sNum, int tNum);


//Create a function that will return whether variable A is greater than variable

bool greaterNum(int A, int B);

//Create a function that will take two Boolean values and display the result of all
//logical operations return true if it was a success

bool logicalOperators(bool a, bool b);

int main()
{
	std::cout<<"The sum of the two number is: "<<sumOfTwoNum(6,7)<<std::endl;
	sumOfThreeNum(6,7,8);

	int A, B;
	
	std::cout <<"Comparing greater value:"<< std::endl;
	greaterNum(7, 8);
	
	if (greaterNum(A,B)){
		std::cout <<"A is greater than B"<< std::endl;
	}else{
		std::cout <<"A is NOT greater than B"<< std::endl;
	}
	
	std::cout<< "The result of the two boolean value is: \n" << logicalOperators(1,0);

	
}
int sumOfTwoNum(int fNum, int sNum){
	
	int sum = fNum + sNum;
	
	return sum;
}
void sumOfThreeNum(int fNum, int sNum, int tNum){
	
	std::cout<< "sum: " << fNum+sNum+tNum <<std::endl;	
}
bool greaterNum(int A, int B){
	return A > B;
}
bool logicalOperators(bool a, bool b){
	std::cout<<"AND: " << (a && b)<< std::endl;
	std::cout<<"OR : " << (a || b)<< std::endl;
	std::cout<<"NOT: " << (!a)<< std::endl;
	std::cout<<"NOT: " << (!b)<< std::endl;
	
	return true;
}
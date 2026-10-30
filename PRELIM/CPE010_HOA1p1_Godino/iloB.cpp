#include <iostream>

//
class Triangle{
	private:
		double totalAngle, angleA, angleB, angleC;
	public:
		//constructor
		Triangle(double A, double B, double C);
		void setAngles(double A, double B, double C);
		
		//triangle validation
		const bool validateTriangle();
		
};

int main(){
	
	Triangle setl(40,30,110);
	if (setl.validateTriangle()){
		std::cout<<"The shape is a valid triangle \n";
	}else{
		std::cout<< "The shape is a NOT valid triangle \n";
	}
	
}

Triangle::Triangle(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC= C;
	totalAngle = A+B+C;
	
} 

void Triangle::setAngles(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC= C;
	totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
	return(totalAngle <= 180);
}

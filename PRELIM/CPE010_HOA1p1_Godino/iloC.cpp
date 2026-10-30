#include <iostream>
#include <cmath>
#include <utility>

class SwapNumbers {
private:
    int num1, num2;

public:
    void input();
    void swapNumbers();
};

class ConvertTemperature {
private:
    double kelvin;

public:
    void inputTemperature();
    double convertTemperature();
};

class CalculateDistance {
private:
    double x1, y1, x2, y2;

public:
    CalculateDistance(double, double, double, double);
    double calculateDistance();
};

class Triangle {
private:
    double angleA, angleB, angleC;
    double sideA, sideB, sideC;

public:
    Triangle(double, double, double, double, double, double);

    bool validateTriangle();
    double computeArea();
    double computePerimeter();
    void triangleType();
};

int main()
{
    SwapNumbers swap;
    swap.input();
    swap.swapNumbers();

    ConvertTemperature converter;
    converter.inputTemperature();
    std::cout << "\nTemperature in Fahrenheit: "
              << converter.convertTemperature() << " F\n";

    CalculateDistance points(2, 3, 6, 7);
    std::cout << "\nDistance between the two points: "
              << points.calculateDistance() << std::endl;

    Triangle t(40, 30, 110, 5, 6, 7);

    if (t.validateTriangle()) {
        std::cout << "\nThe shape is a valid triangle.\n";
        std::cout << "Area = " << t.computeArea() << std::endl;
        std::cout << "Perimeter = " << t.computePerimeter() << std::endl;
        t.triangleType();
    }
    else {
        std::cout << "\nThe shape is NOT a valid triangle.\n";
    }

    return 0;
}

void SwapNumbers::input()
{
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "\nBefore Swapping\n";
    std::cout << "First Number = " << num1 << "\n";
    std::cout << "Second Number = " << num2 << "\n";
}

void SwapNumbers::swapNumbers()
{
    std::swap(num1, num2);

    std::cout << "\nAfter Swapping\n";
    std::cout << "First Number = " << num1 << "\n";
    std::cout << "Second Number = " << num2 << "\n";
}

void ConvertTemperature::inputTemperature()
{
    std::cout << "\nEnter temperature in Kelvin: ";
    std::cin >> kelvin;
}

double ConvertTemperature::convertTemperature()
{
    return (kelvin - 273.15) * 9 / 5 + 32;
}

CalculateDistance::CalculateDistance(double a, double b, double c, double d)
    : x1(a), y1(b), x2(c), y2(d) {}

double CalculateDistance::calculateDistance()
{
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

Triangle::Triangle(double A, double B, double C,
                   double a, double b, double c)
    : angleA(A), angleB(B), angleC(C),
      sideA(a), sideB(b), sideC(c) {}

bool Triangle::validateTriangle()
{
    return (angleA + angleB + angleC == 180);
}

double Triangle::computePerimeter()
{
    return sideA + sideB + sideC;
}

double Triangle::computeArea()
{
    double s = computePerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::triangleType()
{
    if (angleA < 90 && angleB < 90 && angleC < 90)
        std::cout << "Triangle Type: Acute-angled\n";
    else if (angleA > 90 || angleB > 90 || angleC > 90)
        std::cout << "Triangle Type: Obtuse-angled\n";
    else
        std::cout << "Triangle Type: Others\n";
}
#include <iostream>
#include <string.h>

class Grocery{
protected:
    std::string name;
    double price;
    int quantity;

public:
    //constructor
    Grocery(std::string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    //copy constructor
    Grocery(const Grocery& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }
    
    //copy assignment operator
    Grocery& operator=(const Grocery& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }
    //destructor
    virtual ~Grocery() {
        std::cout<< name <<" destroyed" <<std::endl;
    }

    double calculateSum() const {
        return price * quantity;
    }

    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: PHP " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total: PHP " << calculateSum() << std::endl << std::endl;
    }
};

class Fruit : public Grocery {
public:
    Fruit(std::string n = "", double p = 0, int q = 0)
        : Grocery(n, p, q) {}
    
    Fruit& operator=(const Fruit& other) {
        Grocery::operator=(other);
        return *this;
    }

    ~Fruit() {
        std::cout << "Fruit Destructor Called" << std::endl << std::endl;
    }

    void display() const override {
        std::cout << "Fruit" << std::endl;
        Grocery::display();
    }
};

class Vegetable : public Grocery {
public:
    Vegetable(std::string n = "", double p = 0, int q = 0)
        : Grocery(n, p, q) {}

    Vegetable(const Vegetable& other)
        : Grocery(other) {}

    Vegetable& operator=(const Vegetable& other) {
        Grocery::operator=(other);
        return *this;
    }

    ~Vegetable() {
        std::cout << "Vegetable Destructor Called" << std::endl << std::endl;
    }

    void display() const override {
        std::cout << "Vegetable" << std::endl;
        Grocery::display();
    }
};

double TotalSum(Grocery* GroceryList[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        if (GroceryList[i] != nullptr)
            total += GroceryList[i]->calculateSum();
    }
    
    return total;
}

int main() {

    Grocery* GroceryList[4];

    GroceryList[0] = new Fruit("Apple", 10, 7);
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    std::cout << "Jenna's Grocery List\n";

    for (int i = 0; i < 4; i++) {
        GroceryList[i]->display();
    }

    std::cout << "Total Amount to Pay: PHP " 
              << TotalSum(GroceryList, 4) << std::endl;

    std::cout << "\nDeleting Lettuce\n\n";

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    for (int i = 0; i < 4; i++) {
        if (GroceryList[i] != nullptr)
            GroceryList[i]->display();
    }

    std::cout << "Updated Total: PHP " << TotalSum(GroceryList, 4) << std::endl << std::endl;    
    
    //Delete
    for (int i = 0; i <  4; i++) {
        delete GroceryList[i];
    }
    return 0;
}
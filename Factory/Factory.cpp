#include <iostream>
#include <memory>
#include <string>

// Utilty function to print messages to stdout
void print(const std::string& msg) { std::cout << msg << std::endl; }

// Abstract product class 
class Product
{
public:
	// Pure virtual member function that will be overriden by concrete product classes
	virtual void SomeFunction() const = 0;
};

class Creator
{
public:
	// Pure virtual function that concrete methods will override returning concrete products
	virtual std::shared_ptr<Product> FactoryMethod() const = 0;
};


int main() {

}

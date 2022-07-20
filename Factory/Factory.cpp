#include <iostream>
#include <memory>
#include <string>

// Utilty function to print messages to stdout
void print(const std::string& msg) { std::cout << msg << std::endl; }

// Abstract product class 
class Product
{
	std::string name;
public:
	Product(const std::string& nm = "Default Name") : name(nm) {}
	virtual void SomeFunction() const = 0;
	
	~Product() = default;
};

class Creator
{
public:
	// Pure virtual function that concrete methods will override returning concrete products
	virtual std::shared_ptr<Product> FactoryMethod() const = 0;
};

class ConcreteCreator: public Creator
{
public:

	// Concrete factory method
	virtual std::shared_ptr<Product> FactoryMethod() const override 
	{
		print(__PRETTY_FUNCTION__);
		return nullptr;
	}	

	~ConcreteCreator() = default;
};

int main() {

	ConcreteCreator creator;
	creator.FactoryMethod();

}

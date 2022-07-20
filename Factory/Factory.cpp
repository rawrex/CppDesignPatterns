#include <iostream>
#include <memory>
#include <string>

// Utilty function to print messages to stdout
void print(const std::string& msg) { std::cout << msg << std::endl; }

enum class ProductId { FOO, BAR, BAZ };

// Abstract product class 
class Product
{
public:
	// Pure virtual member function that will be overriden by concrete product classes
	virtual void SomeFunction() const = 0;
};

class FooProduct: public Product
{
public:
	virtual void SomeFunction() const override
	{
		print(__PRETTY_FUNCTION__);
	}
};
class BarProduct: public Product
{
public:
	virtual void SomeFunction() const override
	{
		print(__PRETTY_FUNCTION__);
	}
};
class BazProduct: public Product
{
public:
	virtual void SomeFunction() const override
	{
		print(__PRETTY_FUNCTION__);
	}
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
	virtual std::shared_ptr<Product> FactoryMethod(ProductId pid) const override 
	{
		print(__PRETTY_FUNCTION__);

		switch(pid)
		{
			case FOO: return std::make_shared<FooProduct>();
			case BAR: return std::make_shared<BarProduct>();
			case BAZ: return std::make_shared<BazProduct>();
		}
	}	
};

int main() {

	ConcreteCreator creator;
	auto product = creator.FactoryMethod();

}

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

// A concrete product class
class FooProduct: public Product
{
public:
	virtual void SomeFunction() const override
	{
		print(__PRETTY_FUNCTION__);
	}
};
// A concrete product class
class BarProduct: public Product
{
public:
	virtual void SomeFunction() const override
	{
		print(__PRETTY_FUNCTION__);
	}
};
// A concrete product class
class BazProduct: public Product
{
public:
	virtual void SomeFunction() const override
	{
		print(__PRETTY_FUNCTION__);
	}
};

// Abstract Factory class
class Creator
{
public:
	// Pure virtual function that concrete methods will override returning concrete products
	virtual std::shared_ptr<Product> FactoryMethod(ProductId) const = 0;
};

// Concrete Factory class
class ConcreteCreator: public Creator
{
public:
	// Concrete factory method
	virtual std::shared_ptr<Product> FactoryMethod(ProductId pid) const override 
	{
		print(__PRETTY_FUNCTION__);

		switch(pid)
		{
			case ProductId::FOO: return std::make_shared<FooProduct>();
			case ProductId::BAR: return std::make_shared<BarProduct>();
			case ProductId::BAZ: return std::make_shared<BazProduct>();
			default: return nullptr; break;
		}
	}	
};

int main() {

	ConcreteCreator creator;
	auto foo_product = creator.FactoryMethod(ProductId::FOO);
	auto bar_product = creator.FactoryMethod(ProductId::BAR);
	auto baz_product = creator.FactoryMethod(ProductId::BAZ);

	foo_product->SomeFunction();
	bar_product->SomeFunction();
	baz_product->SomeFunction();

}

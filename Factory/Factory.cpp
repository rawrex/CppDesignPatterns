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

// Factory class, an abstract class that provides the common interface
class Factory
{
public:
	// Pure virtual function that concrete methods will override returning concrete products
	virtual std::shared_ptr<Product> Create() const = 0;
};

// Concrete Factory class that creates Foo products
class FooFactory: public Factory
{
	virtual std::shared_ptr<Product> Create() const override 
	{
		return std::make_shared<FooProduct>();
	}
};

// Concrete Factory class that creates Bar products
class BarFactory: public Factory
{
	virtual std::shared_ptr<Product> Create() const override 
	{
		return std::make_shared<BarProduct>();
	}
};

// Concrete Factory class that creates Baz products
class BazFactory: public Factory
{
	virtual std::shared_ptr<Product> Create() const override 
	{
		return std::make_shared<BazProduct>();
	}
};


// A client part of the pattern
// Client is a user of the factory interface 
class Client 
{
public:
	void use(const Factory& factory)
	{
		// A clinet is agnositc of the type of factory it uses 
		// and of the type of products this factory produces
		std::shared_ptr<Product> product = factory.Create();
		product->SomeFunction();
	}
};
		

int main() {

	// We use the same creator object to create different types of products
	FooFactory foo_creator;
	BarFactory bar_creator;
	BazFactory baz_creator;

	Client client;
	client.use(foo_creator);
	client.use(bar_creator);
	client.use(baz_creator);

}

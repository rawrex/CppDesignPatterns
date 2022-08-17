#pragma once
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
class BasicFactory
{
public:
	// Pure virtual function that concrete methods will override returning concrete products
	virtual std::unique_ptr<Product> Create() const = 0;
	virtual ~BasicFactory() = default;
};

// Concrete Factory class that creates Foo products
class FooFactory: public BasicFactory
{
	virtual std::unique_ptr<Product> Create() const override 
	{
		return std::make_unique<FooProduct>();
	}
};

// Concrete Factory class that creates Bar products
class BarFactory: public BasicFactory
{
	virtual std::unique_ptr<Product> Create() const override 
	{
		return std::make_unique<BarProduct>();
	}
};

// Concrete Factory class that creates Baz products
class BazFactory: public BasicFactory
{
	virtual std::unique_ptr<Product> Create() const override 
	{
		return std::make_unique<BazProduct>();
	}
};


// A client part of the pattern
// Client is a user of the factory interface 
class Client 
{
public:
	void use(const BasicFactory& factory)
	{
		// A clinet is agnositc of the type of factory it uses 
		// and of the type of products this factory produces
		std::unique_ptr<Product> product = factory.Create();
		product->SomeFunction();
	}
};

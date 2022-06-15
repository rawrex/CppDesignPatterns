#include <memory>
#include <iostream>

// https://refactoring.guru/design-patterns/bridge
//
// In Bridge we use object composition for implementations diversity


class AbstractImplementor 
{
	// Data members...
public:
	virtual void imp_operation() = 0;
};

class ConcreteImplementor_A: public AbstractImplementor
{
	
public:
	void imp_operation() override 
	{
		// Do the real implementation specific work
	}	
};

class ConcreteImplementor_B: public AbstractImplementor
{
	void imp_operation() override 
	{
		// Do the real implementation specific work
	}	
};


class Abstraction
{
	std::shared_ptr<AbstractImplementor> implementation;	
	// Other data members...

public:
	virtual void operation()
	{
		// ...
		implementation->imp_operation();
		// ...
	}
};

int main() {}

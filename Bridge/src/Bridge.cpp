#include <memory>
#include <iostream>

// In Bridge we use object composition for implementations diversity


// Implementation part
//
// This is a class that provides abstracted from any particular implementation 
// set of operations to which a user of the system class can appeal via the Interface (Abstraction) 

class AbstractImplementor {
	// ...
public:
	virtual void imp_operation() = 0;
};

class ConcreteImplementor_A: public AbstractImplementor {
	// ...
public:
	void imp_operation() override 
	{
		// Do the real implementation specific work
	}	
};

class ConcreteImplementor_B: public AbstractImplementor {
	// ...
public:
	void imp_operation() override 
	{
		// Do the real implementation specific work
	}	
};


// Interface part
// 
// An abstracted high-level, user-accessible, controller class
// Which relies on the intentionnaly separate class hierarchy of Implementors to the job requested
// An implementor in turn builds upon the primitives provided by a particular implementation.

class Abstraction
{
	std::shared_ptr<AbstractImplementor> implementation;	
	// ...

public:
	virtual void operation()
	{
		// ...
		implementation->imp_operation();
	}
};

// These two add up to the class hierarchy of interfaces
class RefinedAbstraction_A : public Abstraction
{
	// Extended interface for the Abstraction
};

class RefinedAbstraction_B: public Abstraction 
{
	// Extended interface for the Abstraction
};

int main() {}

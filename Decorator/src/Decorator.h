class Component {
public:
	virtual void operation() = 0;
};

class ConcreteComponent: public Component {
public:
	virtual void operation() 
	{
		// Some basic behaviour
	}
};

class Decorator: public ConcreteComponent {
	// The poniter to the component which we decorate
	Component* component;
public:
	// Proxify the call to the operation to the Component
	virtual void operation() override
	{
		component->operation();
	}
};

class ConcreteDecoratorA: public Decorator {
public:
	virtual void operation() override
	{
		// Some augmented behaviour
	}
};

class ConcreteDecoratorB: public Decorator {
	// Some ugmented state
	int additional_state;
public:
	virtual void operation() override {}
};

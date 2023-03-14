#include <memory>

class Composite;

class Component 
{
public:
	Component() = default;
	virtual ~Component() = default;
	
	virtual void add(Component* comp) {}
	virtual void remove(Component* comp) {}

	virtual void operation() = 0;

	virtual Component* getChild(size_t i) const { return nullptr; }

	virtual Composite * GetComposite() { return nullptr; }

protected:
	Component* parent = nullptr;
	Component* child = nullptr;
};

class Composite: public Component 
{
public:
	virtual void add(Component* comp) {}
	virtual void remove(Component * comp) {}
	virtual void operation() {}

	virtual Component* getChild(size_t i) const { return nullptr; }

	virtual Composite * GetComposite() override { return this; }
};

class Leaf: public Component 
{
public:
	virtual void operation() {}
};


int main() 
{

	// GetComposite usage case
	Composite* composite = new Composite;
	Leaf* leaf = new Leaf;

	Component* component;
	Composite* test;

	component = composite;

	if (test = component->GetComposite())
		test->add(new Leaf);

	component = leaf;

	// component here is a leaf, so test will be a nullptr
	if (test = component->GetComposite())
		// Won't add leaf
		test->add(new Leaf);
}

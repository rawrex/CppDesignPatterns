#include <memory>

class Composite;

class Component {
protected:
	Component * parent;
	Component * child;
public:
	Component() = default;
	virtual ~Component() = default;

	virtual Composite * GetComposite() { return nullptr; }

};

class Composite: public Component {
public:
	void add(Composite * ptr) {}
	virtual Composite * GetComposite() override { return this; }
};

class Leaf: public Component {

};

int main() {

	Composite* composite = new Composite;
	Leaf* leaf = new Leaf;

	Component* component;
	Composite* test;

	component = composite;

	if (test = component->GetComposite())
		test->add(new Leaf);

	component = leaf;

	if (test = component->GetComposite())
		test->add(new Leaf);	// Won't add leaf

}

#include <memory>

class Composite;

class Component {
	Component * parent;
	Component * child;
public:
	Component() = default;
	virtual Composite * GetComposite() { return nullptr; }

};

class Composite: public Component {
public:
	void add(Composite * ptr) {}
	virtual Composite * GetComposite() override { return this; }
};

class Leaf: public Component {

};

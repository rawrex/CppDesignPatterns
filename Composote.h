#include <memory>

class Component {
	std::shared_ptr<Component> parent;
public:
	Component() = default;
};

class Composite: public Component {
		
};

class Leaf: public Component {

};

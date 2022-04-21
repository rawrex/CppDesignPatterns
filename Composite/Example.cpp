// Equipment such as computers and stereo components are often organized into
// part-whole or containment hierarchies
#include <list>
#include <string>

using Watt = long double;
using Currency = unsigned long long;

class Equipment {
public:
	virtual ~Equipment();

	std::string name() { return name_; }

	// Actual payload-functions of the pattern
	// Subclass(es) will implement these for a particular equipment
	virtual Watt power();
	virtual Currency netPrice();
	virtual Currency discountPrice();

	// Pattern management funcitons
	virtual void add(Equipment*);
	virtual void remove(Equipment*);
	//virtual Iterator<Equipment*>* createlterator();

protected:
	Equipment(const std::string & str_name) : name_(str_name) {}

private:
	std::string name_;

};


// A Leaf subclass
class FloppyDisk : public Equipment {
public:
	FloppyDisk(const std::string & str_name);
	virtual ~FloppyDisk();
	
	virtual Watt power();
	virtual Currency netPrice();
	virtual Currency discountPrice();
};


class CompositeEquipment : public Equipment {
public:
	virtual ~CompositeEquipment();
	virtual Watt Power();
	virtual Currency NetPrice();
	virtual Currency DiscountPrice();
	virtual void Add(Equipment*);
	virtual void Remove(Equipment*);
	//virtual Iterator<Equipment*>* Createlterator();
protected:
	CompositeEquipment(const char*);
private:
	std::list<Equipment*> _equipment;
};

int main () {}

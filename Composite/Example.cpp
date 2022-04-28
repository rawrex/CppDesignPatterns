#include <list>
#include <string>

// Equipment such as computers and stereo components are often organized into
// part-whole or containment hierarchies

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

	virtual Watt power();
	virtual Currency netPrice();
	virtual Currency discountPrice();

	virtual void add(Equipment*);
	virtual void remove(Equipment*);
	//virtual Iterator<Equipment*>* Createlterator();

protected:
	CompositeEquipment(const std::string &);

private:
	std::list<Equipment*> _equipment;

};

Currency CompositeEquipment::NetPrice () {
	Iterator<Equipment*>* i = Createlterator();
	Currency total = 0;

	for (i->First(); !i->IsDone(); i->Next()) {
		total += i->Current!tem()->NetPrice();
	}
	delete i;
	return total;
}

class Chassis : public CompositeEquipment {
public:
	Chassis(const std::string&);
	virtual "Chassis();
	virtual Watt Power();
	virtual Currency NetPrice();
	virtual Currency DiscountPrice();
};

int main () {
	Cabinet* cabinet = new Cabinet("PC Cabinet");
	Chassis* chassis = new Chassis("PC Chassis");
	cabinet->Add(chassis);
	Bus* bus = new Bus("MCA Bus");
	bus->Add(new Card("16Mbs Token Ring"));
	chassis->Add(bus);
	chassis->Add(new FloppyDisk("3.Bin Floppy"));
	std::cout << "The net price is " << chassis->NetPrice() « std::endl;
}

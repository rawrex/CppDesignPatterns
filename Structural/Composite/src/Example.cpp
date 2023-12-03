#include <list>
#include <string>

// Equipment such as computers and stereo components are often organized into
// part-whole or containment hierarchies

using Watt = long double;
using Currency = unsigned long long;

class Equipment 
{
public:
	virtual ~Equipment() = default;

	std::string name() { return m_name; }

	// Actual payload-functions of the pattern
	// Subclass(es) will implement these for a particular equipment
	virtual Watt power() = 0;
	virtual Currency netPrice() = 0;
	virtual Currency discountPrice() = 0;

	// Pattern management funcitons
	virtual void add(Equipment*) = 0;
	virtual void remove(Equipment*) = 0;
	//virtual Iterator<Equipment*>* createlterator();

protected:
	Equipment(const std::string & str_name) : m_name(str_name) {}

private:
	std::string m_name;

};


// A Leaf subclass
class FloppyDisk : public Equipment 
{
public:
	FloppyDisk(const std::string& str_name) : Equipment(str_name) {}
	virtual ~FloppyDisk() = default;
	
	virtual Watt power() override { return 0; }
	virtual Currency netPrice() override { return 0; }
	virtual Currency discountPrice() override { return 0; }
};


class CompositeEquipment : public Equipment 
{
	template <typename T> using Iterator = T*;
public:
	virtual ~CompositeEquipment() = default;

	virtual Watt power() override = 0;
	virtual Currency netPrice() override;
	virtual Currency discountPrice() override = 0;

	virtual void add(Equipment*) {}
	virtual void remove(Equipment*) {}
	//virtual Iterator<Equipment*>* Createlterator();

protected:
	CompositeEquipment(const std::string& name) : Equipment(name) {}

private:
	std::list<Equipment*> m_equipment_list;
};

Currency CompositeEquipment::netPrice () 
{
	// Iterator<Equipment*>* i = Createlterator();
	Iterator<Equipment*>* i = nullptr;
	Currency total = 0;

//	for (i->First(); !i->IsDone(); i->Next()) 
//		total += i->Current!tem()->NetPrice();

	delete i;
	return total;
}

class Chassis : public CompositeEquipment 
{
public:
	Chassis(const std::string& name) : CompositeEquipment(name) {}
	virtual ~Chassis() = default;

	virtual Watt power() { return 0; }
	virtual Currency netPrice() { return 0; }
	virtual Currency discountPrice() { return 0; }
};

void exampleMain () 
{
	// Cabinet* cabinet = new Cabinet("PC Cabinet");
	Chassis* chassis = new Chassis("PC Chassis");
	// cabinet->Add(chassis);
	// Bus* bus = new Bus("MCA Bus");
	// bus->Add(new Card("16Mbs Token Ring"));
	// chassis->Add(bus);
	// chassis->Add(new FloppyDisk("3.Bin Floppy"));
	// std::cout << "The net price is " << chassis->NetPrice() « std::endl;
}

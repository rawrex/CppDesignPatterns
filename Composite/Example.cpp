// Equipment such as computers and stereo components are often organized into
// part-whole or containment hierarchies

#include <string>

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
	virtual Iterator<Equipment*>* createlterator();

protected:
	Equipment(const std::string & str_name) : name(str_name) {}

private:
	std::string name_;

};

class FloppyDisk : public Equipment {
public:
	FloppyDisk(cosnt std::string & str_name);
	virtual ~FloppyDisk();
	
	virtual Watt power();
	virtual Currency netPrice();
	virtual Currency discountPrice();
};



#ifndef VICTIM_H
# define VICTIM_H
#include <iostream>

class Victim{
public:
	Victim(std::string name);
	Victim(Victim const & src);
	~Victim();
	Victim & operator=(Victim const& rhs);
	std::string getName() const;
	virtual void getPolymorphed() const;
protected:
	std::string _name;
private:
	Victim();
};
std::ostream & operator<<(std::ostream & o, Victim const & s);
#endif
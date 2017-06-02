
#include "Victim.hpp"

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" <<std::endl;
	return ;
}
Victim::Victim(Victim const & src)
{
	*this = src;
}
Victim::~Victim()
{
	std::cout << "Victim " << getName() <<" just died  for no apparent reason !" << std::endl;
}
Victim & Victim::operator=(Victim const& rhs)
{
	this->_name = rhs.getName();
	return *this;
}
std::string Victim::getName() const
{
	return (this->_name);
}

std::ostream & operator<<(std::ostream & o, Victim const & s)
{
	o <<"I'm " << s.getName() << " and I like otters !" << std::endl;
	return o;
}

void Victim::getPolymorphed() const
{
std::cout << this->getName()<<"  has been turned into a cute little sheep !" <<std::endl;
}
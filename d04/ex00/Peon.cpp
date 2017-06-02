
#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." <<std::endl;
}
Peon::Peon(Peon const & src) :Victim(src)
{
	*this = src;
}
Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}
Peon & Peon::operator=(Peon const& rhs)
{
	this->_name = rhs.getName();
	//this->setName(rhs.getName());
	return *this;
}
void Peon::getPolymorphed() const
{
	std::cout << this->getName()<<"  has been turned into a pink pony !" <<std::endl;
}


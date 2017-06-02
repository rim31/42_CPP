
#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << name <<", " << title <<", is born!" <<std::endl;
	return ;
}
Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
}
Sorcerer::~Sorcerer()
{
	std::cout << getName() <<", "<< getTitle() <<", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
	this->_name = rhs.getName();
	this->_title= rhs.getTitle();
	return *this;
}

std::string Sorcerer::getName() const
{
	return this->_name;
}

std::string Sorcerer::getTitle() const
{
	return this->_title;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & s)
{
	o <<"I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !" <<std::endl;
	return o;
}



void Sorcerer::polymorph(Victim const & ins) const
{
	ins.getPolymorphed();
}
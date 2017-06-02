
#ifndef SORCERER_H
#define SORCERER_H
#include <iostream>
#include "Peon.hpp"
#include "Victim.hpp"
class Sorcerer{
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & src);
	~Sorcerer();
	Sorcerer & operator=(Sorcerer const & rhs);
	std::string getName() const;
	std::string getTitle() const;
	void polymorph(Victim const & ins) const;
private:
	Sorcerer();
	std::string _name;
	std::string _title;
};
std::ostream & operator<<(std::ostream & o, Sorcerer const & s);
#endif
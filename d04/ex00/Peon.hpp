
#ifndef PEON_H
# define PEON_H
#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name);
	Peon(Peon const & src);
	~Peon();
	Peon & operator=(Peon const& rhs);
	virtual void getPolymorphed() const;

};
#endif

#include "Drone.hpp"
#include <cstdlib>

Drone::Drone( void ): ACharacter( '#', Point(0, 0), 1, 12 ) {
}

Drone::Drone( int y ): ACharacter( '#', Point(0, y), 1, 12 ) {
}

Drone::Drone( Drone const & src ): ACharacter(src) {
}

Drone::~Drone( void ) {
}

Drone &	Drone::operator=( Drone const & rhs ) {
	if ( this != &rhs ) {
		this->_hp = rhs.getHP();
		this->_look = rhs.getLook();
		this->_speed = rhs.getSpeed();
		this->_pos = rhs.getPosition();
		this->_missile = rhs.getMissile()->clone();
	}
	return *this;
}

IMissile *		Drone::shoot( void ) const {
	if ( this->_missile == 0 )
		return 0;

	IMissile *	missile = this->_missile->clone();
	missile->setPosition( Point( this->_pos.x, this->_pos.y + 1 ) );

	return missile;
}

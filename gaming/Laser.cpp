#include "Laser.hpp"

Laser::Laser( void ): GameObject( '|', Point(0, 0), 1 ),
	_dir(1), _damage(1) {
}

Laser::Laser( int dir ): GameObject( '|', Point(0, 0), 1 ),
	_dir(dir), _damage(1) {
}

Laser::Laser( Laser const & src ): GameObject( '|', Point(0, 0), 1 ) {
	this->_dir = src.getDir();
	this->_damage = src.getDamage();
}

Laser::~Laser( void ) {
}

Laser &	Laser::operator=( Laser const & rhs ) {
	if ( this != &rhs ){
		this->_pos.x = rhs.getPosition().x;
		this->_pos.y = rhs.getPosition().y;
		this->_dir = rhs.getDir();
		this->_damage = rhs.getDamage();
		this->_speed = rhs.getSpeed();
	}
	return *this;
}

int			Laser::getDir( void ) const {
	return this->_dir;
}

int			Laser::getDamage( void ) const {
	return this->_damage;
}

int			Laser::getSpeed( void ) const {
	return GameObject::getSpeed();
}

Point		Laser::getPosition( void ) const {
	return GameObject::getPosition();
}

IMissile *		Laser::clone( void ) const {
	return new Laser( *this );
}

void			Laser::setDir( int dir ) {
	this->_dir = dir;
}

void			Laser::setPosition( Point const & pos ) {
	GameObject::setPosition( pos );
}

void			Laser::move( void ) {
	GameObject::move( this->_dir, 0 );
}

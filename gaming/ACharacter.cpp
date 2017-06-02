#include "ACharacter.hpp"

ACharacter::ACharacter( void ): _hp(1), _missile(0) {
}

ACharacter::ACharacter( char look, Point pos, int hp, int speed ): GameObject( look, pos, speed ),
	_hp(hp), _missile(0) {
}

ACharacter::ACharacter( ACharacter const & src ) {
	this->_hp = src.getHP();
	this->_look = src.getLook();
	this->_speed = src.getSpeed();
	this->_pos = src.getPosition();
	this->_missile = src.getMissile()->clone();
}

ACharacter::~ACharacter( void ) {
	delete this->_missile;
}

ACharacter &	ACharacter::operator=( ACharacter const & rhs ) {
	if ( this != &rhs ) {
		this->_hp = rhs.getHP();
		this->_look = rhs.getLook();
		this->_speed = rhs.getSpeed();
		this->_pos = rhs.getPosition();
		this->_missile = rhs.getMissile()->clone();
	}
	return *this;
}

int				ACharacter::getHP( void ) const {
	return this->_hp;
}

IMissile *		ACharacter::getMissile( void ) const {
	return this->_missile;
}

void			ACharacter::takeDamage( int damage ) {
	this->_hp -= damage;
}

void			ACharacter::equip( IMissile * missile ){
	if ( missile )
		delete this->_missile;
	this->_missile = missile;
}

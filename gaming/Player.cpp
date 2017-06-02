#include "Player.hpp"

Player::Player( void ): ACharacter( 'o', Point(10, 10), 1, 1 ) {
	mvaddch( this->getPosition().x, this->getPosition().y - 1, '(' );
	mvaddch( this->getPosition().x, this->getPosition().y, 'o' );
	mvaddch( this->getPosition().x, this->getPosition().y + 1, ')' );
}

Player::Player( Player const & src ): ACharacter(src) {
}

Player::~Player( void ) {
}

Player &	Player::operator=( Player const & rhs ) {
	if ( this != &rhs ) {
		this->_hp = rhs.getHP();
		this->_look = rhs.getLook();
		this->_speed = rhs.getSpeed();
		this->_pos = rhs.getPosition();
		this->_missile = rhs.getMissile()->clone();
	}
	return *this;
}

IMissile *		Player::shoot( void ) const {
	if ( this->_missile == 0 )
		return 0;

	IMissile *	missile = this->_missile->clone();
	missile->setPosition( Point( this->_pos.x - 1, this->_pos.y ) );

	return missile;
}

void			Player::equip( IMissile * missile ){
	if ( missile ) {
		missile->setDir( -1 );
		ACharacter::equip( missile );
	}
}

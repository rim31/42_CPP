#include "GameObject.hpp"

GameObject::GameObject( void ): _look('#'), _pos(), _speed(1) {
}

GameObject::GameObject( char look, Point pos, int speed ):
	_look(look), _pos(pos.x, pos.y), _speed(speed) {
}

GameObject::GameObject( GameObject const & src ) {
	this->_look = src.getLook();
	this->setPosition( src.getPosition() );
}

GameObject::~GameObject( void ) {
}

GameObject &	GameObject::operator=( GameObject const & rhs ) {
	if ( this != &rhs ) {
		this->_look = rhs.getLook();
		this->_pos = rhs.getPosition();
	}
	return *this;
}

char	GameObject::getLook( void ) const {
	return this->_look;
}

Point	GameObject::getPosition( void ) const {
	return this->_pos;
}

int		GameObject::getSpeed( void ) const {
	return this->_speed;
}

void	GameObject::setPosition( Point const & pos ) {
	if ( this->_look == 'o' ) {
		mvaddch( this->_pos.x, this->_pos.y - 1, ' ' );
		mvaddch( this->_pos.x, this->_pos.y, ' ' );
		mvaddch( this->_pos.x, this->_pos.y + 1, ' ' );
	}
	else
		mvaddch( this->_pos.x, this->_pos.y, ' ' );
	this->_pos.x = pos.x;
	this->_pos.y = pos.y;
	if ( this->_look == 'o' ) {
		mvaddch( this->_pos.x, this->_pos.y - 1, '(' );
		mvaddch( this->_pos.x, this->_pos.y, 'o' );
		mvaddch( this->_pos.x, this->_pos.y + 1, ')' );
	}
	else
		init_pair(1, COLOR_YELLOW, COLOR_BLACK);
		start_color();
    attron(COLOR_PAIR(1));
		mvaddch( this->_pos.x, this->_pos.y, this->_look );
    attroff(COLOR_PAIR(1));
}

void	GameObject::move( int x, int y ) {
	if ( this->_look == 'o' ) {
		mvaddch( this->_pos.x, this->_pos.y - 1, ' ' );
		mvaddch( this->_pos.x, this->_pos.y, ' ' );
		mvaddch( this->_pos.x, this->_pos.y + 1, ' ' );
	}
	else
		mvaddch( this->_pos.x, this->_pos.y, ' ' );
	this->_pos.x += x;
	this->_pos.y += y;
	if ( this->_look == 'o' ) {
		mvaddch( this->_pos.x, this->_pos.y - 1, '(' );
		mvaddch( this->_pos.x, this->_pos.y, 'o' );
		mvaddch( this->_pos.x, this->_pos.y + 1, ')' );
	}
	else
		init_pair(1, COLOR_YELLOW, COLOR_BLACK);
		start_color();
		attron(COLOR_PAIR(1));
		mvaddch( this->_pos.x, this->_pos.y, this->_look );
		attroff(COLOR_PAIR(1));
}

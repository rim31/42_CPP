#include "GameWorld.hpp"
#include <iostream>

GameWorld::GameWorld( void ): _ennemies(0), _missiles(0), _score(0), _turn(0) {
	IMissile *	missile = new Laser();

	this->_player = new Player();
	this->_player->equip(missile);

	getmaxyx( stdscr, this->_maxX, this->_maxY );
}

GameWorld::GameWorld( GameWorld const & src ): _ennemies( src._ennemies ), _missiles( src._missiles ),
_player( src._player ),_score( src._score ), _turn( src._turn ) {
}

GameWorld::~GameWorld( void ) {
	List *			cur;
	List *			next;

	delete _player;

	cur = this->_ennemies;
	while ( cur ) {
		next = cur->next;
		delete (ACharacter*)cur->content;
		delete cur;
		cur = next;
	}

	cur = this->_missiles;
	while ( cur ) {
		next = cur->next;
		delete (IMissile*)cur->content;
		delete cur;
		cur = next;
	}
}

GameWorld &	GameWorld::operator=( GameWorld const & rhs ) {
	if ( this != &rhs ){
		this->_ennemies = rhs._ennemies;
		this->_missiles = rhs._missiles;
		this->_player = rhs._player;
		this->_score = rhs._score;
		this->_turn = rhs._turn;
	}
	return *this;
}

int		GameWorld::takeTurn( void ) {
	move(0,0);
	printw("Vie : %d | Score : %d", this->_player->getHP(), this->_score);

	if ( this->bonuswindow() == false )
		return 2;

	this->addEnnemies();

	if ( this->movePlayer() == false )
		return 3;

	if ( this->checkColisions() == false )
		return 1;

	this->moveEnnemies();
	if ( this->checkColisions() == false )
		return 1;

	this->moveMissiles();
	if ( this->checkColisions() == false )
		return 1;

	this->_turn = ( this->_turn + 1 ) % 12;

	return 0;
}

bool	GameWorld::movePlayer( void ) {
	IMissile *	missile;
	int			ch, x, y;

	x = this->_player->getPosition().x;
	y = this->_player->getPosition().y;

	ch = getch();
	if ( ch == 27 )
		return false;

	if ( this->_turn % this->_player->getSpeed() == 0 ) {
		if( ch == KEY_LEFT && y > 0 )
			this->_player->move( 0, -1 );
		else if(ch == KEY_RIGHT && y < (this->_maxY - 1))
			this->_player->move( 0, 1 );
		else if(ch == KEY_UP && x > 0)
			this->_player->move( -1, 0 );
		else if(ch == KEY_DOWN && x < ( this->_maxX - 1))
			this->_player->move( 1, 0 );
		else if(ch == 32) {
			missile = this->_player->shoot();
			if ( missile )
				this->_missiles->push( &(this->_missiles), missile );
		}
	}
	return true;
}

void	GameWorld::moveEnnemies( void ) {
	List *			cur;
	ACharacter *	ennemy;

	cur = this->_ennemies;
	while ( cur ) {
		ennemy = (ACharacter *)cur->content;
		if (this->_turn % ennemy->getSpeed() == 0 )
			ennemy->move( 1, 0 );
		cur = cur->next;
		if (ennemy->getPosition().x > this->_maxX)
		{
			ennemy->setPosition( Point( 0, ennemy->getPosition().y ) ) ;
		}
	}
}

void	GameWorld::moveMissiles( void ) {
	List *		cur;
	IMissile *	missile;

	cur = this->_missiles;
	while ( cur ) {
		missile = (IMissile *)cur->content;
		if (this->_turn % missile->getSpeed() == 0 )
			missile->move();
		cur = cur->next;
	}
}

void	GameWorld::addEnnemies( void ) {
	List *			cur;
	ACharacter *	ennemy;

	cur = this->_ennemies;
	while ( cur ) {
		cur = cur->next;
	}
	if((std::rand() % 100) > 98)
	{
		Drone * d = new Drone( std::rand() % this->_maxY );
		_ennemies->push( &_ennemies, d);
	}
}

bool	GameWorld::checkColisions( void ) {
	List *			curEnn;
	List *			curMis;
	List *			nextEnn;
	List *			nextMis;
	ACharacter *	ennemy;
	IMissile *		missile;

	curEnn = this->_ennemies;
	while ( curEnn ) {
		nextEnn = curEnn->next;
		ennemy = (ACharacter *)curEnn->content;
		if ( ennemy->getPosition() == _player->getPosition() )
			return false;
			if (ennemy->getPosition() == _player->getPosition() ||
			(ennemy->getPosition().x == _player->getPosition().x &&
			ennemy->getPosition().y == _player->getPosition().y - 1) ||
			(ennemy->getPosition().x == _player->getPosition().x &&
			 ennemy->getPosition().y == _player->getPosition().y + 1))
			{
				endwin();
				std::cout << "PERDU !" << std::endl;
				exit(0);
			}
		curMis = this->_missiles;
		while ( curMis ) {
			nextMis = curMis->next;
			missile = (IMissile *)curMis->content;
			if ( ennemy->getPosition() == missile->getPosition() ) {
				ennemy->takeDamage( missile->getDamage() );
				this->_missiles->remove( &(this->_missiles), missile );
				delete missile;
				mvaddch( ennemy->getPosition().x, ennemy->getPosition().y, ' ' );
				this->_score++;
				if ( ennemy->getHP() <= 0 ) {
					this->_ennemies->remove( &(this->_ennemies), ennemy );
					delete ennemy;
				}
				break;
			}
			curMis = nextMis;
		}
		curEnn = nextEnn;
	}
	return true;
}


bool 	GameWorld::bonuswindow(void)
{
	getmaxyx(stdscr, this->_maxX, this->_maxY );
	if (this->_maxY < 20 || this->_maxY < 50) {
		endwin();
		std::cout << "ECRAN TROP PETIT => auto destruction" << std::endl;
		return false;
	}
	return true;
}
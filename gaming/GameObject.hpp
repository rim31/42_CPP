#ifndef GAMEOBJECT_H
# define GAMEOBJECT_H

# include <ncurses.h>
# include "Structs.hpp"

class GameObject {
	public:
		GameObject( void );
		GameObject( char look, Point pos, int speed );
		GameObject( GameObject const & src );
		virtual ~GameObject( void );

		GameObject &	operator=( GameObject const & rhs );

		void	setPosition( Point const & pos );
		char	getLook( void ) const;
		Point	getPosition( void ) const;
		int		getSpeed( void ) const;
		void	move( int x, int y );

	protected:
		char	_look;
		Point	_pos;
		int		_speed;
};

#endif
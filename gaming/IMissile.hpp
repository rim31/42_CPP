#ifndef IMissile_H
# define IMissile_H

# include "Structs.hpp"

class IMissile {
	public:
		virtual ~IMissile( void ) {}
		virtual int			getDir( void ) const = 0;
		virtual int			getDamage( void ) const = 0;
		virtual int			getSpeed( void ) const = 0;
		virtual Point		getPosition( void ) const = 0;
		virtual IMissile *	clone( void ) const = 0;
		virtual void		setDir( int dir ) = 0;
		virtual void		setPosition( Point const & pos ) = 0;
		virtual void		move( void ) = 0;
};

#endif
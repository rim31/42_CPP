#ifndef LASER_H
# define LASER_H

# include "IMissile.hpp"
# include "GameObject.hpp"
# include "Structs.hpp"

class Laser: public IMissile, public GameObject {
	public:
		Laser( void );
		Laser( int dir );
		Laser( Laser const & src );
		~Laser( void );

		Laser &	operator=( Laser const & rhs );

		int			getDir( void ) const;
		int			getDamage( void ) const;
		int			getSpeed( void ) const;
		Point		getPosition( void ) const;
		IMissile *	clone( void ) const;
		void		setDir( int dir );
		void		setPosition( Point const & pos );
		void		move( void );

	private:
		int		_dir;
		int		_damage;
		int		_speed;
};

#endif

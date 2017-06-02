#ifndef DRONE_H
# define DRONE_H

# include "ACharacter.hpp"
# include "IMissile.hpp"

class Drone: public ACharacter {
	public:
		Drone( void );
		Drone( int y );
		Drone( Drone const & src );
		~Drone( void );

		Drone &	operator=( Drone const & rhs );

		IMissile *	shoot( void ) const;
};

#endif

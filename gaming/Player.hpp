#ifndef PLAYER_H
# define PLAYER_H

# include "ACharacter.hpp"
# include "IMissile.hpp"

class Player: public ACharacter {
	public:
		Player( void );
		Player( Player const & src );
		~Player( void );

		Player &	operator=( Player const & rhs );

		IMissile *	shoot( void ) const;
		void		equip( IMissile * missile );
};

#endif

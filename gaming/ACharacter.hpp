#ifndef ACHARACTER_H
# define ACHARACTER_H

# include "GameObject.hpp"
# include "IMissile.hpp"
# include "Structs.hpp"

class ACharacter: public GameObject {
	public:
		ACharacter( void );
		ACharacter( char look, Point pos, int hp, int speed );
		ACharacter( ACharacter const & src );
		virtual ~ACharacter( void );

		ACharacter &	operator=( ACharacter const & rhs );

		int					getHP( void ) const;
		IMissile *			getMissile( void ) const;
		virtual IMissile *	shoot( void ) const = 0;
		void				takeDamage( int damage );
		virtual void		equip( IMissile * missile );

	protected:
		int			_hp;
		IMissile *	_missile;
};

#endif
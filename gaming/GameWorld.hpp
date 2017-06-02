#ifndef GAMEWORLD_H
# define GAMEWORLD_H

# include "GameObject.hpp"
# include "ACharacter.hpp"
# include "Drone.hpp"
# include "Player.hpp"
# include "Laser.hpp"
//# include "Torpedo.hpp"
# include "Structs.hpp"
# include <ncurses.h>
# include <cstdlib>

class	GameWorld {
	public:
		GameWorld( void );
		GameWorld( GameWorld const & src );
		~GameWorld( void );

		GameWorld &	operator=( GameWorld const & rhs );

		int		takeTurn( void );
		int		getScore( void ) const;

	private:
		List *		_ennemies;
		List *		_missiles;
		Player *	_player;
		int			_score;
		int			_turn;
		int			_maxX;
		int			_maxY;

		bool	movePlayer( void );
		void	moveEnnemies( void );
		void	moveMissiles( void );
		bool	checkColisions( void );
		void	addEnnemies( void );
		bool	bonuswindow(void);
};

#endif

#include <ncurses.h>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include "ft_retro.hpp"


void init_screen() {
	//initialiation de la fenetre de jeu
	initscr();
	noecho();
	raw();
	curs_set(0);
//	nodelay(w->window, TRUE);
}

int	main( void ) {
	int	state = 0;
	std::srand(std::time(0));
	init_screen();
	timeout(0);
	keypad(stdscr, true);

	GameWorld *	world = new GameWorld();

	while ( state == 0 ) {
		state = world->takeTurn();
		usleep(5000);
		refresh();
	}

	delete world;

	endwin();

	if ( state == 1 )
		std::cout << "YOU LOSE !" << std::endl;
	else if ( state == 2 )
		std::cout << "ECRAN TROP PETIT => auto destruction" << std::endl;
	else if ( state == 3 )
		std::cout << "See you later astronaut :)" << std::endl;

	return 0;
}
#ifndef FT_RETRO_HPP
#define FT_RETRO_HPP

#include <curses.h>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

#include "GameWorld.hpp"
#include "GameObject.hpp"
#include "ACharacter.hpp"
#include "Drone.hpp"
#include "Imissile.hpp"
#include "Player.hpp"
#include "Structs.hpp"
#include "Laser.hpp"

typedef struct  s_wind {
//  WINDOW*       window;
  int           maxX;
  int           maxY;
  time_t        myTime;
  int           row;
  int           col;
  int           life;
  int           score;
  GameObject    *GameObject;
  ACharacter    *ACharacter;
  Drone         *Drone;
  // Laser         *Laser;
  Player        *player;
  Point         *Point;
  int           x[3];
  int           y[3];
}               t_win;

void init_screen(t_win *w);
void mvt(char main_char, int row, int col, int ch);
void game_loop(char main_char1, char main_char2, char main_char3, int ch, t_win *w);
void ft_run(t_win *w, Drone *d);


#endif

#include "ft_retro.hpp"

void ft_collision(t_win *w) {
  int i = 1;
  // move(w->row, w->col);
  // printw("row : %d col: %d", w->row, w->col);
  if ((w->col == w->y[i]) && w->row == w->x[i])
  {
    clear();
    std::cout << "BOUM !"<<std::endl;
    printw("PERDU");
    refresh();
    endwin();
    putchar('!');
    exit(0);
  }
}

// pour l'asteroid
/*
  numero de l'ateroid
  pos x
  pos y
  vie ou existe
*/
void ft_run(t_win *w, Drone *d)
{
  move(0,0);
  int i = 0;
  printw("Vie : %d | Score : %d", w->life, w->score);
  init_pair(1, COLOR_GREEN, COLOR_BLACK);

  while(i <= 1)
  {
    if (d->getPosition().y > w->maxY)
    {
      if((rand() % 99) > 97)//pour rarifier les etoiles
      {
        // w->x[i] = rand() % w->maxX;
        // w->y[i] = 0;
        d->setPosition(Point (rand() % w->maxX, 0));
      }
    }
    // mvaddch(w->y[i] - 1, w->x[i], ' ');
    mvaddch(d->getPosition().y-1, d->getPosition().x,' ');

    start_color();
    attron(COLOR_PAIR(1));
    // mvaddch(w->y[i], w->x[i], '*');
    mvaddch(d->getPosition().y, d->getPosition().x, d->getLook() );
    attroff(COLOR_PAIR(1));
    // move(w->y[i], w->x[i]);
    // printw("row : %d col: %d", w->y[i], w->x[i] + 3);
    usleep(4000);
    //w->y[i]++;
    d->setPosition(Point (d->getPosition().x, d->getPosition().y + 1));
    i++;
    ft_collision(w);
  }
}
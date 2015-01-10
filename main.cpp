#include "Game.class.hpp"
#include "Map.class.hpp"
#include "Square.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"

#include <cstdlib>
#include <cerrno>
// extern "C"
// {
  #include <ncurses.h>
// }

typedef void (*f_atexit)(void);

bool initNcurses(void)
{
  WINDOW* win;
  bool    has_color;

  (void)win;
  (void)has_color;
  if ((win = initscr()) == NULL) {
    return false;
  }
  if (has_colors() && start_color() != ERR) {
    has_color = true;
  }

  // if (cbreak() == ERR) { // disable buffering + kill
  //   return false;
  // }

  // if (noecho() == ERR) { // disabled echo
  //   return false;
  // }

  // if (nonl() == ERR) { // disable newline on input
  //   return false;
  // }

  // if (keypad(tdscr, true) == ERR) { // enable keypads input
  //   return false;
  // }

  if (curs_set(0) == ERR) { // invisible cursor
    return false;
  }

  atexit((f_atexit)&endwin); // clear ncurses at exit
  return true;
}

void startGame(void)
{
  Game game;

  (void)clear();
  std::cout << game;
  do
  {
    // (void)clear();
    // DO ACTIONS
    // std::cout << game;
  } while (42);
  // } while (game.frame() != Game::END);
}

int main(void)
{
  Game   game;

  if (!initNcurses())
  {
    std::cout << "Could not initialize ncurses"<< std::endl;
    return errno;
  }
  startGame();

  return 0;
}

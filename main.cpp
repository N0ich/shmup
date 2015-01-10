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
  #include <sys/select.h>
  #include <sys/types.h>
  #include <sys/uio.h>
  #include <unistd.h>
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

  if (cbreak() == ERR) { // disable buffering + disable DEL
    return false;
  }

  if (noecho() == ERR) { // disable echo
    return false;
  }

  if (nonl() == ERR) { // disable newline on input
    return false;
  }

  if (keypad(stdscr, true) == ERR) { // enable keypads input
    return false;
  }

  if (curs_set(0) == ERR) { // invisible cursor
    return false;
  }

  if (nodelay(stdscr, true) == ERR) { // input non-blocking
    return false;
  }

  atexit((f_atexit)&endwin); // clear ncurses at exit
  return true;
}

void startGame(void)
{
  Game game;
  int  key;

  do
  {
    key = wgetch(stdscr);
    if (key == KEY_END || key == KEY_EXIT) {
      exit(0);
    }

    // IN A NEAR FUTURE HANDLE THIS IN AN ARRAY OF ORDERS
    if (key == KEY_LEFT || key == KEY_RIGHT)
    {
      // ORDER MOVE SHIP
    }

    if (true) // GAME STATE CHANGED
    {
      (void)clear();
      std::cout << game;
      // SET GAME STATE UNCHANGED
    }
  } while (game.frame() != Game::END);
}

int main(void)
{
  Game   game;

  if (!initNcurses())
  {
    std::cout << "Could not initialize ncurses" << std::endl;
    return errno;
  }
  startGame();

  return 0;
}

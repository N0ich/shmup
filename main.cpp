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


  if (initscr() == NULL) {
    return false;
  }
  (void)atexit((f_atexit)&endwin); // clear ncurses at exit

  if (has_colors() && start_color() == ERR)
  {
    if (
      init_pair(Player::COLOR_PAIR, COLOR_GREEN, COLOR_BLACK) == ERR || 
      init_pair(Enemy::COLOR_PAIR, COLOR_RED, COLOR_BLACK) == ERR
    ) {
      return false;
    }
    return false;
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

  if (scrollok(stdscr, false) == ERR) { // do not scroll on new line
    return false;
  }

  return true;
}

void startGame(void)
{
  Game game;
  int  key;

  do
  {
    { // GAME HANDLER
      key = wgetch(stdscr);
      if (key == KEY_END || key == KEY_EXIT) {
        exit(0);
      }

      // IN A NEAR FUTURE HANDLE THIS IN AN ARRAY OF ORDERS
      if (key == KEY_LEFT || key == KEY_RIGHT)
      {
      // ORDER MOVE SHIP
      }
    }

    if (game.needRefresh())
    {
      (void)clear();
      game.output();
    }
  } while (game.frame() != Game::END);
}

int main(void)
{
  Game   game;

  if (!initNcurses())
  {
    std::cout << "Could not fully initialize ncurses" << std::endl;
    return errno;
  }
  startGame();

  return 0;
}

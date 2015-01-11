#include "Game.class.hpp"
#include "Map.class.hpp"
#include "Square.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"

#include <ctime>
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

bool initNcurses(WINDOW** score_win, WINDOW** game_win)
{


  if (initscr() == NULL) {
    return false;
  }
  (void)atexit((f_atexit)&endwin); // clear ncurses at exit

  if (has_colors() && start_color() == ERR) {
    return false;
  }

  if (
    init_pair(Player::COLOR_PAIR, COLOR_GREEN, COLOR_BLACK) == ERR || 
    init_pair(Enemy::COLOR_PAIR, COLOR_RED, COLOR_BLACK) == ERR ||
    init_pair(Projectile::COLOR_PAIR, COLOR_YELLOW, COLOR_BLACK) == ERR
    ) {
    return false;
  }

  if (cbreak() == ERR) { // disable { (buffering + disable DEL) }
    return false;
  }

  if (noecho() == ERR) { // disable { echo }
    return false;
  }

  if (nonl() == ERR) { // invisible { newline input }
    return false;
  }

  if (keypad(stdscr, true) == ERR) { // enable { keypads input }
    return false;
  }

  if (curs_set(0) == ERR) { // invisible { cursor }
    return false;
  }

  if (nodelay(stdscr, true) == ERR) { // input non-blocking
    return false;
  }

  if (scrollok(stdscr, false) == ERR) { // do not scroll on new line
    return false;
  }

  if ((*score_win = newwin(1, Map::X + 1, 1, 1)) == NULL) {
    return false;
  }

  if ((*game_win = newwin(Map::Y + 1, Map::X + 1, 2, 1)) == NULL) {
    return false;
  }

  return true;
}

void startGame(WINDOW* score_win, WINDOW* game_win)
{
  Game game;
  int  key;

  (void)score_win;
  (void)game_win;
  do
  {
    { // GAME HANDLER
      key = wgetch(stdscr);
      if (key == KEY_END || key == KEY_EXIT) {
        exit(0);
      }

      // IN A NEAR FUTURE HANDLE THIS IN AN ARRAY OF ORDERS
      if (key == KEY_LEFT || key == 'a') {
        game.getPlayer().setOrder(MOVE_LEFT);
      }
      else if (key == KEY_RIGHT || key == 'd') {
        game.getPlayer().setOrder(MOVE_RIGHT);
      }
    }


    if (game.needRefresh())
    {
      (void)wmove(score_win, 0, 0);
      (void)wprintw(score_win, "SCORE %d           HP %d\n", game.getScore(), game.getPlayer().getCHP());

      (void)wborder(game_win, '|', '|', '-', '-', '+', '+', '+', '+');
      game.output(game_win);

      (void)wrefresh(game_win);
      (void)wrefresh(score_win);
    }
    usleep(5000);
    key = 0;
  } while (game.frame() != Game::END);
}

int main(void)
{
  WINDOW* score_win;
  WINDOW* game_win;

  srand(time(NULL));
  if (!initNcurses(&score_win, &game_win))
  {
    std::cout << "Could not fully initialize ncurses" << std::endl;
    return errno;
  }
  startGame(score_win, game_win);

  return 0;
}

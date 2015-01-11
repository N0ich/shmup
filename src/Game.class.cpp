#include "Game.class.hpp"
#include "Pos.class.hpp"
#include <ncurses.h>
#include <cstdlib>

// constructors + destructors

const unsigned int Game::CYCLE_MAX = 10;
const unsigned int Game::ENEMY_MAX = 8;
const bool         Game::END       = false;

Game::Game(void) :
  _map(), _cycle(0), _refresh(true), _score(0), _player(), _nb_enemy(0)
{
  this->_enemy = new Enemy*[Game::ENEMY_MAX];
  for (unsigned int n = 0; n < Game::ENEMY_MAX; ++n) {
    this->_enemy[n] = NULL;
  }

  this->getMap().getSquare(this->_player.getPos()).setEntity(&this->_player);

  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Game()" << std::endl;
  #endif
}

Game::Game(const Game& src) :
  _map(), _cycle(0), _refresh(true), _score(0), _player(), _nb_enemy(0)
{
  (void)src;
  this->_enemy = new Enemy*[Game::ENEMY_MAX];
  for (unsigned int n = 0; n < Game::ENEMY_MAX; ++n) {
    this->_enemy[n] = NULL;
  }
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Game()" << std::endl;
  #endif
}

Game::~Game(void)
{
  for (unsigned int n = 0; n < Game::ENEMY_MAX; ++n) {
    delete this->_enemy[n];
  }
  delete this->_enemy;
  #ifdef DEBUG
  std::cout << "[DESTRUCTED] Game()" << std::endl;
  #endif
}

// OPERATORS

Game&              Game::operator=(const Game& src)
{
  (void)src;
  return *this;
}

// FUNCTIONS

bool               Game::frame(void)
{
  if (false) {
    return Game::END;
  }

  if (this->_player.getOrder() != NONE)
  {
    if (this->_player.getOrder() == MOVE_LEFT)
    {
      Pos old_pos = this->_player.getPos();

      if (old_pos.x > 0)
      {
        this->_player.move(-1);
        this->getMap().getSquare(old_pos).setEntity(NULL);
        this->getMap().getSquare(this->_player.getPos()).setEntity(&this->_player);
      }
    }
    else if (this->_player.getOrder() == MOVE_RIGHT)
    {
      Pos old_pos = this->_player.getPos();

      if (old_pos.x < Map::X - 1)
      {
        this->_player.move(1);
        this->getMap().getSquare(old_pos).setEntity(NULL);
        this->getMap().getSquare(this->_player.getPos()).setEntity(&this->_player);
      }
    }
    this->_player.setOrder(NONE);
  }

  this->spawnEnemy();
  for (unsigned int i = 0; i < this->_nb_enemy; i ++)
  {
    Enemy*       enemy      = this->getEnemy(i);
    Pos          old_pos    = enemy->getPos();
    bool         do_refresh = true;

    if (enemy->move() == true)
    {
      if (enemy->getX() >= Map::X || enemy->getY() >= Map::Y)
      { // CHECK IF OUT OF THE MAP
        this->getMap().getSquare(old_pos).setEntity(NULL);
        this->deleteEnemy(*enemy);
        --i;
        do_refresh = false;
      }
      else
      {
        // RESET SQUARE
        this->getMap().getSquare(old_pos).setEntity(NULL);
        if (this->getMap().getSquare(enemy->getpos()).getEntity() != NULL)
        { // COLLISION
          this->deleteEnemy(*enemy);
          --i;
          do_refresh = false;
        }
        else
        { // MOVE
          this->getMap().getSquare(enemy->getPos()).setEntity(enemy);
          this->_refresh = true;
        }
      }
    }
    if (do_refresh) {
      enemy->refreshMove();
    }
  }
  // DO ACTIONS
  this->updateCycle();
  return ~Game::END;
}

void               Game::spawnEnemy(void)
{  Enemy *          enemy;

  if (this->_nb_enemy >= Game::ENEMY_MAX) {
	  return;
  }

  unsigned int n = 0;
  unsigned int x;

  for (x = 0; x < Map::X; ++x)
  {
	  if (this->getMap().getSquare(Pos(x, 0)).getEntity() == NULL) {
		  ++n;
	  }
  }
  if (n < 1)
	  return;
  unsigned int i;

  x = 0;
  for (i = rand() % n; i > 0;)
  {
	  if (this->getMap().getSquare(Pos(x, 0)).getEntity() == NULL) {
		  i--;
	  }
	  if (i > 0 && ++x == Map::X) {
		  x = 0;
	  }
  }

  enemy = new Enemy(Pos(x, 0));
  this->_enemy[this->_nb_enemy++] = enemy;
  this->getMap().getSquare(Pos(x, 0)).setEntity(enemy);
  this->_refresh = true;
}

void               Game::deleteEnemy(Enemy& enemy)
{
  unsigned int idx;

  idx = this->getEnemyIdx(enemy);
  if (idx == Game::ENEMY_MAX) {
    return;
  }
  // this->getSquare(Pos(x, y)).setEntity(NULL);
  delete this->_enemy[idx];
  this->_enemy[idx] = NULL;
  while (++idx < this->_nb_enemy)
  {
    this->_enemy[idx - 1] = this->_enemy[idx];
    this->_enemy[idx] = NULL;
  }
  --this->_nb_enemy;
}

void               Game::output(void)
{
  this->_refresh = false;
  (void)wmove(stdscr, 0, 0);
  this->getMap().output();
}

// GETTERS + SETTERS

unsigned int       Game::getCycle(void) const
{
  return this->_cycle;
}

void               Game::updateCycle(void)
{
  if (++this->_cycle >= Game::CYCLE_MAX) {
    this->_cycle = 0;
  }
}

Player&            Game::getPlayer(void)
{
  return this->_player;
}

const Player&      Game::getPlayer(void) const
{
  return this->_player;
}

Map&               Game::getMap(void)
{
  return this->_map;
}

const Map&         Game::getMap(void) const
{
  return this->_map;
}

Enemy*             Game::getEnemy(unsigned int idx) const
{
  return this->_enemy[idx];
}

unsigned int       Game::getEnemyIdx(Enemy& enemy) const
{
  unsigned int idx;

  for (idx = 0; idx < _nb_enemy; ++idx) {
    if (&enemy == this->_enemy[idx]) {
      return idx;
    }
  }
  return Game::ENEMY_MAX;
}

bool               Game::needRefresh(void) const
{
  return this->_refresh;
}

// MAGIC GETTERS + SETTERS

Square&            Game::getSquare(const Pos pos)
{
  return this->getMap().getSquare(pos);
}

const Square&      Game::getSquare(const Pos pos) const
{
  return this->getMap().getSquare(pos);
}

#include "Game.class.hpp"

// constructors + destructors

const unsigned int Game::CYCLE_MAX = 10;
const unsigned int Game::ENEMY_MAX = 20;
const bool         Game::END       = false;

Game::Game(void) :
  _map(), _cycle(0), _player(), _nb_enemy(0)
{
  this->_enemy = new Enemy*[Game::ENEMY_MAX];
  for (unsigned int n = 0; n < Game::ENEMY_MAX; ++n) {
    this->_enemy[n] = NULL;
  }

  // @todo: really do it, for real
  // unsigned int x = Map::X / 2;
  // unsigned int y = Map::Y / 2;

  // this->_player.setX(Map::X / 2);
  // this->_player.setX(Map::Y / 2);
  this->getMap().getSquare(Map::X / 2, Map::Y / 2).setEntity(this->_player);

  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Game()" << std::endl;
  #endif
}

Game::Game(const Game& src) :
  _map(), _cycle(0), _player(), _nb_enemy(0)
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

// operators

Game&              Game::operator=(const Game& src)
{
  (void)src;
  return *this;
}

// functions

bool               Game::frame(void)
{
  if (false) {
    return Game::END;
  }
  return ~Game::END;
}

void               Game::spawnEnemy(void)
{
  Enemy*           enemy;

  if (this->_nb_enemy >= Game::ENEMY_MAX) {
    return;
  }
  enemy = new Enemy();
  this->_enemy[this->_nb_enemy++] = enemy;
  // this->getMap().getSquare(x, y).setEntity(*enemy);
}

void               Game::deleteEnemy(Enemy& enemy)
{
  unsigned int idx;

  idx = this->getEnemyIdx(enemy);
  if (idx == Game::ENEMY_MAX) {
    return;
  }
  // this->getSquare(x, y).setEntity(NULL);
  delete this->_enemy[idx];
  this->_enemy[idx] = NULL;
  while (++idx < this->_nb_enemy)
  {
    this->_enemy[idx - 1] = this->_enemy[idx];
    this->_enemy[idx] = NULL;
  }
  --this->_nb_enemy;
}

// getters + setters

unsigned int       Game::getCycle(void) const
{
  return this->_cycle;
}

void               Game::updateCycle(void)
{
  if (++this->_cycle >= Game::CYCLE_MAX) {
    this->_cycle = 0;
  }
  // DO NO ACTION HERE
}

Player&            Game::getPlayer(void)
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

// @todo: move the actual stuff in an output function (which handles ncurses and raw as DEBUG)
std::ostream&      operator<<(std::ostream& stream, const Game& obj)
{
  // @todo: show score
  stream << obj.getMap();
  // @todo: show additionnal infos
  return stream;
}

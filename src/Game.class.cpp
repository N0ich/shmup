// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 15:34:29 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 16:45:05 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.class.hpp"
#include "Pos.class.hpp"
#include <ncurses.h>
#include <cstdlib>

// constructors + destructors

const unsigned int Game::CYCLE_MAX = 10;
const unsigned int Game::ENEMY_MAX = 8;
const unsigned int Game::PROJECTILE_MAX = 1;
const bool         Game::END       = false;

Game::Game(void) :
	_map(), _cycle(0), _refresh(true), _score(0), _player(Map::X / 2, Map::Y - 1),
	_nb_enemy(0), _nb_projectile(0)
{
  this->_projectile = new Projectile*[Game::PROJECTILE_MAX];
  this->_enemy = new Enemy*[Game::ENEMY_MAX];
  for (unsigned int n = 0; n < Game::ENEMY_MAX; ++n) {
    this->_enemy[n] = NULL;
  }
  for (unsigned int k = 0; k < Game::PROJECTILE_MAX; ++k) {
    this->_projectile[k] = NULL;
  }
 
  // @todo: really do it, for real
  // unsigned int x = Map::X / 2;
  // unsigned int y = Map::Y / 2;

  // this->_player.setX(Map::X / 2);
  // this->_player.setX(Map::Y / 2);
  this->getMap().getSquare(Map::X / 2, Map::Y - 1).setEntity(&this->_player);

  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Game()" << std::endl;
  #endif
}

Game::Game(const Game& src) :
  _map(), _cycle(0), _refresh(true), _score(0), _player(),
  _nb_enemy(0), _nb_projectile(0)
{
  (void)src;
  this->_projectile = new Projectile*[Game::PROJECTILE_MAX];
  this->_enemy = new Enemy*[Game::ENEMY_MAX];
  for (unsigned int n = 0; n < Game::ENEMY_MAX; ++n) {
    this->_enemy[n] = NULL;
  }
  for (unsigned int k = 0; k < Game::PROJECTILE_MAX; ++k) {
    this->_projectile[k] = NULL;
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
  for (unsigned int k = 0; k < Game::PROJECTILE_MAX; ++k) {
    delete this->_projectile[k];
  }
  delete this->_projectile;
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
  this->spawnProjectile();
  for (unsigned int j = 0; j < this->_nb_projectile; j ++)
  {
	Projectile*  projectile = this->getProjectile(j);
    unsigned int oldX       = projectile->getX();
    unsigned int oldY       = projectile->getY();

    if (projectile->move() == true)
    {
      if (projectile->getY() <= 0)
      { // CHECK IF OUT OF THE MAP
        this->getMap().getSquare(oldX, oldY).setEntity(NULL);
        this->deleteProjectile(*projectile);
        --j;
      }
      else
      {
        // RESET SQUARE
        this->getMap().getSquare(oldX, oldY).setEntity(NULL);
        if (&this->getMap().getSquare(projectile->getX(), projectile->getY())
			.getEntity() != NULL)
        { // COLLISION
          this->deleteProjectile(*projectile);
          --j;
        }
        else
        { // MOVE
          this->getMap().getSquare(projectile->getX(), projectile->getY())
			  .setEntity(projectile);
        }
      }
    }
	this->getPlayer().refreshShoot();
	projectile->refreshMove();
  }
  this->spawnEnemy();
  for (unsigned int i = 0; i < this->_nb_enemy; i ++)
  {
    Enemy*       enemy      = this->getEnemy(i);
    unsigned int old_x      = enemy->getX();
    unsigned int old_y      = enemy->getY();
    bool         do_refresh = true;

    if (enemy->move() == true)
    {
      if (enemy->getX() >= Map::X || enemy->getY() >= Map::Y)
      { // CHECK IF OUT OF THE MAP
        this->getMap().getSquare(old_x, old_y).setEntity(NULL);
        this->deleteEnemy(*enemy);
        --i;
        do_refresh = false;
      }
      else
      {
        // RESET SQUARE
        this->getMap().getSquare(old_x, old_y).setEntity(NULL);
        if (&this->getMap().getSquare(enemy->getX(), enemy->getY()).getEntity() != NULL)
        { // COLLISION
          this->deleteEnemy(*enemy);
          --i;
          do_refresh = false;
        }
        else
        { // MOVE
          this->getMap().getSquare(enemy->getX(), enemy->getY()).setEntity(enemy);
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
	  if (&this->getMap().getSquare(x, 0).getEntity() == NULL) {
		  ++n;
	  }
  }
  if (n < 1)
	  return;
  unsigned int i;

  x = 0;
  for (i = rand() % n; i > 0;)
  {
	  if (&this->getMap().getSquare(x, 0).getEntity() == NULL) {
		  i--;
	  }
	  if (i > 0 && ++x == Map::X) {
		  x = 0;
	  }
  }

  enemy = new Enemy(Pos(x, 0));
  this->_enemy[this->_nb_enemy++] = enemy;
  this->getMap().getSquare(x, 0).setEntity(enemy);
  this->_refresh = true;
}

void               Game::spawnProjectile(void)
{
	Projectile *          projectile;

	if (this->_nb_projectile >= Game::PROJECTILE_MAX) {
		return;
	}
//	if (this->getPlayer().shoot() == )
	//	return;
	projectile = new Projectile(Pos(this->getPlayer().getX(), 
									this->getPlayer().getY() - 1));
	this->_projectile[this->_nb_projectile++] = projectile;
	this->getMap().getSquare(this->getPlayer().getX(), this->getPlayer().getY() - 1)
		.setEntity(projectile);
	this->_refresh = true;
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

void               Game::deleteProjectile(Projectile & projectile)
{
  unsigned int idx;

  idx = this->getProjectileIdx(projectile);
  if (idx == Game::PROJECTILE_MAX) {
    return;
  }
  idx = this->getProjectileIdx(projectile);
  // this->getSquare(x, y).setEntity(NULL);
  delete this->_projectile[idx];
  this->_projectile[idx] = NULL;
  while (++idx < this->_nb_projectile)
  {
    this->_projectile[idx - 1] = this->_projectile[idx];
    this->_projectile[idx] = NULL;
  }
  --this->_nb_projectile;
}

void               Game::output(void)
{
  this->_refresh = false;
  (void)wmove(stdscr, 0, 0);
  this->getMap().output();
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

Projectile*        Game::getProjectile(unsigned int idx) const
{
  return this->_projectile[idx];
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

unsigned int       Game::getProjectileIdx(Projectile & projectile) const
{
  unsigned int idx;

  for (idx = 0; idx < _nb_projectile; ++idx) {
    if (&projectile == this->_projectile[idx]) {
      return idx;
    }
  }
  return Game::PROJECTILE_MAX;
}

bool               Game::needRefresh(void) const
{
  return this->_refresh;
}

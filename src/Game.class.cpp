#include "Game.class.hpp"
#include <iostream>

// constructors + destructors

const unsigned int Game::CYCLE_MAX = 10;
const bool         Game::END = 0;

Game::Game(void) :
  _map(), _cycle(0)
{
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Game()" << std::endl;
  #endif
}

Game::Game(const Game& src) :
  _map(), _cycle(0)
{
  (void)src;
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Game()" << std::endl;
  #endif
}

Game::~Game(void)
{
  #ifdef DEBUG
  std::cout << "[DESTRUCTED] Game()" << std::endl;
  #endif
}

// operators

Game&        Game::operator=(const Game& src)
{
  (void)src;
  return *this;
}

// functions

bool         Game::frame(void)
{
  if (false) {
    return Game::END;
  }
  return ~Game::END;
}

// getters + setters

unsigned int Game::getCycle(void) const
{
  return this->_cycle;
}

void         Game::updateCycle(void)
{
  if (++this->_cycle >= Game::CYCLE_MAX) {
    this->_cycle = 0;
  }
  // DO NO ACTION HERE
}

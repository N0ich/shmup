#include "Square.class.hpp"
#include <ncurses.h>

// CONSTRUCTORS + DESTRUCTORS

Square::Square(const Pos& pos) :
  pos(pos)
{
  this->_entity = NULL;
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Square(" << this->pos.x << "," << this->pos.y << ")" << std::endl;
  #endif
}

Square::Square(const Square& src) :
  pos(src.pos)
{
  this->_entity = NULL;
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Square(" << this->pos.x << "," << this->pos.y << ")" << std::endl;
  #endif
}

Square::~Square(void)
{
  #ifdef DEBUG
  std::cout << "[DESTRUCTED] Square(" << this->pos.x << "," << this->pos.y << ")" << std::endl;
  #endif
}

// OPERATORS
Square&               Square::operator=(const Square& src)
{
  (void)src;
  return *this;  
}

// FUNCTIONS

void                  Square::output(void) const
{
  if (this->getEntity() != NULL) {
    this->getEntity()->output();
  }
  else {
    (void)waddch(stdscr, ' ');
  }
}

// GETTERS + SETTERS

const AEntity*        Square::getEntity(void) const
{
  return this->_entity;
}

AEntity*              Square::getEntity(void)
{
  return this->_entity;
}

void                  Square::setEntity(AEntity* entity)
{
  this->_entity = entity;
}

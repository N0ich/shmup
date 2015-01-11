#include "Square.class.hpp"
#include <ncurses.h>

// constructors + destructors

Square::Square(const unsigned int x, const unsigned int y) :
  x(x), y(y), _entity(NULL)
{
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Square(" << this->x << "," << this->y << ")" << std::endl;
  #endif
}

Square::Square(const Square& src) :
  x(src.x), y(src.y), _entity(src._entity)
{
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Square(" << this->x << "," << this->y << ")" << std::endl;
  #endif
}

Square::~Square(void)
{
  #ifdef DEBUG
  std::cout << "[DESTRUCTED] Square(" << this->x << "," << this->y << ")" << std::endl;
  #endif
}

// operators
Square&               Square::operator=(const Square& src)
{
  (void)src;
  return *this;  
}

// FUNCTIONS

void                  Square::output(void) const
{
  if (&this->getEntity() != NULL) {
    this->getEntity().output();
  }
  else {
    (void)waddch(stdscr, ' ');
  }
}

// getters + setters

AEntity&              Square::getEntity(void) const
{
  return *this->_entity;
}

void                  Square::setEntity(AEntity* entity)
{
  this->_entity = entity;
}

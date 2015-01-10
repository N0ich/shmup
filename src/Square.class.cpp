#include "Square.class.hpp"

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

// functions

// getters + setters

AEntity&              Square::getEntity(void) const
{
  return *this->_entity;
}

void                  Square::setEntity(AEntity& entity)
{
  this->_entity = &entity;
}

#include <ncurses.h>
std::ostream&               operator<<(std::ostream& stream, const Square& obj)
{
  char ch = ' ';

  if (&obj.getEntity() != NULL) {
    ch = obj.getEntity().toChar();
  }
  waddch(stdscr, ch);
  return stream;
}
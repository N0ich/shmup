#include "Square.class.hpp"
#include <iostream>

// constructors + destructors

Square::Square(const unsigned int x, const unsigned int y) :
  x(x), y(y)
{
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Square(" << this->x << "," << this->y << ")" << std::endl;
  #endif
}

Square::Square(const Square& src) :
  x(src.x), y(src.y)
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

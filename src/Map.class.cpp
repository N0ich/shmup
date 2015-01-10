#include "Map.class.hpp"

// constructors + destructors

const unsigned int     Map::X = 20;
const unsigned int     Map::Y = 20;

Map::Map(void)
{
  this->_square = new Square**[Map::X];
  for (unsigned int x = 0; x < Map::X; ++x)
  {
    this->_square[x] = new Square*[Map::Y];
    for (unsigned int y = 0; y < Map::Y; ++y) {
      this->_square[x][y] = new Square(x, y);
    }
  }
  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Map()" << std::endl;
  #endif
}

Map::Map(const Map& src)
{
  (void)src;
  this->_square = NULL;

  #ifdef DEBUG
  std::cout << "[CONSTRUCTED] Map()" << std::endl;
  #endif
}

Map::~Map(void)
{
  for (unsigned int x = 0; x < Map::X; ++x)
  {
    for (unsigned int y = 0; y < Map::Y; ++y) {
      delete this->_square[x][y];
    }
    delete this->_square[x];
  }
  delete this->_square;

  #ifdef DEBUG
  std::cout << "[DESTRUCTED] Map()" << std::endl;
  #endif
}

// operators
Map&                   Map::operator=(const Map& src)
{
  (void)src;
  return *this;
}

// functions

// getters + setters

Square&                Map::getSquare(const unsigned int x, const unsigned int y)
{
  return this->_square[x][y][0];
}

const Square&          Map::getSquare(const unsigned int x, const unsigned int y) const
{
  return this->_square[x][y][0];
}

#include <ncurses.h>
std::ostream&               operator<<(std::ostream& stream, const Map& obj)
{
  for (unsigned int y = 0; y < Map::Y; ++y)
  {
    (void)wmove(stdscr, y, 0);
    (void)wrefresh(stdscr);
    for (unsigned int x = 0; x < Map::X; ++x) {
      stream << obj.getSquare(x, y);
    }
  }
  return stream;
}


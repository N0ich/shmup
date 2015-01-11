#include "Map.class.hpp"
#include <ncurses.h>

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
      this->_square[x][y] = new Square(Pos(x, y));
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

// FUNCTIONS

void                   Map::output(void) const
{
  // int curs_x = 0;
  // int curs_y = 0;

  // (void)curs_x;
  // (void)curs_y;
  for (unsigned int y = 0; y < Map::Y; ++y)
  {
    // getyx(stdscr, curs_y, curs_x);
    (void)wmove(stdscr, y, 0);
    for (unsigned int x = 0; x < Map::X; ++x) {
      this->getSquare(Pos(x, y)).output();
    }
  }
}

// getters + setters

Square&                Map::getSquare(const Pos pos)
{
  return this->_square[pos.x][pos.y][0];
}

const Square&          Map::getSquare(const Pos pos) const
{
  return this->_square[pos.x][pos.y][0];
}


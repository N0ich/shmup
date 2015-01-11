#include "Map.class.hpp"

// constructors + destructors

const unsigned int     Map::X = 30;
const unsigned int     Map::Y = 30;

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

void                   Map::output(WINDOW *win) const
{
  // int curs_x = 0;
  // int curs_y = 0;

  for (unsigned int y = 0; y < Map::Y; ++y)
  {
    // getyx(win, curs_y, curs_x);
    (void)wmove(win, y, 0);
    for (unsigned int x = 0; x < Map::X; ++x) {
      this->getSquare(Pos(x, y)).output(win);
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


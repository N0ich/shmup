#ifndef __MAP_CLASS_HPP__
# define __MAP_CLASS_HPP__

#include "Square.class.hpp"
#include <cstddef>
#include <ncurses.h>

class Map
{
public:
  // constructors + destructors
  Map(void);
  Map(const Map& src);
  ~Map(void);

  // operators
  Map&                      operator=(const Map& src);

  // FUNCTIONS

  void                      output(WINDOW *win) const;

  // getters + setters

  Square&                   getSquare(const Pos pos);
  const Square&             getSquare(const Pos pos) const;

  static const unsigned int X;
  static const unsigned int Y;

protected:
  Square***                 _square; // _square[x][y][0]

private:
};

#endif

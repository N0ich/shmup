#ifndef __MAP_CLASS_HPP__
# define __MAP_CLASS_HPP__

#include "Square.class.hpp"
#include <cstddef>

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

  void                      output(void) const;

  // getters + setters

  Square&                   getSquare(const unsigned int x, const unsigned int y);
  const Square&             getSquare(const unsigned int x, const unsigned int y) const;

  static const unsigned int X;
  static const unsigned int Y;

protected:
  Square***                 _square; // _square[x][y][0]

private:
};

#endif

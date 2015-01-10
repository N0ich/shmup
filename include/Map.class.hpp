#ifndef __MAP_CLASS_HPP__
# define __MAP_CLASS_HPP__

#include "Square.class.hpp"
#include <cstddef>
#include <iostream>

class Map
{
public:
  // constructors + destructors
  Map(void);
  Map(const Map& src);
  ~Map(void);

  // operators
  Map&                      operator=(const Map& src);

  // functions

  // getters + setters

  Square&                   getSquare(const unsigned int x, const unsigned int y);
  const Square&             getSquare(const unsigned int x, const unsigned int y) const;

  static const unsigned int X;
  static const unsigned int Y;

protected:
  Square***                 _square; // _square[x][y][0]

private:
};

std::ostream&               operator<<(std::ostream& stream, const Map& obj);

#endif

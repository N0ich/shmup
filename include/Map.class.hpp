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

  // functions

  // getters + setters

  Square&                   getSquare(const unsigned int x, const unsigned int y);

  static const unsigned int X;
  static const unsigned int Y;

protected:
  Square***                 _square;

private:
};

#endif

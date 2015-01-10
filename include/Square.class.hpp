#ifndef __SQUARE_CLASS_HPP__
# define __SQUARE_CLASS_HPP__

#include "AEntity.class.hpp"

class Square
{
public:
  // constructors + destructors
  Square(const unsigned int x, const unsigned int y);
  Square(const Square& src);
  ~Square(void);

  // operators
  Square&               operator=(const Square& src);

  // functions

  // getters + setters
  const unsigned int x;
  const unsigned int y;

  AEntity&           getEntity(void) const;
  void               setEntity(AEntity& entity);

protected:
  AEntity*           _entity;

private:
  Square(void);

};

#endif

#ifndef __SQUARE_CLASS_HPP__
# define __SQUARE_CLASS_HPP__

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

  // pixel
  // entities

protected:

private:
  Square(void);

};

#endif

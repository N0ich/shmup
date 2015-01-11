// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Square.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 15:43:55 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 15:44:00 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

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

  void                  output(void) const;

  // getters + setters
  const unsigned int x;
  const unsigned int y;

  AEntity&           getEntity(void) const;
  void               setEntity(AEntity* entity);

protected:
  AEntity*           _entity;

private:
  Square(void);

};

std::ostream&               operator<<(std::ostream& stream, const Square& obj);

#endif

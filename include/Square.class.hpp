// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Square.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 15:43:55 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 19:21:02 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef __SQUARE_CLASS_HPP__
# define __SQUARE_CLASS_HPP__

#include "AEntity.class.hpp"
#include "Pos.class.hpp"

class Square
{
public:
  // constructors + destructors
  Square(const Pos& pos);
  Square(const Square& src);
  ~Square(void);

  // operators
  Square&               operator=(const Square& src);

  // functions

  void                  output(void) const;

  // getters + setters
  const Pos          pos;

  const AEntity*     getEntity(void) const;
  AEntity*           getEntity(void);
  void               setEntity(AEntity* entity);

protected:
  AEntity*           _entity;

private:
  Square(void);
};

#endif

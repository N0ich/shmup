// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pos.class.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:04:13 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 17:04:36 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pos.class.hpp"

Pos::Pos(const unsigned int x, const unsigned int y) :
  x(x), y(y)
{ }

Pos::Pos(const Pos& src) :
  x(src.x), y(src.y)
{ }

Pos::~Pos(void)
{
  return;
}

unsigned int    Pos::getX(void) const
{
  return this->x;
}

unsigned int    Pos::getY(void) const
{
  return this->y;
}

void            Pos::setX(const unsigned int x)
{
  this->x = x;
}

void            Pos::setY(const unsigned int y)
{
  this->y = y;
}

Pos &           Pos::operator=(const Pos& src)
{
  this->x = src.x;
  this->y = src.y;
  return *this;
}

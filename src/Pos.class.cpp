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

Pos::Pos(void): _x(0), _y(0)
{
	return;
}

Pos::Pos(int x, int y): _x(x), _y(y)
{
	return;
}

Pos::Pos(Pos const & pos)
{
	this->_x = pos.getX();
	this->_y = pos.getY();
}

Pos::~Pos(void)
{
	return;
}

unsigned int		Pos::getX(void) const
{
	return this->_x;
}

unsigned int		Pos::getY(void) const
{
	return this->_y;
}

void				Pos::setX(unsigned int i)
{
	this->_x = i;
}

void				Pos::setY(unsigned int i)
{
	this->_y = i;
}

Pos &				Pos::operator=(Pos const & src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	return *this;
}

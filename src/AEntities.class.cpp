// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntities.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:14:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 12:31:15 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEntities.class.hpp"

AEntities::AEntities(void):
	x(0), y(0), type("Undefined"), mhp(0), chp(0), speed(0), dmg(0)
{
	return;
}

AEntities::AEntities(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
		  unsigned int chp, unsigned int speed, unsigned int dmg):
	x(x), y(y), type(type), mhp(mhp), chp(chp), speed(speed), dmg(dmg)
{
	return;
}

AEntities::AEntities(AEntities const & src)
{
	this->x = src.getX();
	this->y = src.getY();
	this->type = src.getType();
	this->mhp = src.getMHP();
	this->chp = src.getCHP();
	this->speed = src.getSpeed();
	this->dmg = src.getDmg();
	return;
}

void			AEntities::die(void)
{
	this->chp = 0;
	return;
}

void			AEntities::move(unsigned int x, unsigned int y)
{
	if (this->chp > 0)
	{
		this->x = x;
		this->y = y;
	}
}

void			AEntities::shoot(void)
{
	return;
}


/*
** Getters
*/

unsigned int	AEntities::getX(void) const
{
	return this->x;
}

unsigned int	AEntities::getY(void) const
{
	return this->y;
}

unsigned int	AEntities::getMHP(void) const
{
	return this->mhp;
}

unsigned int	AEntities::getCHP(void) const
{
	return this->chp;
}

unsigned int	AEntities::getSpeed(void) const
{
	return this->speed;
}

unsigned int	AEntities::getDmg(void) const
{
	return this->dmg;
}

std::string		AEntities::getType(void) const
{
	return this->type;
}

AEntities &		AEntities::operator=(AEntities const & src)
{
	this->x = src.getX();
	this->y = src.getY();
	this->type = src.getType();
	this->mhp = src.getMHP();
	this->chp = src.getCHP();
	this->speed = src.getSpeed();
	this->dmg = src.getDmg();
	return *this;
}


AEntities::~AEntities(void)
{
	return;
}

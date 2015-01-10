// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:14:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 12:31:15 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEntity.class.hpp"

AEntity::AEntity(void):
	x(0), y(0), type("Undefined"), mhp(0), chp(0), speed(0), dmg(0)
{
	return;
}

AEntity::AEntity(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
		  unsigned int chp, unsigned int speed, unsigned int dmg):
	x(x), y(y), type(type), mhp(mhp), chp(chp), speed(speed), dmg(dmg)
{
	return;
}

AEntity::AEntity(AEntity const & src)
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

void			AEntity::die(void)
{
	this->chp = 0;
	return;
}

void			AEntity::move(unsigned int x, unsigned int y)
{
	if (this->chp > 0)
	{
		this->x = x;
		this->y = y;
	}
}

void			AEntity::shoot(void)
{
	return;
}


/*
** Getters
*/

unsigned int	AEntity::getX(void) const
{
	return this->x;
}

unsigned int	AEntity::getY(void) const
{
	return this->y;
}

unsigned int	AEntity::getMHP(void) const
{
	return this->mhp;
}

unsigned int	AEntity::getCHP(void) const
{
	return this->chp;
}

unsigned int	AEntity::getSpeed(void) const
{
	return this->speed;
}

unsigned int	AEntity::getDmg(void) const
{
	return this->dmg;
}

std::string		AEntity::getType(void) const
{
	return this->type;
}

AEntity &		AEntity::operator=(AEntity const & src)
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


AEntity::~AEntity(void)
{
	return;
}

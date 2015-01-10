// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:14:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 17:51:29 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEntity.class.hpp"

AEntity::AEntity(void):
	x(0), y(0), type("Undefined"), mhp(0), chp(0), speed(0), mspeed(0), dmg(0),
	cooldown(0), mcd(0)
{
	this->pos = Pos(x, y);
	return;
}

AEntity::AEntity(unsigned int x, unsigned int y,
				 std::string type, unsigned int mhp,
				 unsigned int chp, unsigned int speed, unsigned int mspeed,
				 unsigned int dmg, unsigned int cooldown, unsigned int mcd):
	x(x), y(y), type(type), mhp(mhp), chp(chp), speed(speed),
	mspeed(mspeed), dmg(dmg), cooldown(cooldown), mcd(mcd)
{
	this->pos = Pos(x, y);
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
	this->mspeed = src.getMSpeed();
	this->dmg = src.getDmg();
	this->cooldown = src.getCooldown();
	this->mcd = src.getMCD();
	this->pos = Pos(this->x, this->y);
	return;
}

/*
** Actions
*/

void			AEntity::die(void)
{
	this->chp = 0;
	return;
}

void			AEntity::move(void)
{
	if (this->chp > 0)
	{
		if (this->speed == this->mspeed)
		{
			this->y--;
			this->speed = 0;
			this->pos.setX(this->x);
			this->pos.setY(this->y);
		}
	}
}

bool			AEntity::shoot(void)
{
	if (this->chp > 0)
	{
		if (this->cooldown == this->mcd)
		{
			this->cooldown = 0;
			return true;
		}
	}
	return false;
}

void			AEntity::takeDamage(unsigned int i)
{
	if (this->chp - i <= 0)
	{
		this->chp = 0;
	}
	else
	{
		this->chp -= i;
	}
}

/*
** Move and shoot cd refreshers
*/

void			AEntity::refreshMove(void)
{
	if (this->speed < this->mspeed)
		this->speed++;
}

void			AEntity::refreshShoot(void)
{
	if (this->cooldown < this->mcd)
		this->cooldown++;
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

unsigned int	AEntity::getMSpeed(void) const
{
	return this->speed;
}

unsigned int	AEntity::getDmg(void) const
{
	return this->dmg;
}

unsigned int	AEntity::getCooldown(void) const
{
	return this->cooldown;
}

unsigned int	AEntity::getMCD(void) const
{
	return this->mcd;
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

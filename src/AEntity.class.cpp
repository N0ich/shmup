// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEntity.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:14:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 13:10:04 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEntity.class.hpp"

AEntity::AEntity(const Pos pos, const std::string& type,
  const unsigned int mhp, const unsigned int chp,
  const unsigned int speed, const unsigned int mspeed,
  const unsigned int dmg, const unsigned int cooldown, const unsigned int mcd) :
  pos(pos), type(type), mhp(mhp), chp(chp), speed(speed), mspeed(mspeed), dmg(dmg), cooldown(cooldown), mcd(mcd)
{ }

AEntity::AEntity(const AEntity& src) :
  pos(src.pos), type(src.type), mhp(src.mhp), chp(src.chp), speed(src.speed), mspeed(src.mspeed), dmg(src.dmg), cooldown(src.cooldown), mcd(src.mcd)
{ }

/*
** Actions
*/

void			AEntity::die(void)
{
	this->chp = 0;
	return;
}

bool			AEntity::move(void)
{
	if (this->chp > 0)
	{
		if (this->speed == this->mspeed)
		{
			this->pos.y++;
			this->speed = 0;
			return true;
		}
	}
	return false;
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

const Pos&    AEntity::getPos(void) const
{
  return this->pos;
}

Pos&          AEntity::getpos(void)
{
  return this->pos;
}

void          AEntity::setPos(const Pos& pos)
{
  this->pos = pos;
}

unsigned int  AEntity::getX(void) const
{
  return this->pos.x;
}

void          AEntity::setX(unsigned int x)
{
  this->pos.x = x;
}

unsigned int  AEntity::getY(void) const
{
  return this->pos.y;
}

void          AEntity::setY(unsigned int y)
{
  this->pos.y = y;
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
  this->pos      = src.pos;
  this->type     = src.type;
  this->mhp      = src.mhp;
  this->chp      = src.chp;
  this->speed    = src.speed;
  this->mspeed   = src.mspeed;
  this->dmg      = src.dmg;
  this->cooldown = src.cooldown;
  this->mcd      = src.mcd;
	return *this;
}


AEntity::~AEntity(void)
{
	return;
}

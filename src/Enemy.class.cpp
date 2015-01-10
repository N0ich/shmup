// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 16:21:32 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "Enemy.class.hpp"


Enemy::Enemy(void): AEntity()
{
	this->type = "Enemy";
    return;
}

Enemy::Enemy(unsigned int x, unsigned int y, std::string type,
			 unsigned int mhp, unsigned int chp, unsigned int speed,
			 unsigned int mspeed, unsigned int dmg, unsigned int cooldown,
			 unsigned int mcd):
	AEntity()
{
    this->x = x;
    this->y = y;
    this->type = type;
    this->mhp = mhp;
    this->chp = chp;
    this->speed = speed;
	this->mspeed = mspeed;
    this->dmg = dmg;
	this->cooldown = cooldown;
    this->mcd = mcd;
    return;
}

Enemy::Enemy(Enemy const & src): AEntity()
{
    this->x = src.getX();
    this->y = src.getY();
    this->type = src.getType();
    this->mhp = src.getMHP();
    this->chp = src.getCHP();
    this->speed = src.getSpeed();
    this->speed = src.getMSpeed();
    this->dmg = src.getDmg();
	this->cooldown = src.getCooldown();
	this->mcd = src.getMCD();
    return;
}

Enemy::~Enemy(void)
{
	return;
}

char         Enemy::toChar(void) const
{
    return '@';
}
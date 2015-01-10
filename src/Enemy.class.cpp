// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 12:49:36 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.class.hpp"


Enemy::Enemy(void): AEntities()
{
	this->type = "Enemy";
    return;
}

Enemy::Enemy(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
					 unsigned int chp, unsigned int speed, unsigned int dmg):
	AEntities()
{
    this->x = x;
    this->y = y;
    this->type = type;
    this->mhp = mhp;
    this->chp = chp;
    this->speed = speed;
    this->dmg = dmg;
    return;
}

Enemy::Enemy(Enemy const & src): AEntities()
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

Enemy::~Enemy(void)
{
	return;
}

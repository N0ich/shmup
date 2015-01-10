// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 13:01:29 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.class.hpp"


Player::Player(void): AEntity()
{
	this->type = "Player";
    return;
}

Player::Player(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
					 unsigned int chp, unsigned int speed, unsigned int dmg):
	AEntity()
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

Player::Player(Player const & src): AEntity()
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

Player::~Player(void)
{
	return;
}

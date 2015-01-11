// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 17:02:52 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.class.hpp"
#include "Square.class.hpp"
#include <ncurses.h>

const short  Player::COLOR_PAIR = 1;

Player::Player(void): AEntity()
{
	this->type = "Player";
    return;
}

Player::Player(unsigned int x, unsigned int y, std::string type,
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

Player::Player(Player const & src): AEntity()
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
    return;
}

void		 Player::move(int i)
{
	if (this->chp > 0)
    {
		if (this->speed == this->mspeed)
		{
            this->speed = 0;
			this->x += i;
			this->pos.setX(this->x);
			this->pos.setY(this->y);
        }
    }
}

Player::~Player(void)
{
	return;
}

void         Player::output(void) const
{
    // attron(COLOR_PAIR(Player::COLOR_PAIR));
    (void)waddch(stdscr, '^');
    // attroff(COLOR_PAIR(Player::COLOR_PAIR));
}

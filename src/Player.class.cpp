// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 16:22:50 by vrey             ###   ########.fr       //
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

Player::Player(unsigned int x, unsigned int y):
	AEntity()
{
    this->x = x;
    this->y = y;
    this->type = "Player";
    this->mhp = 10;
    this->chp = 10;
    this->speed = 10;
	this->mspeed = 10;
    this->dmg = 1;
	this->cooldown = 10;
	this->mcd = 10;
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

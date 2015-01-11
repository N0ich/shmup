// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Projectile.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 16:28:43 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Projectile.class.hpp"
#include <ncurses.h>

const short  Projectile::COLOR_PAIR = 2;

Projectile::Projectile(void): AEntity()
{
	this->type = "Projectile";
    return;
}

Projectile::Projectile(Pos const & pos): AEntity()
{
	this->pos = pos;
    this->x = pos.getX();
    this->y = pos.getY();
    this->type = "Projectile";
    this->mhp = 3;
    this->chp = 3;
    this->speed = 10;
	this->mspeed = 10;
    this->dmg = 0;
	this->cooldown = 0;
    this->mcd = 0;
    return;
}

Projectile::Projectile(Projectile const & src): AEntity()
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

Projectile::~Projectile(void)
{
	return;
}

bool		Projectile::move(void)
{
    if (this->chp > 0)
    {
		if (this->speed == this->mspeed)
        {
            this->y--;
            this->speed = 0;
            this->pos.setX(this->x);
            this->pos.setY(this->y);
            return true;
        }
    }
    return false;
}

void        Projectile::output(void) const
{
    // attron(COLOR_PAIR(Projectile::COLOR_PAIR));
    (void)waddch(stdscr, '|');
    // attroff(COLOR_PAIR(Projectile::COLOR_PAIR));
}

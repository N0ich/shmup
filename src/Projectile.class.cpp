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

Projectile::Projectile(void) :
    AEntity(pos((unsigned int)0, (unsigned int)0), "Enemy", 3, 3, 10, 10, 0, 0, 0)
{
	this->type = "Projectile";
    return;
}

Projectile::Projectile(Pos const & pos) :
    AEntity(pos, "Enemy", 3, 3, 10, 10, 0, 0, 0)
{
}

Projectile::Projectile(Projectile const & src) :
    AEntity(src.pos, src.type, src.mhp, src.chp, src.speed, src.mspeed, src.dmg, src.cooldown, src.mcd)
{
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

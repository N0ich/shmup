// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Projectile.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 19:30:47 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Projectile.class.hpp"

const short  Projectile::COLOR_PAIR = 3;

// Projectile::Projectile(void) :
//      AEntity()
//  {
//  	this->type = "Projectile";
//      return;
//  }

Projectile::Projectile(Pos const & pos) :
    AEntity(pos, "Projectile", 3, 3, 10, 10, 0, 0, 0)
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
            this->pos.y--;
            this->speed = 0;
            return true;
        }
    }
    return false;
}

void        Projectile::output(WINDOW *win) const
{
    attron(COLOR_PAIR(Projectile::COLOR_PAIR));
    (void)waddch(win, '|');
    attroff(COLOR_PAIR(Projectile::COLOR_PAIR));
}

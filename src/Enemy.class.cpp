// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 20:22:55 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.class.hpp"

const short  Enemy::COLOR_PAIR = 2;

// Enemy::Enemy(void): AEntity()
// {
// 	this->type = "Enemy";
//     return;
// }

Enemy::Enemy(const Pos& pos) :
    AEntity(pos, "Enemy", 3, 3, 30, 30, 0, 0, 0)
{
// 	this->pos = pos;
//     this->type = "Enemy";
//     this->mhp = 3;
//     this->chp = 3;
//     this->speed = 10;
// 	this->mspeed = 10;
//     this->dmg = 0;
// 	this->cooldown = 0;
//     this->mcd = 0;
//    return;
}

Enemy::Enemy(const Enemy& src) :
    AEntity(src.pos, src.type, src.mhp, src.chp, src.speed, src.mspeed, src.dmg, src.cooldown, src.mcd)
{
}

Enemy::~Enemy(void)
{
	return;
}

void         Enemy::output(WINDOW *win) const
{
    wattron(win, COLOR_PAIR(Enemy::COLOR_PAIR));
    (void)waddch(win, '@');
    wattroff(win, COLOR_PAIR(Enemy::COLOR_PAIR));
}

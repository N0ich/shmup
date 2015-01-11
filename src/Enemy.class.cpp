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
#include <cstdlib>

const short  Enemy::COLOR_PAIR = 2;

// Enemy::Enemy(void): AEntity()
// {
// 	this->type = "Enemy";
//     return;
// }

Enemy::Enemy(const Pos& pos) :
    AEntity(pos, "Enemy", 3, 3, 0, 5 + (rand() % 15), 0, 0, 0)
{
  const char sb[5] = { '*', '@', '#', '!', '%' };

  this->_char = sb[rand() & 5];
}

Enemy::Enemy(const Enemy& src) :
    AEntity(src.pos, src.type, src.mhp, src.chp, src.speed, src.mspeed, src.dmg, src.cooldown, src.mcd)
{
  const char sb[5] = { '*', '@', '#', '!', '%' };

  this->_char = sb[rand() & 5];
}

Enemy::~Enemy(void)
{
}

void         Enemy::output(WINDOW *win) const
{
    wattron(win, COLOR_PAIR(Enemy::COLOR_PAIR));
    (void)waddch(win, this->_char);
    wattroff(win, COLOR_PAIR(Enemy::COLOR_PAIR));
}

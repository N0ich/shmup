// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:39 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 12:18:33 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.class.hpp"
#include <ncurses.h>

const short  Enemy::COLOR_PAIR = 2;

Enemy::Enemy(void): AEntity()
{
	this->type = "Enemy";
    return;
}

Enemy::Enemy(Pos const & pos): AEntity()
{
	this->pos = pos;
    this->x = pos.getX();
    this->y = pos.getY();
    this->type = "Enemy";
    this->mhp = 3;
    this->chp = 3;
    this->speed = 10;
	this->mspeed = 10;
    this->dmg = 0;
	this->cooldown = 0;
    this->mcd = 0;
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

void         Enemy::output(void) const
{
    // attron(COLOR_PAIR(Enemy::COLOR_PAIR));
    (void)waddch(stdscr, '@');
    // attroff(COLOR_PAIR(Enemy::COLOR_PAIR));
}

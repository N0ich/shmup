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
#include "Map.class.hpp"

const short  Player::COLOR_PAIR = 1;

// Player::Player(void): AEntity()
// {
// 	this->type = "Player";
//     return;
// }

Player::Player(void) :
    AEntity(Pos(Map::X / 2, Map::Y - 1), "Player", 3, 3, 10, 10, 0, 0, 0)
{
    this->_order = NONE;
}

// Player::Player(unsigned int x, unsigned int y, std::string type,
// 			   unsigned int mhp, unsigned int chp, unsigned int speed,
// 			   unsigned int mspeed, unsigned int dmg, unsigned int cooldown,
// 			   unsigned int mcd):
// 	AEntity()
// {
//     this->x = x;
//     this->y = y;
//     this->type = type;
//     this->mhp = mhp;
//     this->chp = chp;
//     this->speed = speed;
// 	this->mspeed = mspeed;
//     this->dmg = dmg;
// 	this->cooldown = cooldown;
// 	this->mcd = mcd;
//     this->_order = NONE;
//     return;
// }

Player::Player(const Player& src) :
    AEntity(src.pos, src.type, src.mhp, src.chp, src.speed, src.mspeed, src.dmg, src.cooldown, src.mcd)
{
    this->_order = NONE;
}

Player::~Player(void)
{
}

void		 Player::move(int i)
{
    this->pos.x += i;
}

void         Player::setOrder(const EPlayerOrder order)
{
    this->_order = order;
}

EPlayerOrder Player::getOrder(void) const
{
    return this->_order;
}

void         Player::output(WINDOW *win) const
{
    attron(COLOR_PAIR(Player::COLOR_PAIR));
    (void)waddch(win, '^');
    attroff(COLOR_PAIR(Player::COLOR_PAIR));
}

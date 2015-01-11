// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 20:09:31 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include "AEntity.class.hpp"

enum EPlayerOrder
{
	NONE = 0,
	MOVE_RIGHT,
	MOVE_LEFT
};

class Player: public AEntity
{
public:
	Player(void);
	// Player(unsigned int x, unsigned int y, std::string type,
	// 	   unsigned int mhp, unsigned int chp, unsigned int speed,
	// 	   unsigned int mspeed, unsigned int dmg, unsigned int cooldown,
	// 	   unsigned int mcd);
	Player(const Player& src);

	~Player(void);

	Player &             operator=(Player const &);

	void		             move(int i);
	void                 output(WINDOW *win) const;

	void                 setOrder(const EPlayerOrder order);
	EPlayerOrder         getOrder(void) const;
	void				 setCHP(unsigned int i);

  static const short   COLOR_PAIR;

protected:
	EPlayerOrder         _order;

private:
};


#endif

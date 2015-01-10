// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 16:23:04 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include "AEntity.class.hpp"

class Player: public AEntity {

private:


public:
	Player(void);
	Player(unsigned int x, unsigned int y, std::string type,
		   unsigned int mhp, unsigned int chp, unsigned int speed,
		   unsigned int mspeed, unsigned int dmg, unsigned int cooldown,
		   unsigned int mcd);
	Player(Player const & src);
	~Player(void);

	void		move(int i);

    Player &     operator=(Player const &);
};


#endif

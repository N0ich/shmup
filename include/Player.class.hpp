// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 16:22:12 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include "AEntity.class.hpp"

class Player: public AEntity {

private:


public:
	Player(void);
	Player(unsigned int x, unsigned int y);
	Player(Player const & src);
	~Player(void);

	Player &             operator=(Player const &);

	void		             move(int i);
	void                 output(void) const;

  static const short   COLOR_PAIR;
};


#endif

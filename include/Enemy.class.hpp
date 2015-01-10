// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 14:49:33 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "AEntity.class.hpp"

class Enemy: public AEntity {

private:


public:
	Enemy(void);
	Enemy(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
		  unsigned int chp, unsigned int speed, unsigned int mspeed, unsigned int dmg,
		  unsigned int cooldown, unsigned int mcd);
	Enemy(Enemy const & src);
	~Enemy(void);


    Enemy &     operator=(Enemy const &);
};


#endif

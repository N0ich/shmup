// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 12:50:05 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "AEntities.class.hpp"

class Enemy: public AEntities {

private:


public:
	Enemy(void);
	Enemy(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
		  unsigned int chp, unsigned int speed, unsigned int dmg);
	Enemy(Enemy const & src);
	~Enemy(void);


    Enemy &     operator=(Enemy const &);
};


#endif

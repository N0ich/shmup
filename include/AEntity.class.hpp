// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//  AEntity.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 11:58:52 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 12:30:19 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AENTITY_CLASS_HPP
# define AENTITY_CLASS_HPP

#include <iostream>
#include <string>

/*
** Entities abstract class
*/

class AEntity {

protected:

	unsigned int	x;
	unsigned int	y;
	std::string		type;
	unsigned int	mhp;
	unsigned int	chp;
	unsigned int	speed;
	unsigned int	dmg;
//	Projectile		weapon;

public:
	AEntity(void);
	AEntity(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
			  unsigned int chp, unsigned int speed, unsigned int dmg);
	AEntity(AEntity const & src);
	~AEntity(void);

	unsigned int	getX(void) const;
	unsigned int	getY(void) const;
	unsigned int	getSpeed(void) const;
	unsigned int	getMHP(void) const;
	unsigned int	getCHP(void) const;
	unsigned int	getDmg(void) const;
	std::string		getType(void) const;


	void			die(void);
	void			move(unsigned int x, unsigned int y);
	void			shoot(void);
	void			takeDamage(unsigned int);

	AEntity &		operator=(AEntity const &);

};

#endif

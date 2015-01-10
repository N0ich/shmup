// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//  AEntities.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 11:58:52 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 12:30:19 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AENTITIES_CLASS_HPP
# define AENTITIES_CLASS_HPP

#include <iostream>
#include <string>

/*
** Entities abstract class
*/

class AEntities {

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
	AEntities(void);
	AEntities(unsigned int x, unsigned int y, std::string type, unsigned int mhp,
			  unsigned int chp, unsigned int speed, unsigned int dmg);
	AEntities(AEntities const & src);
	~AEntities(void);

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

	AEntities &		operator=(AEntities const &);

};

#endif

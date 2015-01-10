// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//  AEntity.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 11:58:52 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 17:50:06 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AENTITY_CLASS_HPP
# define AENTITY_CLASS_HPP

#include <iostream>
#include <string>
#include "Pos.class.hpp"

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
	unsigned int	mspeed;
	unsigned int	dmg;
	unsigned int	cooldown;
	unsigned int	mcd;
	Pos				pos;

public:
	AEntity(void);
	AEntity(unsigned int x, unsigned int y,
			std::string type, unsigned int mhp,
			unsigned int chp, unsigned int speed, unsigned int mspeed,
			unsigned int dmg, unsigned int cooldown, unsigned int mcd);
	AEntity(AEntity const & src);
	~AEntity(void);

	/*
	** Getters
	*/

	unsigned int	getX(void) const;
	unsigned int	getY(void) const;
	unsigned int	getSpeed(void) const;
	unsigned int	getMSpeed(void) const;
	unsigned int	getMHP(void) const;
	unsigned int	getCHP(void) const;
	unsigned int	getDmg(void) const;
	unsigned int	getCooldown(void) const;
	unsigned int	getMCD(void) const;
	std::string		getType(void) const;

	/*
	** Move and shoot cd refreshers
	*/
	
	void			refreshMove(void);
	void			refreshShoot(void);

	/*
	** Actions
	*/

	void			die(void);
	virtual void	move(void);
	bool			shoot(void);
	void			takeDamage(unsigned int);

	AEntity &		operator=(AEntity const &);

};

#endif

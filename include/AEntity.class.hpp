// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//  AEntity.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 11:58:52 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 13:08:41 by vrey             ###   ########.fr       //
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

class AEntity
{
protected:

  Pos           pos;
	std::string		type;
	unsigned int	mhp;
	unsigned int	chp;
	unsigned int	speed;
	unsigned int	mspeed;
	unsigned int	dmg;
	unsigned int	cooldown;
	unsigned int	mcd;

public:
	AEntity(const Pos pos,
			const std::string& type, const unsigned int mhp,
			const unsigned int chp, const unsigned int speed, const unsigned int mspeed,
			const unsigned int dmg, const unsigned int cooldown, const unsigned int mcd);
	AEntity(const AEntity& src);
	virtual ~AEntity(void);

	/*
	** Getters
	*/
  const Pos&    getPos(void) const;
  Pos&          getpos(void);
  void          setPos(const Pos& pos);

	unsigned int	getX(void) const;
  void          setX(unsigned int x);

	unsigned int	getY(void) const;
  void          setY(unsigned int y);

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
	
	void			    refreshMove(void);
	void			    refreshShoot(void);

	/*
	** Actions
	*/

	void			    die(void);
	virtual bool		move(void);
	bool			    shoot(void);
	void			    takeDamage(unsigned int);

	AEntity &		  operator=(AEntity const &);

	virtual void  output(void) const = 0;

private:
  AEntity(void);
};

#endif

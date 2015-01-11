// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Projectile.class.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 15:25:08 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PROJECTILE_CLASS_HPP
# define PROJECTILE_CLASS_HPP

#include "AEntity.class.hpp"

class Projectile: public AEntity {

private:


public:
	Projectile(void);
	Projectile(Pos const & pos);
	Projectile(Projectile const & src);
	~Projectile(void);

	Projectile &              operator=(Projectile const &);

	bool				move(void);
	void                output(void) const;

  static const short   COLOR_PAIR;
};


#endif

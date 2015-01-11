// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:41:47 by vrey              #+#    #+#             //
//   Updated: 2015/01/11 12:31:22 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include "AEntity.class.hpp"

class Enemy: public AEntity {

private:


public:
	Enemy(void);
	Enemy(Pos const & pos);
	Enemy(Enemy const & src);
	~Enemy(void);

  Enemy &              operator=(Enemy const &);

  void                 output(WINDOW *win) const;

  static const short   COLOR_PAIR;
};


#endif

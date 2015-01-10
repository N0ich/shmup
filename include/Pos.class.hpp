// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pos.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:04:24 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 16:32:28 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POS_CLASS_HPP
# define POS_CLASS_HPP

#include <iostream>
#include <string>

class Pos {

private:
	unsigned int		_x;
	unsigned int		_y;	

public:
	Pos();
	Pos(int x, int y);
	Pos(Pos const &pos);
	~Pos(void);

	unsigned int		getX(void) const;
	unsigned int		getY(void) const;

	Pos &	operator=(Pos const & src);

};


#endif

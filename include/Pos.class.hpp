// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pos.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vrey <vrey@student.42.fr>                  +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:04:24 by vrey              #+#    #+#             //
//   Updated: 2015/01/10 16:41:33 by vrey             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POS_CLASS_HPP
# define POS_CLASS_HPP

class Pos
{
public:
  Pos(const unsigned int x, const unsigned int y);
  Pos(Pos const &pos);
  ~Pos(void);

  unsigned int    getX(void) const;
  unsigned int    getY(void) const;

  void            setX(const unsigned int i);
  void            setY(const unsigned int i);

  Pos&            operator=(Pos const & src);

  unsigned int    x;
  unsigned int    y;

private:
  Pos(void);
};


#endif

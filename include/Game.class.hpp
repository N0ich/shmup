#ifndef __GAME_CLASS_HPP__
# define __GAME_CLASS_HPP__

#include "Map.class.hpp"

class Game
{
public:
  // constructors + destructors
  Game(void);
  Game(const Game& src);
  ~Game(void);

  // operators
  Game&                     operator=(const Game& src);

  // functions

  bool                      frame(void);

  // getters + setters

  unsigned int              getCycle(void) const;
  void                      updateCycle(void);

  static const bool         END;

protected:
  Map                       _map;
  unsigned int              _cycle;

private:
  static const unsigned int CYCLE_MAX;
};

#endif

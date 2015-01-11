#ifndef __GAME_CLASS_HPP__
# define __GAME_CLASS_HPP__

#include "Map.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"

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

  void                      spawnEnemy(void);
  void                      deleteEnemy(Enemy& enemy);

  void                      output(void);

  // getters + setters

  unsigned int              getCycle(void) const;
  void                      updateCycle(void);

  Map&                      getMap(void);
  const Map&                getMap(void) const;

  Player&                   getPlayer(void);
  const Player&             getPlayer(void) const;

  Enemy*                    getEnemy(unsigned int idx) const;
  unsigned int              getEnemyIdx(Enemy& enemy) const;

  bool                      needRefresh(void) const;

  // magic getters + setters

  Square&                   getSquare(const Pos pos);
  const Square&             getSquare(const Pos pos) const;

  static const bool         END;

protected:
  Map                       _map;
  unsigned int              _cycle;
  bool                      _refresh;
  unsigned int              _score;

  Player                    _player;
  unsigned int              _nb_enemy;
  Enemy**                   _enemy; // _enemy[n][0]

private:
  static const unsigned int CYCLE_MAX;
  static const unsigned int ENEMY_MAX;
};

#endif

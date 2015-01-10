#include "Game.class.hpp"
#include "Map.class.hpp"
#include "Square.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"

int main(void)
{
  Game   game;

  // while (game.frame() != Game::END)
  // {
    
  // }

  // TEST ADD/DELETE ENEMY
  game.spawnEnemy();
  game.spawnEnemy();
  game.spawnEnemy();
  game.spawnEnemy();
  game.deleteEnemy(*game.getEnemy(1));

  return 0;
}
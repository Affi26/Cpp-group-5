#ifndef __BOMB_ENEMY_H__
#define __BOMB_ENEMY_H__

#include "Enemy.hpp"
#include "Node.hpp"
/**
 * @brief Child class for boss enemies
 *
 */
class BossEnemy : public Enemy {
 public:
  /**
   * @brief Construct a new Boss Enemy object
   *
   * @param n starting node
   */
  BossEnemy(std::shared_ptr<Node> n);
};
#endif  // __BOMB_ENEMY_H__
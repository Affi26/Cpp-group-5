#ifndef __BASIC_ENEMY_H__
#define __BASIC_ENEMY_H__

#include "Enemy.hpp"
#include "Node.hpp"
/**
 * @brief Child class for basic enemies
 *
 */
class BasicEnemy : public Enemy {
 public:
  /**
   * @brief Construct a new Basic Enemy object
   *
   * @param n starting node
   */
  BasicEnemy(std::shared_ptr<Node> n);
};

#endif  // __BASIC_ENEMY_H__
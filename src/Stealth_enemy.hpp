#ifndef __STEALTH_ENEMY_H__
#define __STEALTH_ENEMY_H__

#include "Enemy.hpp"
#include "Node.hpp"
/**
 * @brief Child class for stealth enemies
 *
 */
class StealthEnemy : public Enemy {
 public:
  /**
   * @brief Construct a new Stealth Enemy object
   *
   * @param n starting node
   */
  StealthEnemy(std::shared_ptr<Node> n);
};

#endif  // __STEALTH_ENEMY_H__
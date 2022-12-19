#ifndef __POSION_TOWER_H__
#define __POSION_TOWER_H__

#include "Tower.hpp"

/**
 * @brief Poison tower class
 */
class PoisonTower : public Tower {
public:
  /**
   * @brief Construct a new Poison Tower object
   * 
   */
  PoisonTower();
  
  /**
   * @brief Destroy the Poison Tower object
   * 
   */
  ~PoisonTower();

  /**
   * @brief Fire at enemy
   * 
   */
  void fire();

  /**
   * @brief Get the Projectiles object
   * 
   * @return std::vector<std::shared_ptr<Projectile>>& 
   */
  std::vector<std::shared_ptr<Projectile>>& getProjectiles();

private:
  std::vector<std::shared_ptr<Projectile>> projectiles_;
};
#endif // __POSION_TOWER_H__
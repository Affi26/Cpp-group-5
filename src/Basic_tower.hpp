#ifndef __BASIC_TOWER_H__
#define __BASIC_TOWER_H__

#include "Tower.hpp"

/**
 * @brief Basic tower class
 */
class basicTower : public Tower {
public:
/**
 * @brief Construct a new basic Tower object
 * 
 */
  basicTower();
  /**
   * @brief Destroy the basic Tower object
   * 
   */
  ~basicTower();
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
#endif  // __BASIC_TOWER_H__
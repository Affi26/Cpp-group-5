#ifndef __ICE_TOWER_H__
#define __ICE_TOWER_H__

#include "Tower.hpp"

/**
 * @brief Ice tower class
 * 
 */
class IceTower : public Tower {
public:
  /**
   * @brief Construct a new Ice Tower object
   * 
   */
  IceTower();

  /**
   * @brief Destroy the Ice Tower object
   * 
   */
  ~IceTower();

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

#endif // __ICE_TOWER_H__
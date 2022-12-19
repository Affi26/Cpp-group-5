#ifndef __BASIC_PROJECTILE_H__
#define __BASIC_PROJECTILE_H__

#include "Projectile.hpp"
/**
 * @brief Basic projectile for basic tower.
 * 
 */
class basicProjectile : public Projectile {
 public:
 /**
  * @brief Construct a new basic Projectile object
  * 
  * @param enemy target
  * @param origin position of tower
  */
  basicProjectile(std::shared_ptr<Enemy> enemy, sf::Vector2f origin);


};

#endif  // __BASIC_PROJECTILE_H__
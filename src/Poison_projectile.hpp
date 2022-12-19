#ifndef __POISON_PROJECTILE_H__
#define __POISON_PROJECTILE_H__

#include "Projectile.hpp"
/**
 * @brief Poison projectile for poison tower.
 * 
 */
class PoisonProjectile : public Projectile {
 public:
 /**
  * @brief Construct a new Poison Projectile object
  * 
  * @param enemy target
  * @param origin position of tower
  */
  PoisonProjectile(std::shared_ptr<Enemy> enemy, sf::Vector2f origin);
};

#endif // __POISON_PROJECTILE_H__
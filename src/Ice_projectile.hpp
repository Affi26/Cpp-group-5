#ifndef __ICE_PROJECTILE_H__
#define __ICE_PROJECTILE_H__

#include "Projectile.hpp"

/**
 * @brief Ice projectile for ice tower.
 * 
 */
class IceProjectile : public Projectile {
 public:
 /**
  * @brief Construct a new Ice Projectile object
  * 
  * @param enemy target
  * @param origin position of tower
  */
  IceProjectile(std::shared_ptr<Enemy> enemy, sf::Vector2f origin);
};

#endif // __ICE_PROJECTILE_H__
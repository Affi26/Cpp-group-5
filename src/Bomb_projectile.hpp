#ifndef __BOMB_PROJECTILE_H__
#define __BOMB_PROJECTILE_H__

#include "Projectile.hpp"

/**
 * @brief Bomb projectile for bomb tower.
 * 
 */
class BombProjectile : public Projectile {
 public:
 /**
  * @brief Construct a new Bomb Projectile object
  * 
  * @param enemy target
  * @param origin position of tower
  */
  BombProjectile(std::shared_ptr<Enemy> enemy, sf::Vector2f origin);
};

#endif // __BOMB_PROJECTILE_H__

#include "Ice_projectile.hpp"

IceProjectile::IceProjectile(std::shared_ptr<Enemy> enemy,
                                 const sf::Vector2f origin)
    : Projectile("assets/ice_projectile.png", 3, enemy, origin) {
  damage_ = 0;
}

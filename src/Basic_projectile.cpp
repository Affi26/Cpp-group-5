
#include "Basic_projectile.hpp"

basicProjectile::basicProjectile(std::shared_ptr<Enemy> enemy,
                                 const sf::Vector2f origin)
    : Projectile("assets/basic_projectile.png", 0, enemy, origin) {
  damage_ = 1;
}

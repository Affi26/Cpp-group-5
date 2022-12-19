
#include "Poison_projectile.hpp"

PoisonProjectile::PoisonProjectile(std::shared_ptr<Enemy> enemy,
                                 const sf::Vector2f origin)
    : Projectile("assets/poison_projectile.png", 2, enemy, origin) {
  damage_ = 1;
}


#include "Bomb_projectile.hpp"

BombProjectile::BombProjectile(std::shared_ptr<Enemy> enemy,
                                 const sf::Vector2f origin)
    : Projectile("assets/bomb_projectile.png", 1, enemy, origin) {
  damage_ = 3;
}

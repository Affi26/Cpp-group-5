#include "Bomb_tower.hpp"

BombTower::BombTower() : Tower("assets/bomb_tower.png", 1, 1.5, 3000) {
    price_ = 75;
}

BombTower::~BombTower() { }

void BombTower::fire() {
  projectiles_.push_back(
      std::make_shared<BombProjectile>(target_, sprite_.getPosition()));
}

std::vector<std::shared_ptr<Projectile>>& BombTower::getProjectiles() {
  return projectiles_;
}
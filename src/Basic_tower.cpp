#include "Basic_tower.hpp"

basicTower::basicTower() : Tower("assets/basic_tower.png", 0, 1, 1000) {
  price_ = 50;
}

basicTower::~basicTower() {}

void basicTower::fire() {
  projectiles_.push_back(
      std::make_shared<basicProjectile>(target_, sprite_.getPosition()));
}

std::vector<std::shared_ptr<Projectile>>& basicTower::getProjectiles() {
  return projectiles_;
}

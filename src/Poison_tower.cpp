#include "Poison_tower.hpp"

PoisonTower::PoisonTower() : Tower("assets/poison_tower.png", 3, 1, 2000)
{
    price_ = 50;
}

PoisonTower::~PoisonTower() { }

void PoisonTower::fire() {
  projectiles_.push_back(
      std::make_shared<PoisonProjectile>(target_, sprite_.getPosition()));
}

std::vector<std::shared_ptr<Projectile>>& PoisonTower::getProjectiles() {
  return projectiles_;
}
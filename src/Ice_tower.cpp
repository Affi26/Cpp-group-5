#include "Ice_tower.hpp"

IceTower::IceTower() : Tower("assets/ice_tower.png", 2, 1, 3000)
{
    price_ = 25;
}

IceTower::~IceTower() { }

void IceTower::fire() {
  projectiles_.push_back(
      std::make_shared<IceProjectile>(target_, sprite_.getPosition()));
}

std::vector<std::shared_ptr<Projectile>>& IceTower::getProjectiles() {
  return projectiles_;
}

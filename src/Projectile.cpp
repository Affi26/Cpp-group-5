
#include "Projectile.hpp"

#include <iostream>

Projectile::Projectile(std::string texturePath, int type,
                       std::shared_ptr<Enemy> enemy,
                       const sf::Vector2f origin) {
  type_ = type;
  texture_.loadFromFile(texturePath);
  sprite_.setTexture(texture_);
  sprite_.setPosition(origin);
  sprite_.setOrigin(50, 50);
  sprite_.scale(1.5, 1.5);
  enemy_ = enemy;
  hitbox_ = {sprite_.getPosition().x - 1, sprite_.getPosition().y - 1, 2, 2};
}

Projectile::~Projectile() {}

sf::Sprite& Projectile::getSprite() { return sprite_; }

sf::FloatRect& Projectile::getHitbox() { return hitbox_; }
int Projectile::getDamage() const { return damage_; }

std::shared_ptr<Enemy> Projectile::getEnemy() { return enemy_; }

bool Projectile::move() {
  float delta_x = enemy_->getSprite().getPosition().x - sprite_.getPosition().x;
  float delta_y = enemy_->getSprite().getPosition().y - sprite_.getPosition().y;

  if (enemy_->isalive()) {
    if (delta_x < 0)
      delta_x = -1;
    else if (delta_x > 0)
      delta_x = 1;

    if (delta_y < 0)
      delta_y = -1;
    else if (delta_y > 0)
      delta_y = 1;

    sprite_.move(delta_x * speed_,
                 delta_y * speed_);  // multiply deltas by movement speed

    hitbox_.left = sprite_.getPosition().x - 1;
    hitbox_.top = sprite_.getPosition().y - 1;
    if (enemy_->getHitbox().intersects(hitbox_)) {
      if (type_ == 1 && enemy_->getType() == 1) {
        enemy_->takeDamage(0);
      } else if (type_ == 2) { // if poison projectile hits enemy, apply poison
        if (enemy_->getType() == 1) { // stealth enemy immune to poison
          enemy_->takeDamage(0);
        } else { enemy_->getPoisoned(); }
      } else if (type_ == 3) { // if ice projectile hits enemy, freeze enemy
        if (enemy_->getType() != 2) { // boss enemy immune to freeze
          enemy_->Freeze();
        }
      }

      else {      
        enemy_->takeDamage(damage_);
          if (enemy_->getHitpoints() <= 0 && !enemy_->isalive()) {
            enemy_->kill();
          }
        }
        return true;
      }
      return false;
    }
    return true;
}
#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy(std::string texturePath, int type, std::shared_ptr<Node> n,
             int hitpoints, int speed)
    : steps_taken_(0), next_point_(n) {
  texture_.loadFromFile(texturePath);

  sprite_.setTexture(texture_);

  sprite_.setPosition(next_point_->get_cord());

  sprite_.setOrigin(50, 50);

  alive_ = true;

  frozen_ = false;

  type_ = type;

  hitpoints_ = hitpoints;

  speed_ = speed;

  hitbox_ = {sprite_.getPosition().x - 10, sprite_.getPosition().y - 20, 20,
             40};

  death_sound_buffer_.loadFromFile("assets/death_sound.wav");
  death_sound_.setBuffer(death_sound_buffer_);

  // sprite_.getTransform().transformRect(hitbox_);
}

Enemy::~Enemy() {}

sf::Sprite& Enemy::getSprite() { return sprite_; }

void Enemy::kill() {
  death_sound_.play();
  alive_ = false;
}
bool Enemy::isalive() { return alive_; }

sf::FloatRect& Enemy::getHitbox() { return hitbox_; }

int Enemy::getHitpoints() { return hitpoints_; }
void Enemy::setHitpoints(int hp) { hitpoints_ = hp; }

void Enemy::takeDamage(const int& dmg) { hitpoints_ -= dmg; }

int Enemy::getSpeed() { return speed_; }

int Enemy::getType() { return type_; }

bool Enemy::shouldPay() {
  if (has_payed_) {
    return false;
  }
  has_payed_ = true;
  return true;
}

void Enemy::getPoisoned() { poisoned_ += 300; }

void Enemy::checkPoisonDamage() {
  if (alive_) {
    if (poisoned_ > 0) {
      poisoned_--;
      if (poison_timer_ > 0) {
        poison_timer_--;
      } else {
        takeDamage(1);
        poison_timer_ = 30;
      }
    }
    if (hitpoints_ <= 0) {
      kill();
    }
  }
}

bool Enemy::isFrozen() { return frozen_; }

void Enemy::Freeze() {
  frozen_ = true;
  freeze_timer_ = 120;
}

void Enemy::unFreeze() { frozen_ = false; }

void Enemy::checkFreeze() {
  if (freeze_timer_ > 0) {
    freeze_timer_--;
  } else {
    unFreeze();
  }
}

//################## Movement ##################
void Enemy::move() {
  if (!frozen_) {
    steps_taken_++;
    sprite_.move(
        sf::Vector2f(speed_ * delta_x,
                     speed_ * delta_y));  // multiply deltas by movement speed
    hitbox_.left = sprite_.getPosition().x - 10;
    hitbox_.top = sprite_.getPosition().y - 20;
  }
}

bool Enemy::atCheckpoint() {
  if (sprite_.getPosition().x == next_point_->get_cord().x &&
      sprite_.getPosition().y == next_point_->get_cord().y)
    return true;
  return false;
}

bool Enemy::setCheckpoint() {
  next_point_ = next_point_->get_next();
  if (next_point_ == nullptr) {
    return true;
  }
  delta_x = next_point_->get_cord().x - sprite_.getPosition().x;
  delta_y = next_point_->get_cord().y - sprite_.getPosition().y;
  if (delta_x < 0)
    delta_x = -1;
  else if (delta_x > 0)
    delta_x = 1;

  if (delta_y < 0)
    delta_y = -1;
  else if (delta_y > 0)
    delta_y = 1;
  return false;
}

int Enemy::getSteps() { return steps_taken_; }
//################## Movement ##################

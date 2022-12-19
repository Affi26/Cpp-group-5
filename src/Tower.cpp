#include "Tower.hpp"

Tower::Tower(std::string texturePath, int type, float range, int attack_speed) {
  texture_.loadFromFile(texturePath);
  sprite_.setTexture(texture_);
  sprite_.setOrigin(26, 26.5);
  sprite_.scale(1.92, 1.89);
  selected_ = false;
  type_ = type;
  range_ = range;
  attack_speed_ = attack_speed;
  //############# Range circle ##############
  range_circle_.setRadius(150 * range_);
  range_circle_.setOutlineColor(sf::Color::Red);
  sf::Color fillColor(255, 0, 0, 30);
  range_circle_.setFillColor(fillColor);
  range_circle_.setOutlineThickness(5);
  range_circle_.setOrigin(range_circle_.getRadius(), range_circle_.getRadius());
  last_fire_time_ = sf::milliseconds(0);

  font_.loadFromFile("assets/LEMONMILK-Light.otf");
  text_.setFont(font_);
  text_.setString(std::to_string(level_));
  text_.setCharacterSize(20);
  text_.setFillColor(sf::Color::Black);
}
void Tower::setSelected() { selected_ = true; }

void Tower::upgrade() {
  level_ += 1;
  text_.setString(std::to_string(level_));
  attack_speed_ -= 200;
}
void Tower::resetSelected() { selected_ = false; }
bool Tower::isSelected() const { return selected_; }

Tower::~Tower() {}
sf::Sprite& Tower::getSprite() { return sprite_; }

int Tower::getRange() const { return range_; }
int Tower::getAttackSpeed() const { return attack_speed_; }
int Tower::getType() const { return type_; }

int Tower::getLevel() const { return level_; }

sf::CircleShape& Tower::getRangeCircle() { return range_circle_; }

void Tower::setTarget(std::shared_ptr<Enemy> enemy) {
  target_ = enemy;
  has_target_ = true;
}

void Tower::removeTarget() { has_target_ = false; }

bool Tower::hasTarget() { return has_target_; }

std::shared_ptr<Enemy> Tower::getTarget() { return target_; }

void Tower::setLastFireTime(sf::Time time) { last_fire_time_ = time; }
sf::Time Tower::getLastFireTime() const { return last_fire_time_; }

sf::Text& Tower::getText() { return text_; }

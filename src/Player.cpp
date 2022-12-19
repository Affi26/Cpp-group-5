#include "Player.hpp"

Player::Player(int hp, int money) : health_(hp), money_(money) {
  font_.loadFromFile("assets/LEMONMILK-Light.otf");
  hp_text_.setFont(font_);
  hp_text_.setString(std::string("HP: ").append(std::to_string(health_)));
  hp_text_.setCharacterSize(20);
  hp_text_.setFillColor(sf::Color::White);
  hp_text_.setPosition(900, 500);
  money_text_.setFont(font_);
  money_text_.setString(std::string("Money: ").append(std::to_string(money_)));
  money_text_.setCharacterSize(20);
  money_text_.setFillColor(sf::Color::White);
  money_text_.setPosition(900, 550);
}

void Player::giveMoney(int amount) { money_ += amount; }

bool Player::takeMoney(int amount) {
  if (amount <= money_) {
    money_ -= amount;
    return true;
  }
  return false;
}

void Player::heal(int amount) { health_ += amount; }

bool Player::takeDamage(int amount) {
  if (amount <= health_) {
    health_ -= amount;
    return true;
  }
  return false;
}

int Player::getHealth() { return health_; }

int Player::getMoney() { return money_; }

sf::Text& Player::getHealthText() {
  hp_text_.setString(std::string("HP: ").append(std::to_string(health_)));
  return hp_text_;
}

sf::Text& Player::getMoneyText() {
  money_text_.setString(std::string("Money: ").append(std::to_string(money_)));
  return money_text_;
}

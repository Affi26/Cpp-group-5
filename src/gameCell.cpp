#include "gameCell.hpp"

GameCell::GameCell(std::string path, float x, float y, bool passable, bool exit, bool start) {
    if (!setUpSprite(path)) {
        std::cout << "ERROR: Failed to retrieve texture!" << std::endl;
        return;
    }
    sprite_.setOrigin(50,50);
    pos_ = sf::Vector2f(x, y);
    sprite_.setOrigin(50, 50);
    sprite_.setPosition(pos_);
    isPassable_ = passable;
    isExit_ = exit;
    isStart_ = start;
}

bool GameCell::setUpSprite(std::string path) {
  if (!texture_.loadFromFile(path)) {
    return false;
  }
  texture_.setSmooth(true);
  sprite_.setTexture(texture_);
  sprite_.setTextureRect(sf::IntRect(0, 0, 100, 100));
  return true;
}

sf::Sprite& GameCell::getSprite() { return sprite_; }

#include "Button.hpp"

Button::Button(std::string texturePathN, std::string texturePathC,
               std::string text, int x_cord, int y_cord, int type) {
  type_ = type;
  texture_.loadFromFile(texturePathN);
  sprite_.setTexture(texture_);
  sprite_.setPosition(x_cord, y_cord);
  clicked_ = texturePathC;
  notClicked_ = texturePathN;

  font_.loadFromFile("assets/LEMONMILK-Light.otf");
  text_.setFont(font_);
  text_.setCharacterSize(21);
  text_.setFillColor(sf::Color::Black);
  text_.setString(text);
  text_.setPosition(sprite_.getPosition().x + 20, sprite_.getPosition().y + 20);
}

sf::Sprite& Button::getSprite() { return sprite_; }

sf::Text& Button::getText() { return text_; }

void Button::setClicked() {
  texture_.loadFromFile(clicked_);
  sprite_.setTexture(texture_);
  is_clicked_ = true;
}

void Button::setNotClicked() {
  texture_.loadFromFile(notClicked_);
  sprite_.setTexture(texture_);
  is_clicked_ = false;
}

bool Button::isClicked() { return is_clicked_; }

int Button::getType() { return type_; }

void Button::setStart()
{
  is_Start = true;
}

void Button::setFinnish()
{
  is_Finnish = true;
}

void Button::setNotStart()
{
  is_Start = false;
}

void Button::setNotFinnish()
{
  is_Finnish = false;
}

bool Button::isStart()
{
  return is_Start; 
}

bool Button::isFinnish()
{
  return is_Finnish;
}

void Button::setSprite(std::string path)
{
  texture_.loadFromFile(path);
  sprite_.setTexture(texture_);
}

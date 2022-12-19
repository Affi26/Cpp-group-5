#include "Game_over.hpp"

GameOver::GameOver(int* state) {
  font_.loadFromFile("assets/LEMONMILK-Light.otf");
  text_.setFont(font_);
  state_ = state;

  if (*state == 1) {
    window_ = new sf::RenderWindow(sf::VideoMode(1200, 600), "Victory!");
    text_.setString(std::string("Congratulations, you win! :D"));
  } else if (*state == 2) {
    window_ = new sf::RenderWindow(sf::VideoMode(1200, 600), "You lose :(");
    text_.setString(
        std::string("Unfortunately you were defeated, better luck next time"));
  }

  text_.setCharacterSize(25);
  text_.setFillColor(sf::Color::White);
  text_.setPosition((1200 - text_.getGlobalBounds().width) / 2, 150);

  buttons_.push_back(std::make_shared<Button>("assets/Button.png",
                                              "assets/Button_clicked.png",
                                              "Main menu", 300, 350, 0));
  buttons_.push_back(std::make_shared<Button>(
      "assets/Button.png", "assets/Button_clicked.png", "Quit", 700, 350, 1));
}

bool GameOver::running() { return window_->isOpen(); }

void GameOver::update() { pollEv(); }

void GameOver::render() {
  window_->clear();

  window_->draw(text_);

  for (auto& it : buttons_) {
    window_->draw(it->getSprite());
    window_->draw(it->getText());
  }

  window_->display();
}

void GameOver::checkButtons(sf::Vector2i mouse_location) {
  for (auto& it : buttons_) {
    if (it->getSprite().getGlobalBounds().contains(
            window_->mapPixelToCoords(mouse_location))) {
      if (it->getType() == 0) {
        *state_ = 0;
        window_->close();
      }
      if (it->getType() == 1) {
        *state_ = 1;
        window_->close();
      }
    }
  }
}

void GameOver::pollEv() {
  while (window_->pollEvent(event_)) {
    switch (event_.type) {
      case sf::Event::Closed:  // if window is closed
        window_->close();
        break;
      case sf::Event::MouseButtonPressed: {  // kill enemies in mouse click
                                             // (used for testing)
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(*window_);
        checkButtons(mouseLocation);
        break;
      }
      default:
        break;
    }
  }
}

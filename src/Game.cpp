#include "Game.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#include "Basic_tower.hpp"
#include "Bomb_tower.hpp"
#include "Ice_tower.hpp"
#include "Poison_tower.hpp"

Game::Game(int* state)
    : window_(new sf::RenderWindow(sf::VideoMode(1200, 600), "Awesome TDG")) {
  state_ = state;
  window_->setFramerateLimit(60);

  nodes_ = map_.getNodes();

  buttons_.push_back(std::make_shared<Button>("assets/Button.png",
                                              "assets/Button_clicked.png",
                                              "Basic tower", 900, 0, 0));
  buttons_.push_back(std::make_shared<Button>("assets/Button.png",
                                              "assets/Button_clicked.png",
                                              "Poison tower", 900, 100, 1));
  buttons_.push_back(std::make_shared<Button>("assets/Button.png",
                                              "assets/Button_clicked.png",
                                              "Bomb tower", 900, 200, 2));
  buttons_.push_back(std::make_shared<Button>("assets/Button.png",
                                              "assets/Button_clicked.png",
                                              "Ice tower", 900, 300, 3));
  buttons_.push_back(std::make_unique<Button>("assets/Button.png",
                                              "assets/Button_clicked.png",
                                              "UPGRADE", 900, 400, 4));
  buttons_.push_back(std::make_unique<Button>("assets/delete_button.png",
                                              "assets/delete_button.png", "",
                                              1100, 420, 6));
  buttons_.push_back(std::make_unique<Button>(
      "assets/play_button.png", "assets/black_button.png", "", 1100, 500, 5));

  player_ = std::make_unique<Player>(50, 100);

  button_background_.setSize(sf::Vector2f(400, 600));
  button_background_.setPosition(800, 0);
  button_background_.setFillColor(sf::Color::Black);
  paused_ = false;
  placing_new_tower = false;
  wave_number_ = 0;
}

Game::~Game() {}

bool Game::running() { return window_->isOpen(); }

bool Game::intersects(sf::CircleShape& c, sf::FloatRect& r) {
  float centerDistance_x = abs(c.getPosition().x - (r.left + (r.width / 2)));
  float centerDistance_y = abs(c.getPosition().y - (r.top + (r.height / 2)));

  if (centerDistance_x > (r.width / 2 + c.getRadius())) return false;
  if (centerDistance_y > (r.height / 2 + c.getRadius())) return false;

  if (centerDistance_x <= (r.width / 2)) return true;
  if (centerDistance_y <= (r.height / 2)) return true;

  // let's compare squares of distances to avoid having to calculate square root
  float corner_dist_squared = pow(centerDistance_x - r.width / 2, 2) +
                              pow(centerDistance_y - r.height / 2, 2);

  return (corner_dist_squared <= pow(c.getRadius(), 2));
}

bool Game::checkPositions() {
  //@todo Don't check the towers which can't fire (on cooldown);
  for (auto& itt : towers_) {
    if (!paused_) {
      for (auto& ite : enemies_) {
        if (intersects(itt->getRangeCircle(), ite->getHitbox())) {
          if (itt->hasTarget()) {
            if (itt->getTarget()->getSteps() < ite->getSteps()) {
              itt->setTarget(ite);
            }
          } else {
            itt->setTarget(ite);
          }
          // std::cout << "Enemy in range" << std::endl;
        } else {
          // std::cout << "Enemy not in range" << std::endl;
        }
      }
    }
    if (itt->hasTarget()) {
      if (clock.getElapsedTime().asMilliseconds() -
              itt->getLastFireTime().asMilliseconds() >
          itt->getAttackSpeed()) {
        itt->fire();
        // itt->removeTarget();
        itt->setLastFireTime(clock.getElapsedTime());
      }
    }
  }
  // check if any enemies are alive
  for (auto it : enemies_) {
    if (it->isalive()) {
      return false;
    }
  }

  return true;
}

void Game::checkTowers(sf::Vector2i mouse_location) {
  for (auto& it : towers_)
    if (it->getSprite().getGlobalBounds().contains(window_->mapPixelToCoords(
            mouse_location))) {  // if tower is clicked
      if (it->isSelected()) {
        it->resetSelected();
      } else if (std::find_if(towers_.begin(), towers_.end(),
                              [&](const std::shared_ptr<Tower>& tower) {
                                return tower != it && tower->isSelected();
                              }) == towers_.end()) {
        // move range circle to same position as tower
        it->setSelected();
        it->getRangeCircle().setPosition(it->getSprite().getPosition());
      }
    } else if (validPlacement(mouse_location) && it->isSelected()) {
      moveTower(it, mouse_location);
    }
}

void Game::checkButtons(sf::Vector2i mouse_location) {
  for (auto& it : buttons_) {
    if (it->getSprite().getGlobalBounds().contains(
            window_->mapPixelToCoords(mouse_location))) {
      if (it->getType() == 4) {
        if (player_->getMoney() >= 50) {
          for (auto& itt : towers_) {
            if (itt->isSelected()) {
              if (itt->getLevel() < 3) {
                player_->takeMoney(50);
                itt->upgrade();
              }
              break;
            }
          }
        }
      } else if (it->getType() == 5) {
        paused_ = false;
        it->setClicked();
      } else if (it->getType() == 6) {
        for (auto& itt : towers_) {
          if (itt->isSelected()) {
            auto itd = find(towers_.begin(), towers_.end(), itt);
            if (itd != towers_.end()) {
              player_->giveMoney(40 * itt->getLevel());
              towers_.erase(itd);
              break;
            }
          }
        }
      } else if (it->isClicked()) {
        it->setNotClicked();
        placing_new_tower = false;
      } else {
        it->setClicked();
        placing_new_tower = true;
      }
    } else if (it->isClicked() && validPlacement(mouse_location) &&
               player_->takeMoney(50)) {
      switch (it->getType()) {
        case 0: {
          towers_.push_back(std::make_shared<basicTower>());
          moveTower(towers_.back(), mouse_location);
          placing_new_tower = false;
          break;
        }
        case 1: {
          towers_.push_back(std::make_shared<PoisonTower>());
          moveTower(towers_.back(), mouse_location);
          placing_new_tower = false;
          break;
        }
        case 2: {
          towers_.push_back(std::make_shared<BombTower>());
          moveTower(towers_.back(), mouse_location);
          placing_new_tower = false;
          break;
        }
        case 3: {
          towers_.push_back(std::make_shared<IceTower>());
          moveTower(towers_.back(), mouse_location);
          placing_new_tower = false;
          break;
        }

        default:
          break;
      }
      it->setNotClicked();
    }
  }
}

void Game::showInfo(unsigned int wave_number_, unsigned int info_type) {
  sf::RenderWindow infoWindow(sf::VideoMode(300, 100), "My window");
  std::string beginning;
  std::string wave_nr;
  std::string end;
  // run the program as long as the window is open
  while (infoWindow.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (infoWindow.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) infoWindow.close();
      sf::Font font;
      font.loadFromFile("assets/arial.ttf");
      sf::Text text;
      text.setFont(font);
      switch (info_type) {
        case 1:
          beginning = " Welcome!";
          wave_nr = "";
          break;
        case 2:
          beginning = " Nice job! You passed wave ";
          wave_nr = std::to_string(wave_number_);
          break;
        default:
          break;
      }
      end =
          "\n\n Feel free to make changes to your towers,\n and press the "
          "green play button when you\n are ready.";
      std::string info_text = beginning + wave_nr + end;
      text.setString(info_text);
      text.setCharacterSize(15);
      text.setFillColor(sf::Color::Black);

      // text.setStyle(sf::Text::Bold);
      text.setPosition(0, 0);
      sf::RectangleShape rectangle(sf::Vector2f(300, 100));
      rectangle.setOrigin(0, 0);
      rectangle.setPosition(0, 0);

      infoWindow.draw(rectangle);
      infoWindow.draw(text);
      infoWindow.display();
    }
  }
}

void Game::pollEv() {
  while (window_->pollEvent(event_)) {
    switch (event_.type) {
      case sf::Event::Closed:  // if window is closed
        window_->close();
        break;
      case sf::Event::KeyPressed:  // if esc is pressed
        if (event_.key.code == sf::Keyboard::Escape) {
          window_->close();
        }
        break;
      case sf::Event::MouseButtonPressed: {  // kill enemies in mouse click
                                             // (used for testing)
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(*window_);
        // check if any towers are clicked
        if (!placing_new_tower) {
          checkTowers(mouseLocation);
        }
        // check if any buttons are clicked
        checkButtons(mouseLocation);

      } break;

      default:
        break;
    }
  }
}

void Game::render() {
  window_->clear();
  // draw map tiles
  for (auto& row : map_.getTiles()) {
    for (auto& cell : row) {
      window_->draw(cell->getSprite());
    }
  }

  // draw enemies
  if (!paused_) {
    for (auto& it : enemies_) {
      if (it->isalive()) {
        window_->draw(it->getSprite());
        if (it->atCheckpoint()) {  // if enemy is at checkpoint, set new
                                   // checkpoint
          if (it->setCheckpoint()) player_->takeDamage(50);
        }
      }
      it->move();
      it->checkPoisonDamage();
      it->checkFreeze();
    }
  }

  // draw towers
  for (auto& it : towers_) {
    window_->draw(it->getSprite());
    window_->draw(it->getText());
    if (it->isSelected()) {  // if tower is selected, draw range circle
      window_->draw(it->getRangeCircle());
    }
    if (!it->getProjectiles().empty()) {
      for (auto itp : it->getProjectiles()) {
        if (!itp->move() &&
            intersects(it->getRangeCircle(), itp->getHitbox())) {
          window_->draw(itp->getSprite());
        } else {
          // it->getProjectiles().clear();
          if (!itp->getEnemy()->isalive() && itp->getEnemy()->shouldPay()) {
            switch ((itp->getEnemy()->getType())) {
              case (0): {
                player_->giveMoney(25);
                break;
              }
              case (1): {
                player_->giveMoney(50);
                break;
              }
              case (2): {
                player_->giveMoney(100);
                break;
              }
            }
          }

          it->getProjectiles().erase(
              std::remove(it->getProjectiles().begin(),
                          it->getProjectiles().end(), itp),
              it->getProjectiles().end());
        }
      }
      it->removeTarget();
    }
  }

  // draw buttons
  window_->draw(button_background_);

  for (auto& it : buttons_) {
    window_->draw(it->getSprite());
    window_->draw(it->getText());
  }

  window_->draw(player_->getMoneyText());

  if (player_->getHealth() <= 0) {
    (*state_) = 2;
    window_->close();
  }

  window_->display();
}

void Game::update() {
  // check for any mouse clicks
  pollEv();
  //

  if (checkPositions() && !paused_) {
    wave_number_++;
    enemies_ = Wave(wave_number_, nodes_[0]).getEnemies();
    paused_ = true;
    buttons_.back()->setNotClicked();
    render();
    // end game if wave_number = 6, otherwise show info.
    if (wave_number_ == 6) {
      (*state_) = 1;
      window_->close();
    } else if (wave_number_ > 1) {
      showInfo(wave_number_ - 1, 2);
    } else {
      showInfo(wave_number_, 1);
    }
  }
}

void Game::moveTower(std::shared_ptr<Tower>& tower,
                     const sf::Vector2i& mouse_location) {
  tower->getSprite().setPosition(window_->mapPixelToCoords(mouse_location));
  tower->getRangeCircle().setPosition(
      window_->mapPixelToCoords(mouse_location));
  tower->getText().setPosition(
      window_->mapPixelToCoords(mouse_location).x + 37,
      window_->mapPixelToCoords(mouse_location).y + 28);
}

bool Game::validPlacement(sf::Vector2i mouse_location) { // checks if a tower can be placed on mouse_location
  if (mouse_location.x > 750) {
    return false;
  }
  for (auto& row : map_.getTiles()) {
    for (auto& cell : row) {
      if (std::find_if(
              towers_.begin(), towers_.end(),
              [&](const std::shared_ptr<Tower>& placed_tower) {
                return placed_tower->getSprite().getGlobalBounds().contains(
                    window_->mapPixelToCoords(mouse_location));
              }) != towers_.end()) {
        return false;
        // showErrorMessage("Can't place tower on tower!");
        // tower->resetSelected();
      } else if (cell->getSprite().getGlobalBounds().contains(
                     window_->mapPixelToCoords(mouse_location)) &&
                 cell->isPassable_) {
        // showErrorMessage("Can't place tower on road!");
        return false;
      }
    }
  }
  return true;
}
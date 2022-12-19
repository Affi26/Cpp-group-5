#include <iostream>
#include <fstream>
#include <string>

#include "mapCreator.hpp"
#include "Game.hpp"

mapCreator::mapCreator()
    : window_(new sf::RenderWindow(sf::VideoMode(1200, 600), "Map Creator")), saveButton_(new Button("assets/Button.png",
    "assets/Button_clicked.png", "Save Map", 900, 100, 7)), mainMenuButton_(new Button("assets/Button.png",
    "assets/Button_clicked.png", "Main Menu", 900, 200, 7)), setStartButton_(new Button("assets/Button.png",
    "assets/Button_clicked.png", "Set Start", 900, 300, 7)), setFinnishButton_((new Button("assets/Button.png",
    "assets/Button_clicked.png", "Set Finnish", 900, 400, 7))) {
    std::vector<std::shared_ptr<Button>> row;
    for (int y = 0; y < 600; y += 100) {
        for (int x = 0; x < 800; x += 100) {
            row.push_back(std::make_shared<Button>("assets/grass.png",
                            "assets/road.png", "", x, y, 6));
        }
        buttons_.push_back(row);
        row.clear();
    }
    Render();
    showInfo(1);
}

mapCreator::~mapCreator() { }

bool mapCreator::isRunning()
{
    return window_->isOpen(); 
}

void mapCreator::Render()
{
    window_->clear();
    for (auto& it : buttons_) {
        for (auto& button : it) {
            window_->draw(button->getSprite());
        }
    }
    window_->draw(saveButton_->getSprite());
    window_->draw(saveButton_->getText());
    window_->draw(mainMenuButton_->getSprite());
    window_->draw(mainMenuButton_->getText());
    window_->draw(setStartButton_->getSprite());
    window_->draw(setStartButton_->getText());
    window_->draw(setFinnishButton_->getSprite());
    window_->draw(setFinnishButton_->getText());
    window_->display();
}

void mapCreator::Update()
{
    pollEv();
}

void mapCreator::pollEv()
{
    while (window_->pollEvent(event_)) {
        if(event_.type == sf::Event::Closed) {
            window_->close();
        } else if (event_.type == sf::Event::KeyPressed) {
            switch (event_.key.code)
            {
            case sf::Keyboard::Escape:
                window_->close();
                break;
            default:
                break;
            }
        } else if (event_.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mouseLocation = sf::Mouse::getPosition(*window_);
            checkButtons(mouseLocation);
        }
    }
}

void mapCreator::showInfo(unsigned int info_type) {
  sf::RenderWindow infoWindow(sf::VideoMode(300, 100), "My window");
  std::string info_text;
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
      switch (info_type)
      {
      case 1:
        info_text = "Welcome to the map creator!\nHere you can create a map by clicking on\nthe game tiles.\nRemember to define start and finnish!";
        break;
      case 2:
        info_text = "Map saved successfully!";
        break;
      default:
        break;
      }
      text.setString(info_text);
      text.setCharacterSize(15);
      text.setFillColor(sf::Color::Black);
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

void mapCreator::checkButtons(sf::Vector2i mouseLocation)
{   
    if (saveButton_->getSprite().getGlobalBounds().contains(window_->mapPixelToCoords(mouseLocation))) {
        char tile;
        std::string line;
        std::ofstream file("assets/map.txt");
        for(auto& it : buttons_) {
            for(auto& button : it) {
                if(button->isClicked()) {
                    if (button->isFinnish()) {
                        tile = '?';
                    } else if (button->isStart()) {
                        tile = '!';
                    } else {
                        tile = '=';
                    }
                } else {
                    tile = '#';
                }
                line += tile;
            }
            file << line << std::endl;
            line = "";
        }
        file.close();

        showInfo(2);
    } else if (setStartButton_->getSprite().getGlobalBounds().contains(window_->mapPixelToCoords(mouseLocation))) {
        if (setStartButton_->isClicked()) {
            setStartButton_->setNotClicked();
        } else if (!setFinnishButton_->isClicked()) {
            setStartButton_->setClicked();
        }
    } else if (setFinnishButton_->getSprite().getGlobalBounds().contains(window_->mapPixelToCoords(mouseLocation))) {
        if (setFinnishButton_->isClicked()) {
            setFinnishButton_->setNotClicked();
        } else if (!setStartButton_->isClicked()) {
            setFinnishButton_->setClicked();
        }
    } else if (mainMenuButton_->getSprite().getGlobalBounds().contains(window_->mapPixelToCoords(mouseLocation))) {
        window_->close();
    }

    if (setStartButton_->isClicked()) {
        for (auto& it : buttons_) {
            for (auto& button : it) {
                if (button->getSprite().getGlobalBounds().contains(
                window_->mapPixelToCoords(mouseLocation))) {
                    if (button->isClicked()) {
                        setStartButton_->setNotClicked();
                        button->setSprite("assets/start.png");
                        button->setStart();
                        button->setNotFinnish();
                    }
                }
            }
        }
    } else if (setFinnishButton_->isClicked()) {
        for (auto& it : buttons_) {
            for (auto& button : it) {
                if (button->getSprite().getGlobalBounds().contains(
                window_->mapPixelToCoords(mouseLocation))) {
                    if (button->isClicked()) {
                        setFinnishButton_->setNotClicked();
                        button->setSprite("assets/end.png");
                        button->setFinnish();
                        button->setNotStart();
                    }
                }
            }
        }
    } else {
        for (auto& it : buttons_) {
            for (auto& button : it) {
                if (button->getSprite().getGlobalBounds().contains(
                window_->mapPixelToCoords(mouseLocation))) {
                    if (button->isClicked()) {
                        button->setNotClicked();
                    } else {
                        button->setClicked();
                    }
                    button->setNotFinnish();
                    button->setNotStart();
                }
            }
        }
    }
}

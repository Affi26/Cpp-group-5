#include "mainMenu.hpp"

mainMenu::mainMenu()
    : window_(new sf::RenderWindow(sf::VideoMode(1200, 600), "Main Menu")), 
    playButtonSelected_(true), playButtonPressed_(false), exitButtonSelected_(false), exitButtonPressed_(false),
    mapButtonSelected_(false), mapButtonPressed_(false) { 
    font_.loadFromFile("assets/arial.ttf");
    gameTitle_.setFont(font_);
    gameTitle_.setString("THE TOWERS OF POWER");
    gameTitle_.setCharacterSize(50);
    gameTitle_.setOrigin(gameTitle_.getLocalBounds().width/2, gameTitle_.getLocalBounds().height/2);
    gameTitle_.setPosition(window_->getSize().x/2, window_->getSize().y/2 - 150.f);
    
    playButton_.setFont(font_);
    playButton_.setString("Play");
    playButton_.setCharacterSize(30);
    playButton_.setOrigin(playButton_.getLocalBounds().width/2, playButton_.getLocalBounds().height/2);
    playButton_.setPosition(window_->getSize().x/2, window_->getSize().y/2 - 25.f);

    mapButton_.setFont(font_);
    mapButton_.setString("Create Map");
    mapButton_.setCharacterSize(30);
    mapButton_.setOrigin(mapButton_.getLocalBounds().width/2, mapButton_.getLocalBounds().height/2);
    mapButton_.setPosition(window_->getSize().x/2, window_->getSize().y/2 + 25);
    
    exitButton_.setFont(font_);
    exitButton_.setString("Quit");
    exitButton_.setCharacterSize(30);
    exitButton_.setOrigin(exitButton_.getLocalBounds().width/2, exitButton_.getLocalBounds().height/2);
    exitButton_.setPosition(window_->getSize().x/2, window_->getSize().y/2 + 75.f); 
}

bool mainMenu::isRunning()
{
    return window_->isOpen(); 
}

int mainMenu::getNextWindow()
{
    return next_window_;
}

void mainMenu::Render() {
    window_->clear();
    window_->draw(gameTitle_);
    window_->draw(playButton_);
    window_->draw(mapButton_);
    window_->draw(exitButton_);
    window_->display();
}

void mainMenu::Update()
{
    pollEv();
    if (playButtonSelected_) {
        playButton_.setFillColor(sf::Color::Yellow);
        mapButton_.setFillColor(sf::Color::White);
        exitButton_.setFillColor(sf::Color::White);
    } else if (mapButtonSelected_) {
        playButton_.setFillColor(sf::Color::White);
        mapButton_.setFillColor(sf::Color::Yellow);
        exitButton_.setFillColor(sf::Color::White);
    } else {
        playButton_.setFillColor(sf::Color::White);
        mapButton_.setFillColor(sf::Color::White);
        exitButton_.setFillColor(sf::Color::Yellow);
    }

    if (mapButtonPressed_) {
        next_window_ = 2;
        window_->close();
    } else if(playButtonPressed_) {
        next_window_ = 1;
        window_->close();
    } else if (exitButtonPressed_) {
        next_window_ = 0;
        window_->close();
    } 
}

void mainMenu::pollEv() {
  while (window_->pollEvent(event_)) {
    if(event_.type == sf::Event::Closed) {
        playButtonPressed_ = false;
        mapButtonPressed_ = false;
        exitButtonPressed_ = true;
    } else if (event_.type == sf::Event::KeyPressed) {
        switch (event_.key.code) {
            case sf::Keyboard::Escape: 
                playButtonPressed_ = false;
                mapButtonPressed_ = false;
                exitButtonPressed_ = true;
                break;
            case sf::Keyboard::Up: 
                if (!playButtonSelected_) {
                    if (mapButtonSelected_) {
                        playButtonSelected_ = true;
                        mapButtonSelected_ = false;
                        exitButtonSelected_ = false;
                    } else {
                        playButtonSelected_ = false;
                        mapButtonSelected_ = true;
                        exitButtonSelected_ = false;   
                    }
                }
                break;
            case sf::Keyboard::Down:
                if (!exitButtonSelected_) {
                    if (mapButtonSelected_) {
                        playButtonSelected_ = false;
                        mapButtonSelected_ = false;
                        exitButtonSelected_ = true;
                    } else {
                        playButtonSelected_ = false;
                        mapButtonSelected_ = true;
                        exitButtonSelected_ = false;
                    }
                }
                break;
            case sf::Keyboard::Return:
                playButtonPressed_ = false;
                mapButtonPressed_ = false;
                exitButtonPressed_ = false;
                if (playButtonSelected_) {
                    playButtonPressed_ = true;
                } else if (mapButtonSelected_) {
                    mapButtonPressed_ = true;
                } else {
                    exitButtonPressed_ = true;
                }
                break;
            default:
                break;
        }
    } else if (event_.type == sf::Event::MouseButtonPressed) {
        sf::FloatRect rectPlay(playButton_.getPosition().x, playButton_.getPosition().y, playButton_.getGlobalBounds().width, playButton_.getGlobalBounds().height);
        sf::FloatRect rectMap(mapButton_.getPosition().x, mapButton_.getPosition().y, mapButton_.getGlobalBounds().width, mapButton_.getGlobalBounds().height);
        sf::FloatRect rectExit(exitButton_.getPosition().x, exitButton_.getPosition().y, exitButton_.getGlobalBounds().width, exitButton_.getGlobalBounds().height);
        sf::Vector2i mouseLocation = sf::Mouse::getPosition(*window_);
        if (rectPlay.contains(window_->mapPixelToCoords(mouseLocation))) {
            playButtonSelected_ = true;
            mapButtonSelected_ = false;
            exitButtonSelected_ = false;

            playButtonPressed_ = true;
            mapButtonPressed_ = false;
            exitButtonPressed_ = false;
        } else if (rectMap.contains(window_->mapPixelToCoords(mouseLocation))) {
            playButtonSelected_ = false;
            mapButtonSelected_ = true;
            exitButtonSelected_ = false;

            playButtonPressed_ = false;
            mapButtonPressed_ = true;
            exitButtonPressed_ = false;
        } else if (rectExit.contains(window_->mapPixelToCoords(mouseLocation))) {
            playButtonSelected_ = false;
            mapButtonSelected_ = false;
            exitButtonSelected_ = true;

            playButtonPressed_ = false;
            mapButtonPressed_ = false;
            exitButtonPressed_ = true;
        }   
    }
  }
}

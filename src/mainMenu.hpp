#ifndef __MAINMENU_H__
#define __MAINMENU_H__

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Button.hpp"

/**
 * @file mainMenu.hpp
 * @author Axel Hedman, axel.hedman@aalto.fi
 * @brief Main Menu Implementation
 * @version 0.1
 * @date 2022-12-2
 *
 * @copyright Copyright (c) 2022
 *
 */

class mainMenu {
public:
  /**
   * @brief Constructor for initializing a mainMenu object
   * 
   */
    mainMenu();

  /**
   * @brief Destructor for a mainMenu object
   * 
   */
    ~mainMenu() {}

  /**
   * @brief Draws the main menu window. Takes no parameters and returns nothing
   * 
   */
    void Render();
    
  /**
   * @brief Updates the main menu window frame by frame.
   * 
   */
    void Update();

  /**
   * @brief Checks for events in the main menu window.
   * 
   */
    void pollEv();

  /**
   * @brief Checks if the window is still open returns a boolean value.
   * 
   */
    bool isRunning();
    
  /**
   * @brief Returns an integer that defines which window to open after main menu. 
   * 
   */
    int getNextWindow();

private: 
    sf::Text gameTitle_;
    sf::Text playButton_;
    sf::Text mapButton_;
    sf::Text exitButton_;
    sf::RenderWindow* window_;
    sf::Event event_;
    sf::Font font_;
    std::vector<std::shared_ptr<Button>> buttons_;

    bool playButtonSelected_;
    bool playButtonPressed_;
    bool exitButtonSelected_;
    bool exitButtonPressed_; 
    bool mapButtonSelected_;
    bool mapButtonPressed_;

    int next_window_;
};

#endif // __MAINMENU_H__
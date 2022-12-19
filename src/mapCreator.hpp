#ifndef __MAPCREATOR_H__
#define __MAPCREATOR_H__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Button.hpp"

/**
 * @file mapCreator.hpp
 * @author Axel Hedman, axel.hedman@aalto.fi
 * @brief Map Creator Implementation
 * @version 0.1
 * @date 2022-11-27
 *
 * @copyright Copyright (c) 2022
 *
 */

class mapCreator {
public:
  /**
   * @brief Constructor for initializing a mapCreator object
   * 
   */
    mapCreator();

  /**
   * @brief mapCreator object destructor
   *  
   */
    ~mapCreator();
    
  /**
   * @brief Draws the map creator window. Takes no parameters and returns nothing
   * 
   */
    void Render();

  /**
   * @brief Updates the map creator window frame by frame.
   * 
   */
    void Update();

  /**
   * @brief Checks for events in the map creator window.
   * 
   */
    void pollEv();

  /**
   * @brief Checks if a button or a game tile gets pressed in the map creator window.
   * 
   */
    void checkButtons(sf::Vector2i mouseLocation);
 
  /**
   * @brief Checks if the map creator window is still open returns a boolean value.
   * 
   */
    bool isRunning();

    /**
   * @brief Creates and displays an info window
   * 
   */
    void showInfo(unsigned int info_type);

private:
    sf::RenderWindow* window_;
    sf::Event event_;
    std::vector<std::vector<std::shared_ptr<Button>>> buttons_;
    std::shared_ptr<Button> saveButton_;
    std::shared_ptr<Button> mainMenuButton_;
    std::shared_ptr<Button> setStartButton_;
    std::shared_ptr<Button> setFinnishButton_;
};

#endif // __MAPCREATOR_H__
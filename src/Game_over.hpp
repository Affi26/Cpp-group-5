#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

/**
 * @file Game_over.hpp
 * @author David Enberg (david.enberg@aalto.fi)
 * @brief Handles state after game finishes execution
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Button.hpp"

/**
 * @brief Handles state after game finishes execution
 *
 */
class GameOver {
 public:
  /**
   * @brief Construct a new Game Over object
   *
   * @param state state when game finished execution
   */
  GameOver(int* state);

  /**
   * @brief If window is open
   *
   * @return true
   * @return false
   */
  bool running();

  /**
   * @brief Update the window state
   *
   */
  void update();

  /**
   * @brief Render the elemets
   *
   */
  void render();

 private:
  /**
   * @brief Check if any of the buttons has been clicked
   *
   * @param mouse_location
   */
  void checkButtons(sf::Vector2i mouse_location);

  /**
   * @brief Check for events (mouse clicks, keyboard input etc.)
   *
   */
  void pollEv();
  std::vector<std::shared_ptr<Button>> buttons_;
  sf::Event event_;
  sf::RenderWindow* window_;
  int* state_;
  sf::Text text_;
  sf::Font font_;
};
#endif  // __GAME_OVER_H__
#ifndef __BUTTON_H__
#define __BUTTON_H__

/**
 * @file Button.hpp
 * @author David Enberg (david.enberg@aalto.fi)
 * @brief
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <SFML/Graphics.hpp>

/**
 * @brief Class for implementing buttons using SFML
 *
 */
class Button {
 public:
  /**
   * @brief Construct a new Button object
   *
   * @param texturePathN Texture path for not clicked button
   * @param texturePathC Texture path for clicked button
   * @param text Text on button
   * @param x_cord X-coordinate of the button
   * @param y_cord Y-coordinate of the button
   * @param type Type of button
   */
  Button(std::string texturePathN, std::string texturePathC, std::string text,
         int x_cord, int y_cord, int type);

  /**
   * @brief Get the Sprite object
   *
   * @return sf::Sprite&
   */
  sf::Sprite& getSprite();

  /**
   * @brief Get the Text object
   *
   * @return sf::Text&
   */
  sf::Text& getText();

  /**
   * @brief Set the button to clicked state
   *
   */
  void setClicked();

  /**
   * @brief Set the button to not clicked state
   *
   */
  void setNotClicked();

  /**
   * @brief Check if the button has been clicked
   *
   * @return true
   * @return false
   */
  bool isClicked();

  /**
   * @brief Get the type of button
   *
   * @return int
   */
  int getType();

  /**
   * @brief Set the button as a start button
   *
   */
  void setStart();

  /**
   * @brief Set the buttons as a finish button
   *
   */
  void setFinnish();

  /**
   * @brief Set the button to not be a start button
   *
   */
  void setNotStart();

  /**
   * @brief Set the button to not be a finish button
   *
   */
  void setNotFinnish();

  /**
   * @brief Check if button is a start button
   *
   * @return true
   * @return false
   */
  bool isStart();

  /**
   * @brief Check if button is a finish button
   *
   * @return true
   * @return false
   */
  bool isFinnish();

  /**
   * @brief Set the sprite for the button
   *
   * @param path path to the texture for the sprite
   */
  void setSprite(std::string path);

 private:
  int type_;
  bool is_clicked_ = false;
  bool is_Start = false;
  bool is_Finnish = false;
  sf::Text text_;
  sf::Font font_;
  sf::Texture texture_;
  sf::Sprite sprite_;
  std::string clicked_;
  std::string notClicked_;
};
#endif  // __BUTTON_H__
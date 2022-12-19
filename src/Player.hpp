#ifndef __PLAYER_H__
#define __PLAYER_H__
/**
 * @file Player.hpp
 * @author David Enberg (david.enberg@aalto.fi)
 * @brief Class for handling status of player
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <SFML/Graphics.hpp>

/**
 * @brief Class for handling gamestate from player perspective
 *
 */
class Player {
 public:
  /**
   * @brief Construct a new Player object
   *
   * @param hp starting health
   * @param money starting money
   */
  Player(int hp = 0, int money = 0);

  /**
   * @brief Add money to player
   *
   * @param amount amount to add
   */
  void giveMoney(int amount);

  /**
   * @brief Remove money from player
   *
   * @param amount to remove
   * @return true if player has enough money
   * @return false if player does not have enough money
   */
  bool takeMoney(int amount);

  /**
   * @brief Add health to player
   *
   * @param amount amount to heal
   */
  void heal(int amount);

  /**
   * @brief remove health from player
   *
   * @param amount amount to remove
   * @return true
   * @return false
   */
  bool takeDamage(int amount);

  /**
   * @brief Get the Health amount
   *
   * @return int amount of health
   */
  int getHealth();

  /**
   * @brief Get the Money amount
   *
   * @return int amount of money
   */
  int getMoney();

  /**
   * @brief Get the Health Text object
   *
   * @return sf::Text&
   */
  sf::Text& getHealthText();

  /**
   * @brief Get the Money Text object
   *
   * @return sf::Text&
   */
  sf::Text& getMoneyText();

 private:
  int health_;
  int money_;
  sf::Text hp_text_;
  sf::Text money_text_;
  sf::Font font_;
};
#endif  // __PLAYER_H__
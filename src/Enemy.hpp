#ifndef __ENEMY_H__
#define __ENEMY_H__

/**
 * @file Enemy.hpp
 * @author David Enberg david.enberg@aalto.fi
 * @brief Parent class for all enemies
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Node.hpp"

/**
 * @brief Enemy parent class
 *
 */
class Enemy {
 public:
  /**
   * @brief Construct a new Enemy object
   *
   * @param texturePath path to the texture
   * @param type type of enemy
   * @param n Node to begin from
   * @param hitpoints amount of hitpoints
   * @param speed
   */
  Enemy(std::string texturePath, int type, std::shared_ptr<Node> n,
        int hitpoints, int speed);

  /**
   * @brief Destroy the Enemy object
   *
   */
  virtual ~Enemy();

  /**
   * @brief Get the Sprite object
   *
   * @return sf::Sprite&
   */
  sf::Sprite& getSprite();

  /**
   * @brief kill the enemy
   *
   */
  void kill();

  /**
   * @brief Move the enemy
   *
   */
  void move();

  /**
   * @brief check if enemy is alive
   *
   * @return true if alive
   * @return false otherwise
   */
  bool isalive();

  /**
   * @brief Get the Hitbox object
   *
   * @return sf::FloatRect&
   */
  sf::FloatRect& getHitbox();

  /**
   * @brief Get the Hitpoints amount
   *
   * @return int
   */
  int getHitpoints();

  /**
   * @brief Set the amount of hitpoints
   *
   * @param hp new hitpoint amount
   */
  void setHitpoints(int hp);

  /**
   * @brief Deal damage to an enemy
   *
   * @param dmg
   */
  void takeDamage(const int& dmg);

  /**
   * @brief Get the speed of the enemy
   *
   * @return int speed
   */
  int getSpeed();

  /**
   * @brief Get the Type
   *
   * @return int type
   */
  int getType();

  /**
   * @brief function to check if enemy has payed out
   *
   * @return true if enemy has no payed out
   * @return false otherwise
   */
  bool shouldPay();

  /**
   * @brief Apply poison to enemy
   *
   */
  void getPoisoned();

  /**
   * @brief Check for poison damage
   *
   */
  void checkPoisonDamage();

  /**
   * @brief check if enemy is currently frozen
   *
   * @return true
   * @return false
   */
  bool isFrozen();

  /**
   * @brief freeze the enemy object
   *
   */
  void Freeze();

  /**
   * @brief unfreeze the enemy object
   *
   */
  void unFreeze();

  /**
   * @brief check if enemy is frozen
   *
   */
  void checkFreeze();

  //#################### Movement #######################

  /**
   * @brief check if enemy has reached its next checkpoint
   *
   * @return true
   * @return false
   */
  bool atCheckpoint();

  /**
   * @brief Set the next checkpoint of the enemy
   *
   * @return true if finished is reached
   * @return false otherwise
   */
  bool setCheckpoint();

  /**
   * @brief Get the amount of steps taken by enemy object
   *
   * @return int
   */
  int getSteps();
  //#################### Movement #######################

 protected:
  int hitpoints_;
  int speed_;
  int steps_taken_;
  bool frozen_;
  int freeze_timer_ = 0;
  int poisoned_ = 0;
  int poison_timer_ = 0;

 private:
  bool x_goal_;
  bool y_goal_;
  sf::Texture texture_;
  sf::Sprite sprite_;

  bool has_payed_ = false;
  bool alive_;
  int type_;
  sf::FloatRect hitbox_;
  std::shared_ptr<Node> next_point_;
  int delta_x;
  int delta_y;
  sf::SoundBuffer death_sound_buffer_;
  sf::Sound death_sound_;
};

#endif  // __ENEMY_H__
#ifndef __TOWER_H__
#define __TOWER_H__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Basic_projectile.hpp"
#include "Bomb_projectile.hpp"
#include "Enemy.hpp"
#include "Ice_projectile.hpp"
#include "Poison_projectile.hpp"
#include "Projectile.hpp"

/**
 * \brief Parent class for different towers
 * 
 */
class Tower {
 public:
  /**
   * \brief Tower constructor.
   * \param texturePath Path to the tower sprite.
   * \param type Type of tower.
   * \param range The towers range.
   * \param attack_speed The towers attack speed.
   */

  Tower(std::string texturePath, int type, float range, int attack_speed);

  /**
   * \brief Tower destructor.
   */
  virtual ~Tower();

  /**
   * \brief Get the Sprite object
   * 
   * \return sf::Sprite& 
   */
  sf::Sprite& getSprite();

  /**
   * \brief Set the object state as selected (true)
   * 
   */
  void setSelected();

  /**
   * \brief Set the object state as not selected (false)
   * 
   */
  void resetSelected();

  /**
   * \brief Upgrade the tower attack speed
   * 
   */
  void upgrade();

  /**
   * \brief Check if the tower is selected
   * 
   * \return true 
   * \return false 
   */
  bool isSelected() const;

  /**
   * \brief Get the tower range
   * 
   * \return int 
   */
  int getRange() const;

  /**
   * \brief Get the tower attack speed
   * 
   * \return int 
   */
  int getAttackSpeed() const;

  /**
   * \brief Get the tower type
   * 
   * \return int 
   */
  int getType() const;

  /**
   * \brief Get the tower level
   * 
   * \return int 
   */
  int getLevel() const;

  /**
   * \brief Get the geometric circle that represents the tower range
   * 
   * \return sf::CircleShape& 
   */
  sf::CircleShape& getRangeCircle();

  /**
   * \brief Set the tower's target
   * 
   * \param enemy 
   */
  void setTarget(std::shared_ptr<Enemy> enemy);

  /**
   * \brief Remove the tower's target
   * 
   */
  void removeTarget();

  /**
   * \brief Check if tower has selected a target
   * 
   * \return true 
   * \return false 
   */
  bool hasTarget();

  /**
   * \brief Returns the tower's current target
   * 
   * \return std::shared_ptr<Enemy> 
   */
  std::shared_ptr<Enemy> getTarget();

  /**
   * \brief Makes the tower fire a projectile at an enemy
   * This is a virtual function since every tower type has its own projectile type
   */
  virtual void fire() = 0;

  /**
   * \brief Get the tower projectiles as a vector
   * 
   * \return std::vector<std::shared_ptr<Projectile>>& 
   */
  virtual std::vector<std::shared_ptr<Projectile>>& getProjectiles() = 0;

  /**
   * \brief Set the time since last attack for tower
   * 
   * \param time 
   */
  void setLastFireTime(sf::Time time);

  /**
   * \brief Returns the time since last attack for tower
   * 
   * \return sf::Time 
   */
  sf::Time getLastFireTime() const;

  /**
   * \brief Get the tower level text (graphical element)
   * 
   * \return sf::Text&
   */
  sf::Text& getText();

 protected:
  int level_ = 1;
  int price_;
  float range_;
  int attack_speed_;
  bool has_target_ = false;
  std::shared_ptr<Enemy> target_;
  sf::CircleShape range_circle_;
  sf::Sprite sprite_;

 private:
  sf::Text text_;
  sf::Font font_;
  sf::Texture texture_;
  bool selected_;
  int type_;
  sf::Time last_fire_time_;
};

#endif  // __TOWER_H__

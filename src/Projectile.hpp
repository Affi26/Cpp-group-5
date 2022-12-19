#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Enemy.hpp"
/**
 * @brief Parent class for projectiles
 *
 */
class Projectile {
 public:
  /**
   * @brief Construct a new Projectile object
   *
   * @param texturePath Path to the projectile texture
   * @param type type of projectile
   * @param enemy target for the projectile
   * @param origin the starting point of the projectile
   */
  Projectile(std::string texturePath, int type, std::shared_ptr<Enemy> enemy,
             const sf::Vector2f origin);

  /**
   * @brief Destroy the Projectile object
   *
   */
  virtual ~Projectile();

  /**
   * @brief return the projectile sprite
   *
   * @return sf::Sprite&
   */
  sf::Sprite& getSprite();

  /**
   * @brief return the projectile hitbox
   *
   * @return sf::FloatRect&
   */
  sf::FloatRect& getHitbox();

  /**
   * @brief return the projectile target
   *
   * @return std::shared_ptr<Enemy>
   */
  std::shared_ptr<Enemy> getEnemy();

  /**
   * @brief Move the projectile
   *
   * @return true when intersecting with enemy
   * @return false otherwise
   */
  bool move();

  /**
   * @brief Return the damage of the projectile
   *
   * @return int
   */
  int getDamage() const;

 protected:
  int damage_;

 private:
  sf::Texture texture_;
  sf::Sprite sprite_;
  sf::FloatRect hitbox_;
  int type_;
  int speed_ = 8;
  std::shared_ptr<Enemy> enemy_;
};

#endif  // __PROJECTILE_H__
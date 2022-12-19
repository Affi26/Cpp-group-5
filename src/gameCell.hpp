#ifndef __GAMETILE_H__
#define __GAMETILE_H__

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @file gameCell.hpp
 * @author Axel Hedman, axel.hedman@aalto.fi
 * @brief Splitting the map into cells that are easier to handle
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */

class GameCell {
 public:
   /**
   * @brief Constructor for initializing a Map object
   * 
   * @param path Path to sprite asset
   * @param x The desired x coordinate of the sprite
   * @param y The desired y coordinate of the sprite
   * @param passable Boolean value that tells if the cell is passable
   * @param exit Boolean value to set the exit of the map
   * @param start Boolean parameter to set the start of the map
    */
  GameCell(std::string path, float x, float y, bool passable, bool exit, bool start);
  
  /**
   * @brief GameCell object destructor
   *  
   */
  ~GameCell() {}
  
  /**
   * @brief Constructor for initializing a Map object
   * 
   * @param path Path to sprite asset
   * @return true if successful, false otherwise
    */
  bool setUpSprite(std::string path);

  /**
   * @brief Returns a reference to the sprite variable
   * 
   * @return Reference to the sprite variable
    */
  sf::Sprite& getSprite();

  bool isExit_;
  bool isStart_;
  bool isPassable_;
  sf::Vector2f pos_;
  sf::Texture texture_;
  sf::Sprite sprite_;

};

#endif  // __GAMETILE_H__

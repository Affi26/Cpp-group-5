/**
 * @file Game.h
 * @author David Enberg david.enberg@aalto.fi
 * @brief Class that works as the game engine
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "Button.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "Node.hpp"
#include "Player.hpp"
#include "Tower.hpp"
#include "Wave.hpp"
#include "gameCell.hpp"

/*! Game class */
class Game {
 public:
  /**
   * @brief Default game constructor
   */
  Game(int* state);

  /**
   * @brief Default game destructor
   */
  virtual ~Game();

  /**
   * @brief Updates the game on the screen
   */
  void update();

  /**
   * @brief Renders all objects on the screen
   */
  void render();

  /**
   * @brief Tells whether the game is running
   *
   * @return true if game is running
   * @return false if game is not running
   */

  bool running();

  /**
   * @brief Function for checking if a circle and a rectangle intersects,
   *        from
   *        https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
   *
   * @param c the circle that should be checked
   * @param r the rectangle to check
   * @return true if the shapes intersect
   * @return false if the shapes do not intersect
   */

  bool intersects(sf::CircleShape& c, sf::FloatRect& r);


 private:
  
 
  void pollEv();

  /**
   * @brief Shows an error message
   * @param message Error message to be displayed
   */ 
  void showErrorMessage(const std::string& message);

  /**
   * @brief Check if enemies are within range
   * 
   * @return true if all enemies are dead
   * @return false if enemies are still alive
   */
  bool checkPositions();

  /**
   * @brief Check if any towers are clicked
   * 
   * @param mouse_location Mouse coordinates
   */
  void checkTowers(sf::Vector2i mouse_location);

  /**
   * @brief Check if any button is clicked
   * @param mouse_location Coordinates of mouse
   */ 
  void checkButtons(sf::Vector2i mouse_location);

  /**
   * @brief Show info window
   * @param mouse_location Coordinates of mouse
   */ 
  void showInfo(unsigned int wave_nr, unsigned int info_type);

   /**
   * @brief Move a tower
   * @param tower The tower to move
   * @param mouse_location Coordinates of mouse
   */
  void moveTower(std::shared_ptr<Tower>& tower, const sf::Vector2i& mouse_location);
  
  /**
   * @brief Checks if a tower can be placed at passed coordinate
   * 
   * @param mouse_location Coordinates of mouse
   * @return true if tower can be placed
   * @return false if tower can't be placed
   */
  bool validPlacement(sf::Vector2i mouse_location);
 

  int* state_;
  bool placing_new_tower;
  bool paused_;
  int wave_number_;

  std::unique_ptr<Player> player_;
  sf::RenderWindow* window_;
  sf::Event event_;
  std::vector<std::shared_ptr<Enemy>> enemies_;
  std::vector<std::shared_ptr<Tower>> towers_;
  std::vector<std::shared_ptr<Node>> nodes_;
  Map map_ = Map("assets/map.txt");

  std::vector<std::shared_ptr<GameCell>> tiles_;
  std::vector<std::shared_ptr<Button>> buttons_;
  sf::RectangleShape button_background_;
  sf::Clock clock;
};

#endif
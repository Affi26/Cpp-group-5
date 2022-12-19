#ifndef __PATHFINDING_H__
#define __PATHFINDING_H__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include "gameCell.hpp"
#include "Node.hpp"
#include <memory>


/**
 * @brief Check if coordinate is inside map
 * 
 * @param x 
 * @param y 
 * @return true if coordinate is inside file
 * @return false if coordinate is not inside file
 */
bool isValid(int x, int y);

/**
 * @brief Search for the path
 * 
 * @param grid Map grid
 * @param nodes Vector to where path will be added
 * @param start Coordinate of start
 */
void pathSearch(const std::vector<std::vector<std::shared_ptr<GameCell>>>& grid,
                std::vector<std::shared_ptr<Node>>& nodes,
                const sf::Vector2f& start);

#endif 
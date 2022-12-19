#ifndef __MAP_H__
#define __MAP_H__

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "gameCell.hpp"
#include "Node.hpp"

/**
 * @file Map.hpp
 * @author Axel Hedman, axel.hedman@aalto.fi
 * @brief Map Class Implementation
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

class Map {
public:
  /**
   * @brief Constructor for initializing a Map object
   * 
   * @param filename Path to file where the map is read from
    */
  Map(std::string path);

  /**
   * @brief Map object destructor
   *  
   */
  ~Map() {}

  /**
   * @brief Sets up a matrix of tiles that are used to render the map. 
   * Takes no parameters and return nothing
   */
  void setUpCells();
    
  /**
   * @brief Returns a vector of shared pointers to Node objects
   * Takes no parameters.
   * @return Vector of shared pointers to Node objects
   */
  std::vector<std::shared_ptr<Node>> getNodes() const;
    
  /**
   * @brief Returns a matrix of shared pointers to GameCell objects 
   * Takes no parameters
   * @return Matrix of shared pointers to GameCell objects
   */
  std::vector<std::vector<std::shared_ptr<GameCell>>> getTiles() const;

private:
  std::vector<std::vector<std::shared_ptr<GameCell>>> tile_matrix_;
  std::string file_path_;
  std::vector<std::shared_ptr<Node>> nodes_;
};

#endif // __MAP_H__

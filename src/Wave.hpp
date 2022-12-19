#ifndef __WAVE_H__
#define __WAVE_H__

/**
 * @file Wave.hpp
 * @author David Enberg (david.enberg@aalto.fi)
 * @brief
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <memory>
#include <vector>

#include "Enemy.hpp"
#include "Node.hpp"

/**
 * @brief Class that generates individual waves
 *
 */
class Wave {
 public:
  /**
   * @brief Construct a new Wave object
   *
   * @param waveNum wavenumber that affects wave creation
   * @param start starting point for enemies
   */
  Wave(int waveNum, const std::shared_ptr<Node>& start);

  /**
   * @brief Get the vector of Enemies
   *
   * @return std::vector<std::shared_ptr<Enemy>>&
   */
  std::vector<std::shared_ptr<Enemy>>& getEnemies();

 private:
  std::vector<std::shared_ptr<Enemy>> enemies_;
};

#endif  // __WAVE_H__
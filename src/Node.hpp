#ifndef __NODE_H__
#define __NODE_H__

#include <SFML/Graphics.hpp>
#include <memory>

class Node {
 public:
  Node(std::shared_ptr<Node> ptr = NULL, float x = 0, float y = 0);
  sf::Vector2f& get_cord();
  std::shared_ptr<Node> get_next();

  /**
   * @brief Set the cord object
   * 
   * @param v coordinate
   */
  void set_cord(sf::Vector2f& v);

  /**
   * @brief Set the next object
   * 
   * @param n next object
   */
  void set_next(std::shared_ptr<Node> n);

 private:
  std::shared_ptr<Node> next_;
  sf::Vector2f coordinate_;
};

#endif  // __NODE_H__
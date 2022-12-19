
#include "Node.hpp"

Node::Node(std::shared_ptr<Node> n, float x, float y)
    : next_(n), coordinate_(sf::Vector2f(x, y)) {}

sf::Vector2f& Node::get_cord() { return coordinate_; }

std::shared_ptr<Node> Node::get_next() { return next_; }

void Node::set_cord(sf::Vector2f& v) { coordinate_ = v; }

void Node::set_next(std::shared_ptr<Node> n) { next_ = n; }

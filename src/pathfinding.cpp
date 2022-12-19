#include "pathfinding.hpp"

bool isValid(int x, int y)
{
    // Returns true if row number and column number
    // is in range
    return (x >= 0) && (x <= 800 ) &&
           (y >= 0) && (y <= 600);
}



void pathSearch(const std::vector<std::vector<std::shared_ptr<GameCell>>>& grid, 
                std::vector<std::shared_ptr<Node>>& nodes, const sf::Vector2f& start){
  bool at_end = false;
  int x;
  int y;
  std::vector<sf::Vector2f> blocked;
  nodes.push_back(std::make_shared<Node>(nullptr, start.x, start.y));
  while(!at_end){

    x = nodes.back()->get_cord().x;
    y = nodes.back()->get_cord().y;
    
    // check north
    sf::Vector2f next_node(x, y-100);
    if (isValid(next_node.x, next_node.y)) {
      if (grid[next_node.y/100][next_node.x/100]->isExit_) {  // if next node is exit
        auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
        nodes.back()->set_next(new_node);
        nodes.push_back(new_node);
        at_end = true;
        break;
      } 
      // if next node is not on blocked or nodes
      else if (std::find(blocked.begin(), blocked.end(), next_node) ==
                     blocked.end() && std::find_if(nodes.begin(), nodes.end(), [&](const std::shared_ptr<Node>& n) {
                                return (next_node.x == n->get_cord().x &&
                                        next_node.y == n->get_cord().y);
                              }) == nodes.end()) {
        if(grid[next_node.y/100][next_node.x/100]->isPassable_){
            auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
            nodes.back()->set_next(new_node);
            nodes.push_back(new_node);
        }
        else{
          blocked.push_back(next_node);
        }
      }
    }

    // south
    next_node.y = y + 100;
    if (isValid(next_node.x, next_node.y)) {
      if (grid[next_node.y/100][next_node.x/100]->isExit_) {
        auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
        nodes.back()->set_next(new_node);
        nodes.push_back(new_node);
        at_end = true;
        break;
      } else if (std::find(blocked.begin(), blocked.end(), next_node) ==
                 blocked.end()&& std::find_if(nodes.begin(), nodes.end(), [&](const std::shared_ptr<Node>& n) {
                                return (next_node.x == n->get_cord().x &&
                                        next_node.y == n->get_cord().y);
                              }) == nodes.end()) 
                              {
        if(grid[next_node.y/100][next_node.x/100]->isPassable_){
            auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
            nodes.back()->set_next(new_node);
            nodes.push_back(new_node);
        }
        else{
          blocked.push_back(next_node);
        }
      }
    }

    // east
    next_node.y = y;
    next_node.x = x + 100;
    if (isValid(next_node.x, next_node.y)) {
      if (grid[next_node.y/100][next_node.x/100]->isExit_) {
        auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
        nodes.back()->set_next(new_node);
        nodes.push_back(new_node);
        at_end = true;
        break;
      } else if (std::find(blocked.begin(), blocked.end(), next_node) ==
                 blocked.end() && std::find_if(nodes.begin(), nodes.end(), [&](const std::shared_ptr<Node>& n) {
                                return (next_node.x == n->get_cord().x &&
                                        next_node.y == n->get_cord().y);
                              }) == nodes.end()) {
        if(grid[next_node.y/100][next_node.x/100]->isPassable_){
            auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
            nodes.back()->set_next(new_node);
            nodes.push_back(new_node);
        }
        else{
          blocked.push_back(next_node);
        }
      }
    }

    // west
    next_node.x = x - 100;
    if (isValid(next_node.x, next_node.y)) {
      if (grid[next_node.y/100][next_node.x/100]->isExit_) {
        auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
        nodes.back()->set_next(new_node);
        nodes.push_back(new_node);
        at_end = true;
        break;
      } else if (std::find(blocked.begin(), blocked.end(), next_node) ==
                 blocked.end() && std::find_if(nodes.begin(), nodes.end(), [&](const std::shared_ptr<Node>& n) {
                                return (next_node.x == n->get_cord().x &&
                                        next_node.y == n->get_cord().y);
                              }) == nodes.end()) {
        if(grid[next_node.y/100][next_node.x/100]->isPassable_){
            auto new_node = std::make_shared<Node>(nullptr, next_node.x, next_node.y);
            nodes.back()->set_next(new_node);
            nodes.push_back(new_node);
        }
        else{
          blocked.push_back(next_node);
        }
      }
    }
  }
}
                

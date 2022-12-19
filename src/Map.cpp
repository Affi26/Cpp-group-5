#include "Map.hpp"

#include <fstream>
#include <vector>

#include "Node.hpp"
#include "gameCell.hpp"
#include "pathfinding.hpp"

Map::Map(std::string path) : file_path_(path) { setUpCells(); }

std::vector<std::vector<std::shared_ptr<GameCell>>> Map::getTiles() const {
  return tile_matrix_;
}

std::vector<std::shared_ptr<Node>> Map::getNodes() const { return nodes_; }

void Map::setUpCells() {
  std::ifstream file(file_path_);
  std::string line;
  float x = 50;
  float y = 50;
  std::vector<std::shared_ptr<GameCell>> row;
  sf::Vector2f start;

  if (file.is_open()) {
    // while loop that reads the map file and converts it to a vector of GameCell objects
    while (getline(file, line)) {
      for (auto &ch : line) {
        if (ch == '!') {
          row.push_back(std::make_shared<GameCell>("assets/road.png", x, y,
                                                   true, false, true));
          start.x = x;
          start.y = y;
        } else if (ch == '#') {
          row.push_back(std::make_shared<GameCell>("assets/grass.png", x, y,
                                                   false, false, false));
        } else if (ch == '?') {
          row.push_back(std::make_shared<GameCell>("assets/road.png", x, y,
                                                   true, true, false));
        } else if (ch == '=') {
          row.push_back(std::make_shared<GameCell>("assets/road.png", x, y,
                                                   true, false, false));
        }
        x += 100;
      }
      tile_matrix_.push_back(row);
      row.clear();
      y += 100;
      x = 50;
    }
    file.close();
  }
  pathSearch(tile_matrix_, nodes_, start);

  // Making sure the enemy spawns outside the map -> enters the map -> exits the map (Adding a node before the "start tile" and after the "end tile")
  float x_diff = nodes_[0]->get_cord().x - nodes_[1]->get_cord().x;
  float y_diff = nodes_[0]->get_cord().y - nodes_[1]->get_cord().y;
  if (x_diff != 0) {
    nodes_.insert(
        nodes_.begin(),
        std::make_shared<Node>(nodes_[0], nodes_[0]->get_cord().x + x_diff, nodes_[0]->get_cord().y));
  } else if (y_diff != 0) {
    nodes_.insert(
        nodes_.begin(),
        std::make_shared<Node>(nodes_[0], nodes_[0]->get_cord().x, nodes_[0]->get_cord().y + y_diff));
  }
  x_diff = nodes_.end()[-1]->get_cord().x - nodes_.end()[-2]->get_cord().x;
  y_diff = nodes_.end()[-1]->get_cord().y - nodes_.end()[-2]->get_cord().y;
  if (x_diff != 0) {
    nodes_.push_back(
        std::make_shared<Node>(nullptr, nodes_.end()[-1]->get_cord().x + x_diff, nodes_.end()[-1]->get_cord().y));
  } else if (y_diff != 0) {
    nodes_.push_back(
        std::make_shared<Node>(nullptr, nodes_.end()[-1]->get_cord().x, nodes_.end()[-1]->get_cord().y + y_diff));
  }
  nodes_.end()[-2]->set_next(nodes_.end()[-1]);
}

#include "Wave.hpp"

#include "Basic_enemy.hpp"
#include "Stealth_enemy.hpp"
#include "Boss_enemy.hpp"

Wave::Wave(int waveNum, const std::shared_ptr<Node>& start) {
  enemies_.clear();
  int enemy_amount = waveNum * 2;

  std::vector<std::shared_ptr<Node>> enemy_starting_points;
  // int stealthEnemies = waveNum / 2;
  // int bossEnemies = waveNum / 5;

  // Lining up enemies in a row outside the map
  for (int i = 0; i < enemy_amount; i++) {
    enemy_starting_points.push_back(std::make_shared<Node>(*start));
    if (enemy_starting_points[i]->get_cord().x < 0) {
      enemy_starting_points[i]->get_cord().x -= 100 * i;
    } else if (enemy_starting_points[i]->get_cord().x > 800) {
      enemy_starting_points[i]->get_cord().x += 100 * i;
    } else if (enemy_starting_points[i]->get_cord().y < 0) {
      enemy_starting_points[i]->get_cord().y -= 100 * i;
    } else if (enemy_starting_points[i]->get_cord().y > 600) {
      enemy_starting_points[i]->get_cord().y += 100 * i;
    }
    
    // add stealth enemies every round after the 1st
    if (waveNum != 1 && i % 3 == 0) {
      std::shared_ptr<StealthEnemy> new_stealth_enemy = std::make_shared<StealthEnemy>(enemy_starting_points[i]);
      // add 1 to hp for every wave
      if(waveNum > 2){
        new_stealth_enemy->setHitpoints(waveNum - 1);
      }
      enemies_.push_back(new_stealth_enemy);
    }
    // add boss enemy every round after the 3rd
    else if (waveNum >= 4 && i == waveNum) {
      std::shared_ptr<BossEnemy> new_boss_enemy = std::make_shared<BossEnemy>(enemy_starting_points[i]);
      // add 5 to hp for last wave
      if(waveNum == 5){
        new_boss_enemy->setHitpoints(new_boss_enemy->getHitpoints() + 5);
      }
      enemies_.push_back(new_boss_enemy);
    }
    // add basic enemies every round
    else {
      std::shared_ptr<BasicEnemy> new_basic_enemy = std::make_shared<BasicEnemy>(enemy_starting_points[i]);
      // add 1 to hp for every wave
      if(waveNum != 1){
        new_basic_enemy->setHitpoints(waveNum);
      }
      enemies_.push_back(new_basic_enemy);
    }
    
  }
}

std::vector<std::shared_ptr<Enemy>>& Wave::getEnemies() { return enemies_; }
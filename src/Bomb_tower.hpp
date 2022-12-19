#ifndef __BOMB_TOWER_H__
#define __BOMB_TOWER_H__

#include "Tower.hpp"

/**
 * @brief Bomb tower class
 * 
 */
class BombTower : public Tower {
 public:
    /**
     * @brief Construct a new Bomb Tower object
     * 
     */
    BombTower();
    
    /**
     * @brief Destroy the Bomb Tower object
     * 
     */

    ~BombTower();
    
    /**
     * @brief Fire at enemy
     * git 
     */
    void fire();

    /**
     * @brief Get the Projectiles object
     * 
     * @return std::vector<std::shared_ptr<Projectile>>& 
     */
    std::vector<std::shared_ptr<Projectile>>& getProjectiles();

private:
    std::vector<std::shared_ptr<Projectile>> projectiles_;
};

#endif // __BOMB_TOWER_H__
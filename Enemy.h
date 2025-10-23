#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>

class Character; // Forward declaration

class Enemy {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;
    int xpReward;

public:
    // Constructor
    Enemy(std::string enemyName, int hp, int atk, int xp);
    
    // Virtual destructor
    virtual ~Enemy();
    
    // Core methods (virtual for polymorphism)
    virtual void attack(Character* target);
    virtual void takeDamage(int damage);
    
    // Display methods
    void displayHealthBar() const;
    virtual void displayInfo() const;
    
    // Getters
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttackPower() const;
    int getXPReward() const;
    bool isDead() const;
    
    // Setters
    void setHealth(int hp);
};

#endif
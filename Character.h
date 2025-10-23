#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int level;
    int xp;
    int attackPower;
    int xpToNextLevel;

public:
    // Constructor
    Character(std::string charName, int hp, int atk);
    
    // Virtual destructor for proper cleanup
    virtual ~Character();
    
    // Core methods
    virtual void attack(Character* target);
    virtual void takeDamage(int damage);
    void gainXP(int amount);
    void levelUp();
    
    // Display methods
    virtual void displayStats() const;
    void displayHealthBar() const;
    
    // Getters
    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getLevel() const;
    int getXP() const;
    int getAttackPower() const;
    bool isAlive() const;
    
    // Setters
    void setHealth(int hp);
    void setLevel(int lvl);
    void setXP(int experience);
};

#endif
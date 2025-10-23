#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
private:
    int armorPoints;
    bool shieldBlockActive;
    int shieldBlockCooldown;

public:
    // Constructor
    Warrior(std::string name);
    
    // Destructor
    ~Warrior();
    
    // Override attack method
    void attack(Character* target) override;
    
    // Override takeDamage with armor calculation
    void takeDamage(int damage) override;
    
    // Special skill - Shield Block
    void useShieldBlock();
    
    // Display stats override
    void displayStats() const override;
    
    // Getters
    int getArmorPoints() const;
    bool isShieldBlockActive() const;
    int getShieldBlockCooldown() const;
    
    // Cooldown management
    void reduceCooldown();
};

#endif
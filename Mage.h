#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage : public Character {
private:
    int mana;
    int maxMana;
    int manaRegen;

public:
    // Constructor
    Mage(std::string name);
    
    // Destructor
    ~Mage();
    
    // Override attack method - Magic attack
    void attack(Character* target) override;
    
    // Special skill - Fireball (costs mana, high damage)
    void castFireball(Character* target);
    
    // Mana management
    void regenerateMana();
    bool hasMana(int cost) const;
    
    // Display stats override
    void displayStats() const override;
    
    // Getters
    int getMana() const;
    int getMaxMana() const;
};

#endif
#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"

class Archer : public Character {
private:
    int arrows;
    int criticalChance; // Percentage chance for critical hit

public:
    // Constructor
    Archer(std::string name);
    
    // Destructor
    ~Archer();
    
    // Override attack method - Ranged attack
    void attack(Character* target) override;
    
    // Special skill - Multi-shot (attacks 3 times)
    void useMultiShot(Character* target);
    
    // Arrow management
    void collectArrows(int amount);
    bool hasArrows() const;
    
    // Critical hit calculation
    bool rollCritical() const;
    
    // Display stats override
    void displayStats() const override;
    
    // Getters
    int getArrows() const;
    int getCriticalChance() const;
};

#endif
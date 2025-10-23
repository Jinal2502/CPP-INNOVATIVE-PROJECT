#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"

class Goblin : public Enemy {
private:
    bool canDodge;

public:
    // Constructor
    Goblin();
    
    // Destructor
    ~Goblin();
    
    // Override attack - Quick, weak attacks
    void attack(Character* target) override;
    
    // Override display info
    void displayInfo() const override;
    
    // Special ability - chance to dodge
    bool attemptDodge();
};

#endif
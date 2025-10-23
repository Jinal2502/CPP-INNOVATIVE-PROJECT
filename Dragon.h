#ifndef DRAGON_H
#define DRAGON_H

#include "Enemy.h"

class Dragon : public Enemy {
private:
    int fireBreathCooldown;
    bool canUseFlight;

public:
    // Constructor
    Dragon();
    
    // Destructor
    ~Destructor();
    
    // Override attack - Alternates between melee and fire breath
    void attack(Character* target) override;
    
    // Special attack - Fire Breath (massive damage)
    void useFireBreath(Character* target);
    
    // Override display info
    void displayInfo() const override;
    
    // Cooldown management
    void reduceCooldown();
    bool canUseFireBreath() const;
};

#endif
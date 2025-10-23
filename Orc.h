#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy {
private:
    int rage;
    bool isEnraged;

public:
    // Constructor
    Orc();
    
    // Destructor
    ~Orc();
    
    // Override attack - Heavy physical attacks
    void attack(Character* target) override;
    
    // Override takeDamage - builds rage when hit
    void takeDamage(int damage) override;
    
    // Override display info
    void displayInfo() const override;
    
    // Rage mechanic
    void buildRage();
    void checkEnrage();
};

#endif
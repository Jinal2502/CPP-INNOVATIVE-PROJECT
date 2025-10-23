#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
private:
    int attackBonus;

public:
    // Constructor
    Weapon(std::string name, std::string desc, int bonus);
    
    // Destructor
    ~Weapon();
    
    // Override use method
    void use(Character* target) override;
    
    // Override display info
    void displayInfo() const override;
    
    // Getter
    int getAttackBonus() const;
};

#endif
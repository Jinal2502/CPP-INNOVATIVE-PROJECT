#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item {
private:
    int healAmount;

public:
    // Constructor
    Potion(std::string name, std::string desc, int heal);
    
    // Destructor
    ~Potion();
    
    // Override use method - Heals the character
    void use(Character* target) override;
    
    // Override display info
    void displayInfo() const override;
    
    // Getter
    int getHealAmount() const;
};

#endif
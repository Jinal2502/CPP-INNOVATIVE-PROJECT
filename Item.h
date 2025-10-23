#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Character; // Forward declaration

class Item {
protected:
    std::string name;
    std::string description;
    std::string type; // "Weapon", "Armor", "Potion"

public:
    // Constructor
    Item(std::string itemName, std::string desc, std::string itemType);
    
    // Virtual destructor
    virtual ~Item();
    
    // Pure virtual method - must be implemented by derived classes
    virtual void use(Character* target) = 0;
    
    // Display methods
    virtual void displayInfo() const;
    
    // Getters
    std::string getName() const;
    std::string getDescription() const;
    std::string getType() const;
};

#endif
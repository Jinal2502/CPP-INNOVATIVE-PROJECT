#include "Item.h"

// Constructor
Item::Item(std::string itemName, std::string desc, std::string itemType)
    : name(itemName), description(desc), type(itemType) {}

// Virtual destructor
Item::~Item() {}

// Display item info
void Item::displayInfo() const {
    std::cout << "\n[" << type << "] " << name << "\n";
    std::cout << "Description: " << description << "\n";
}

// Getters
std::string Item::getName() const { return name; }
std::string Item::getDescription() const { return description; }
std::string Item::getType() const { return type; }
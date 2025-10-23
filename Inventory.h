#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include <vector>
#include <memory>

class Inventory {
private:
    std::vector<Item*> items;
    int maxCapacity;

public:
    // Constructor
    Inventory(int capacity = 20);
    
    // Destructor
    ~Inventory();
    
    // Item management
    bool addItem(Item* item);
    bool removeItem(int index);
    Item* getItem(int index);
    
    // Display methods
    void displayInventory() const;
    void displayItemDetails(int index) const;
    
    // Inventory queries
    int getItemCount() const;
    int getMaxCapacity() const;
    bool isFull() const;
    bool isEmpty() const;
    
    // Use item
    bool useItem(int index, Character* target);
    
    // Find specific items
    int findPotion() const;
    int countPotions() const;
};

#endif
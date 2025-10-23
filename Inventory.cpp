#include "Inventory.h"
#include "Character.h"

// Constructor
Inventory::Inventory(int capacity) : maxCapacity(capacity) {}

// Destructor - Clean up all items
Inventory::~Inventory() {
    for (Item* item : items) {
        delete item;
    }
    items.clear();
}

// Add item to inventory
bool Inventory::addItem(Item* item) {
    if (isFull()) {
        std::cout << "Inventory is full! Cannot add " << item->getName() << "\n";
        return false;
    }
    
    items.push_back(item);
    std::cout << "Added " << item->getName() << " to inventory!\n";
    return true;
}

// Remove item from inventory
bool Inventory::removeItem(int index) {
    if (index < 0 || index >= items.size()) {
        std::cout << "Invalid item index!\n";
        return false;
    }
    
    std::cout << "Removed " << items[index]->getName() << " from inventory.\n";
    delete items[index];
    items.erase(items.begin() + index);
    return true;
}

// Get item at index
Item* Inventory::getItem(int index) {
    if (index < 0 || index >= items.size()) {
        return nullptr;
    }
    return items[index];
}

// Display all items in inventory
void Inventory::displayInventory() const {
    std::cout << "\n========== INVENTORY ==========\n";
    std::cout << "Items: " << items.size() << "/" << maxCapacity << "\n";
    std::cout << "================================\n";
    
    if (isEmpty()) {
        std::cout << "Inventory is empty.\n";
    } else {
        for (size_t i = 0; i < items.size(); i++) {
            std::cout << (i + 1) << ". " << items[i]->getName() 
                      << " [" << items[i]->getType() << "]\n";
        }
    }
    std::cout << "================================\n";
}

// Display details of specific item
void Inventory::displayItemDetails(int index) const {
    if (index < 0 || index >= items.size()) {
        std::cout << "Invalid item index!\n";
        return;
    }
    
    items[index]->displayInfo();
}

// Get item count
int Inventory::getItemCount() const {
    return items.size();
}

// Get max capacity
int Inventory::getMaxCapacity() const {
    return maxCapacity;
}

// Check if inventory is full
bool Inventory::isFull() const {
    return items.size() >= maxCapacity;
}

// Check if inventory is empty
bool Inventory::isEmpty() const {
    return items.empty();
}

// Use item on target
bool Inventory::useItem(int index, Character* target) {
    if (index < 0 || index >= items.size()) {
        std::cout << "Invalid item index!\n";
        return false;
    }
    
    Item* item = items[index];
    item->use(target);
    
    // Remove consumable items (potions) after use
    if (item->getType() == "Potion") {
        removeItem(index);
    }
    
    return true;
}

// Find first potion in inventory
int Inventory::findPotion() const {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i]->getType() == "Potion") {
            return i;
        }
    }
    return -1; // No potion found
}

// Count potions in inventory
int Inventory::countPotions() const {
    int count = 0;
    for (Item* item : items) {
        if (item->getType() == "Potion") {
            count++;
        }
    }
    return count;
}
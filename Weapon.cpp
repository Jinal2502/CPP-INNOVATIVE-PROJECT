#include "Weapon.h"
#include "Character.h"

// Constructor
Weapon::Weapon(std::string name, std::string desc, int bonus)
    : Item(name, desc, "Weapon"), attackBonus(bonus) {}

// Destructor
Weapon::~Weapon() {}

// Override use method - Equip weapon (increases attack power)
void Weapon::use(Character* target) {
    if (target != nullptr) {
        std::cout << "\n⚔️ " << target->getName() << " equips " << name << "!\n";
        std::cout << "Attack Power increased by " << attackBonus << "!\n";
        // Note: In a full implementation, we would modify the character's attack power
        // For now, this demonstrates the concept
    }
}

// Override display info
void Weapon::displayInfo() const {
    std::cout << "\n[WEAPON] ⚔️ " << name << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Attack Bonus: +" << attackBonus << "\n";
}

// Getter
int Weapon::getAttackBonus() const {
    return attackBonus;
}
#include "Mage.h"
#include "Enemy.h"

// Constructor - Mage has lower health but high attack and mana
Mage::Mage(std::string name) 
    : Character(name, 80, 22), mana(50), maxMana(50), manaRegen(10) {
    std::cout << "\n" << name << " the Mage has been created!\n";
    std::cout << "Class Bonus: +7 ATK, 50 Mana Points\n";
    std::cout << "Special Skill: Fireball (costs 20 mana, deals massive damage)\n";
}

// Destructor
Mage::~Mage() {}

// Override attack - Magic damage
void Mage::attack(Character* target) {
    if (target != nullptr) {
        std::cout << name << " casts MAGIC MISSILE at " << target->getName() 
                  << " for " << attackPower << " magical damage!\n";
        target->takeDamage(attackPower);
        
        // Regenerate some mana after basic attack
        regenerateMana();
    }
}

// Special skill - Fireball
void Mage::castFireball(Enemy* target) {
    const int manaCost = 20;
    
    if (!hasMana(manaCost)) {
        std::cout << "Not enough mana! Need " << manaCost << " mana. Current: " << mana << "\n";
        return;
    }
    
    if (target != nullptr) {
        mana -= manaCost;
        int fireballDamage = attackPower * 2; // Double damage!
        
        std::cout << "\n🔥 " << name << " casts FIREBALL! 🔥\n";
        std::cout << "A massive ball of fire engulfs " << target->getName() 
                  << " for " << fireballDamage << " damage!\n";
        target->takeDamage(fireballDamage);
        std::cout << "Mana: " << mana << "/" << maxMana << "\n";
    }
}

// Regenerate mana
void Mage::regenerateMana() {
    mana += manaRegen;
    if (mana > maxMana) {
        mana = maxMana;
    }
}

// Check if has enough mana
bool Mage::hasMana(int cost) const {
    return mana >= cost;
}

// Display stats override
void Mage::displayStats() const {
    std::cout << "\n========== CHARACTER STATS ==========\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Class: MAGE\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Mana: " << mana << "/" << maxMana << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "XP: " << xp << "/" << xpToNextLevel << "\n";
    std::cout << "====================================\n\n";
}

// Getters
int Mage::getMana() const { return mana; }
int Mage::getMaxMana() const { return maxMana; }
#include "Warrior.h"

// Constructor - Warrior has high health and armor
Warrior::Warrior(std::string name) 
    : Character(name, 120, 18), armorPoints(10), shieldBlockActive(false), shieldBlockCooldown(0) {
    std::cout << "\n" << name << " the Warrior has been created!\n";
    std::cout << "Class Bonus: +20 HP, +3 ATK, 10 Armor Points\n";
    std::cout << "Special Skill: Shield Block (reduces damage by 50% for 1 turn)\n";
}

// Destructor
Warrior::~Warrior() {}

// Override attack - Heavy physical damage
void Warrior::attack(Character* target) {
    if (target != nullptr) {
        int damage = attackPower + 5; // Warriors deal bonus damage
        std::cout << name << " performs a HEAVY STRIKE on " << target->getName() 
                  << " for " << damage << " damage!\n";
        target->takeDamage(damage);
    }
}

// Override takeDamage - Armor reduces incoming damage
void Warrior::takeDamage(int damage) {
    int reducedDamage = damage;
    
    // Apply armor reduction
    reducedDamage -= armorPoints;
    if (reducedDamage < 0) reducedDamage = 0;
    
    // Apply shield block if active
    if (shieldBlockActive) {
        reducedDamage = reducedDamage / 2;
        std::cout << "⚔️ SHIELD BLOCK ACTIVE! Damage reduced by 50%!\n";
        shieldBlockActive = false; // Shield block lasts only 1 turn
    }
    
    health -= reducedDamage;
    if (health < 0) health = 0;
    
    std::cout << name << " takes " << reducedDamage << " damage";
    if (armorPoints > 0) {
        std::cout << " (reduced by " << armorPoints << " armor)";
    }
    std::cout << "! Health: " << health << "/" << maxHealth << "\n";
}

// Special skill - Shield Block
void Warrior::useShieldBlock() {
    if (shieldBlockCooldown > 0) {
        std::cout << "Shield Block is on cooldown! (" << shieldBlockCooldown << " turns remaining)\n";
        return;
    }
    
    shieldBlockActive = true;
    shieldBlockCooldown = 3; // 3 turn cooldown
    std::cout << "\n🛡️ " << name << " raises their shield!\n";
    std::cout << "Next incoming attack will be reduced by 50%!\n";
}

// Display stats override
void Warrior::displayStats() const {
    std::cout << "\n========== CHARACTER STATS ==========\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Class: WARRIOR\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "Armor Points: " << armorPoints << "\n";
    std::cout << "XP: " << xp << "/" << xpToNextLevel << "\n";
    std::cout << "Shield Block Cooldown: " << shieldBlockCooldown << " turns\n";
    std::cout << "====================================\n\n";
}

// Getters
int Warrior::getArmorPoints() const { return armorPoints; }
bool Warrior::isShieldBlockActive() const { return shieldBlockActive; }
int Warrior::getShieldBlockCooldown() const { return shieldBlockCooldown; }

// Reduce cooldown
void Warrior::reduceCooldown() {
    if (shieldBlockCooldown > 0) {
        shieldBlockCooldown--;
    }
}
#include "Character.h"
#include <algorithm>

// Constructor
Character::Character(std::string charName, int hp, int atk)
    : name(charName), health(hp), maxHealth(hp), level(1), xp(0), attackPower(atk), xpToNextLevel(100) {}

// Virtual destructor
Character::~Character() {}

// Attack method (can be overridden by derived classes)
void Character::attack(Character* target) {
    if (target != nullptr) {
        std::cout << name << " attacks " << target->getName() << " for " << attackPower << " damage!\n";
        target->takeDamage(attackPower);
    }
}

// Take damage method
void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    std::cout << name << " takes " << damage << " damage! ";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
}

// Gain experience points
void Character::gainXP(int amount) {
    xp += amount;
    std::cout << name << " gained " << amount << " XP!\n";
    
    // Check if level up
    while (xp >= xpToNextLevel) {
        levelUp();
    }
}

// Level up method
void Character::levelUp() {
    level++;
    xp -= xpToNextLevel;
    xpToNextLevel = level * 100; // Scaling XP requirement
    
    // Increase stats
    maxHealth += 20;
    health = maxHealth; // Restore health on level up
    attackPower += 5;
    
    std::cout << "\n*** LEVEL UP! ***\n";
    std::cout << name << " is now level " << level << "!\n";
    std::cout << "Health increased to " << maxHealth << "\n";
    std::cout << "Attack Power increased to " << attackPower << "\n";
    std::cout << "Health fully restored!\n\n";
}

// Display character stats
void Character::displayStats() const {
    std::cout << "\n========== CHARACTER STATS ==========\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "XP: " << xp << "/" << xpToNextLevel << "\n";
    std::cout << "====================================\n\n";
}

// Display health bar
void Character::displayHealthBar() const {
    int barLength = 20;
    int filledLength = (health * barLength) / maxHealth;
    
    std::cout << name << " [";
    for (int i = 0; i < barLength; i++) {
        if (i < filledLength) {
            std::cout << "█";
        } else {
            std::cout << "░";
        }
    }
    std::cout << "] " << health << "/" << maxHealth << "\n";
}

// Getters
std::string Character::getName() const { return name; }
int Character::getHealth() const { return health; }
int Character::getMaxHealth() const { return maxHealth; }
int Character::getLevel() const { return level; }
int Character::getXP() const { return xp; }
int Character::getAttackPower() const { return attackPower; }
bool Character::isAlive() const { return health > 0; }

// Setters
void Character::setHealth(int hp) { 
    health = hp;
    if (health > maxHealth) health = maxHealth;
    if (health < 0) health = 0;
}

void Character::setLevel(int lvl) { 
    level = lvl;
    xpToNextLevel = level * 100;
}

void Character::setXP(int experience) { xp = experience; }
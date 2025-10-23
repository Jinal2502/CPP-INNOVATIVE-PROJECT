#include "Archer.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

// Constructor - Archer has balanced stats with arrows and crit chance
Archer::Archer(std::string name) 
    : Character(name, 100, 20), arrows(30), criticalChance(25) {
    std::cout << "\n" << name << " the Archer has been created!\n";
    std::cout << "Class Bonus: +5 ATK, 30 Arrows, 25% Critical Hit Chance\n";
    std::cout << "Special Skill: Multi-Shot (fires 3 arrows in quick succession)\n";
}

// Destructor
Archer::~Archer() {}

// Override attack - Ranged attack with critical chance
void Archer::attack(Character* target) {
    if (target != nullptr) {
        if (!hasArrows()) {
            std::cout << name << " is out of arrows! Using melee attack...\n";
            int meleeDamage = attackPower / 2;
            std::cout << name << " strikes " << target->getName() 
                      << " with their bow for " << meleeDamage << " damage!\n";
            target->takeDamage(meleeDamage);
            return;
        }
        
        arrows--;
        int damage = attackPower;
        
        // Check for critical hit
        if (rollCritical()) {
            damage = damage * 2;
            std::cout << "💥 CRITICAL HIT! 💥\n";
        }
        
        std::cout << name << " shoots an arrow at " << target->getName() 
                  << " for " << damage << " damage!\n";
        std::cout << "Arrows remaining: " << arrows << "\n";
        target->takeDamage(damage);
    }
}

// Special skill - Multi-shot
void Archer::useMultiShot(Enemy* target) {
    if (arrows < 3) {
        std::cout << "Not enough arrows for Multi-Shot! Need 3 arrows. Current: " << arrows << "\n";
        return;
    }
    
    if (target != nullptr) {
        std::cout << "\n🏹 " << name << " uses MULTI-SHOT! 🏹\n";
        
        int totalDamage = 0;
        for (int i = 0; i < 3; i++) {
            arrows--;
            int damage = attackPower - 3; // Slightly reduced damage per arrow
            
            if (rollCritical()) {
                damage = damage * 2;
                std::cout << "Arrow " << (i+1) << ": 💥 CRITICAL! " << damage << " damage!\n";
            } else {
                std::cout << "Arrow " << (i+1) << ": " << damage << " damage\n";
            }
            
            totalDamage += damage;
        }
        
        std::cout << "Total damage: " << totalDamage << "!\n";
        std::cout << "Arrows remaining: " << arrows << "\n";
        target->takeDamage(totalDamage);
    }
}

// Collect arrows
void Archer::collectArrows(int amount) {
    arrows += amount;
    std::cout << "Collected " << amount << " arrows! Total: " << arrows << "\n";
}

// Check if has arrows
bool Archer::hasArrows() const {
    return arrows > 0;
}

// Roll for critical hit
bool Archer::rollCritical() const {
    int roll = rand() % 100;
    return roll < criticalChance;
}

// Display stats override
void Archer::displayStats() const {
    std::cout << "\n========== CHARACTER STATS ==========\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Class: ARCHER\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "Arrows: " << arrows << "\n";
    std::cout << "Critical Chance: " << criticalChance << "%\n";
    std::cout << "XP: " << xp << "/" << xpToNextLevel << "\n";
    std::cout << "====================================\n\n";
}

// Getters
int Archer::getArrows() const { return arrows; }
int Archer::getCriticalChance() const { return criticalChance; }
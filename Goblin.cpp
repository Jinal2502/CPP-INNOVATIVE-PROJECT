#include "Goblin.h"
#include "Character.h"
#include <cstdlib>
#include <ctime>

// Constructor - Weak enemy, low stats, low XP reward
Goblin::Goblin() 
    : Enemy("Goblin", 40, 8, 30), canDodge(true) {
    srand(time(0));
}

// Destructor
Goblin::~Goblin() {}

// Override attack - Quick weak strikes
void Goblin::attack(Character* target) {
    if (target != nullptr) {
        std::cout << "👺 " << name << " swings a rusty dagger at " << target->getName() 
                  << " for " << attackPower << " damage!\n";
        target->takeDamage(attackPower);
    }
}

// Display info override
void Goblin::displayInfo() const {
    std::cout << "\n--- 👺 GOBLIN ---\n";
    std::cout << "A small, weak creature with a rusty dagger.\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "XP Reward: " << xpReward << "\n";
    std::cout << "Special: Can sometimes dodge attacks\n";
}

// Attempt to dodge (20% chance)
bool Goblin::attemptDodge() {
    if (!canDodge) return false;
    
    int roll = rand() % 100;
    if (roll < 20) { // 20% dodge chance
        std::cout << "💨 " << name << " dodges the attack!\n";
        return true;
    }
    return false;
}
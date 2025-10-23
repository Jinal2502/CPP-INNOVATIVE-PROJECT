#include "Orc.h"
#include "Character.h"

// Constructor - Medium difficulty enemy
Orc::Orc() 
    : Enemy("Orc Warrior", 80, 15, 60), rage(0), isEnraged(false) {}

// Destructor
Orc::~Orc() {}

// Override attack - Heavy hits, more when enraged
void Orc::attack(Character* target) {
    if (target != nullptr) {
        int damage = attackPower;
        
        if (isEnraged) {
            damage = damage + 5; // Bonus damage when enraged
            std::cout << "💢 ENRAGED! 💢\n";
        }
        
        std::cout << "⚔️ " << name << " swings a massive axe at " << target->getName() 
                  << " for " << damage << " damage!\n";
        target->takeDamage(damage);
    }
}

// Override takeDamage - builds rage
void Orc::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    
    std::cout << name << " takes " << damage << " damage! ";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    
    // Build rage when damaged
    buildRage();
}

// Build rage mechanic
void Orc::buildRage() {
    rage += 10;
    checkEnrage();
}

// Check if should become enraged
void Orc::checkEnrage() {
    if (rage >= 50 && !isEnraged) {
        isEnraged = true;
        std::cout << "💢 " << name << " becomes ENRAGED! Attack power increased!\n";
    }
}

// Display info override
void Orc::displayInfo() const {
    std::cout << "\n--- ⚔️ ORC WARRIOR ---\n";
    std::cout << "A brutal orc warrior wielding a massive battle axe.\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower;
    if (isEnraged) std::cout << " (+5 ENRAGED)";
    std::cout << "\n";
    std::cout << "XP Reward: " << xpReward << "\n";
    std::cout << "Special: Becomes enraged when damaged, increasing attack power\n";
}
#include "Dragon.h"
#include "Character.h"

// Constructor - Boss enemy with high stats
Dragon::Dragon() 
    : Enemy("Ancient Dragon", 200, 25, 150), fireBreathCooldown(0), canUseFlight(true) {}

// Destructor
Dragon::~Dragon() {}

// Override attack - Uses fire breath when available
void Dragon::attack(Character* target) {
    if (target != nullptr) {
        // Reduce cooldown
        if (fireBreathCooldown > 0) {
            fireBreathCooldown--;
        }
        
        // Use fire breath if available
        if (canUseFireBreath()) {
            useFireBreath(target);
        } else {
            // Normal melee attack
            std::cout << "🐉 " << name << " slashes with razor-sharp claws at " 
                      << target->getName() << " for " << attackPower << " damage!\n";
            target->takeDamage(attackPower);
        }
    }
}

// Fire breath special attack
void Dragon::useFireBreath(Character* target) {
    if (target != nullptr) {
        int fireBreathDamage = attackPower * 2; // Double damage!
        fireBreathCooldown = 3; // 3 turn cooldown
        
        std::cout << "\n🔥🔥🔥 FIRE BREATH! 🔥🔥🔥\n";
        std::cout << "🐉 " << name << " unleashes a torrent of flames!\n";
        std::cout << target->getName() << " is engulfed in fire for " 
                  << fireBreathDamage << " damage!\n";
        target->takeDamage(fireBreathDamage);
        std::cout << "Fire Breath cooldown: 3 turns\n";
    }
}

// Display info override
void Dragon::displayInfo() const {
    std::cout << "\n--- 🐉 ANCIENT DRAGON ---\n";
    std::cout << "A massive, ancient dragon with scales as hard as steel.\n";
    std::cout << "Its breath can incinerate anything in its path!\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "XP Reward: " << xpReward << "\n";
    std::cout << "Special: Fire Breath (deals double damage, 3 turn cooldown)\n";
    if (fireBreathCooldown > 0) {
        std::cout << "Fire Breath Cooldown: " << fireBreathCooldown << " turns\n";
    }
}

// Reduce cooldown
void Dragon::reduceCooldown() {
    if (fireBreathCooldown > 0) {
        fireBreathCooldown--;
    }
}

// Check if can use fire breath
bool Dragon::canUseFireBreath() const {
    return fireBreathCooldown == 0;
}
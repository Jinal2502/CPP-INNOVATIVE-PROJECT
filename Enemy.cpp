#include "Enemy.h"
#include "Character.h"

// Constructor
Enemy::Enemy(std::string enemyName, int hp, int atk, int xp)
    : name(enemyName), health(hp), maxHealth(hp), attackPower(atk), xpReward(xp) {}

// Virtual destructor
Enemy::~Enemy() {}

// Attack method
void Enemy::attack(Character* target) {
    if (target != nullptr) {
        std::cout << name << " attacks " << target->getName() << " for " << attackPower << " damage!\n";
        target->takeDamage(attackPower);
    }
}

// Take damage method
void Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    std::cout << name << " takes " << damage << " damage! ";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
}

// Display health bar
void Enemy::displayHealthBar() const {
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

// Display enemy info
void Enemy::displayInfo() const {
    std::cout << "\n--- " << name << " ---\n";
    std::cout << "Health: " << health << "/" << maxHealth << "\n";
    std::cout << "Attack Power: " << attackPower << "\n";
    std::cout << "XP Reward: " << xpReward << "\n";
}

// Getters
std::string Enemy::getName() const { return name; }
int Enemy::getHealth() const { return health; }
int Enemy::getMaxHealth() const { return maxHealth; }
int Enemy::getAttackPower() const { return attackPower; }
int Enemy::getXPReward() const { return xpReward; }
bool Enemy::isDead() const { return health <= 0; }

// Setters
void Enemy::setHealth(int hp) { 
    health = hp;
    if (health > maxHealth) health = maxHealth;
    if (health < 0) health = 0;
}
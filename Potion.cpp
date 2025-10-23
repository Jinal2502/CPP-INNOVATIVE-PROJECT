#include "Potion.h"
#include "Character.h"

// Constructor
Potion::Potion(std::string name, std::string desc, int heal)
    : Item(name, desc, "Potion"), healAmount(heal) {}

// Destructor
Potion::~Potion() {}

// Override use method - Heals character
void Potion::use(Character* target) {
    if (target != nullptr) {
        int currentHealth = target->getHealth();
        int maxHealth = target->getMaxHealth();
        
        if (currentHealth >= maxHealth) {
            std::cout << "\n" << target->getName() << " is already at full health!\n";
            return;
        }
        
        int newHealth = currentHealth + healAmount;
        if (newHealth > maxHealth) {
            newHealth = maxHealth;
        }
        
        target->setHealth(newHealth);
        int actualHealing = newHealth - currentHealth;
        
        std::cout << "\n💚 " << target->getName() << " drinks " << name << "!\n";
        std::cout << "Restored " << actualHealing << " HP!\n";
        std::cout << "Health: " << newHealth << "/" << maxHealth << "\n";
    }
}

// Override display info
void Potion::displayInfo() const {
    std::cout << "\n[POTION] 🧪 " << name << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Healing: +" << healAmount << " HP\n";
}

// Getter
int Potion::getHealAmount() const {
    return healAmount;
}
#include "Game.h"
#include "MatrixUI.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>

// Constructor
Game::Game() : player(nullptr), inventory(nullptr), isRunning(true), battlesWon(0) {
    srand(time(0)); // Seed random number generator
}

// Destructor
Game::~Game() {
    if (player != nullptr) {
        delete player;
    }
    if (inventory != nullptr) {
        delete inventory;
    }
}

// Clear screen (cross-platform)
void Game::clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Press enter to continue
void Game::pressEnterToContinue() {
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Get valid input within range
int Game::getValidInput(int min, int max) {
    int choice;
    while (true) {
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between " << min << " and " << max << ": ";
        } else if (choice < min || choice > max) {
            std::cout << "Please enter a number between " << min << " and " << max << ": ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

// Start the game
void Game::startGame() {
    MatrixUI::clearScreen();
    
    // Matrix loading effect
    MatrixUI::printLoadingBar(2);
    
    // Matrix rain effect
    MatrixUI::printMatrixRain(5);
    
    // Matrix logo
    MatrixUI::printMatrixLogo();
    
    // Animated welcome text
    MatrixUI::animateMatrixText("INITIALIZING CHRONICLES IN TEXT SYSTEM...", 80);
    MatrixUI::sleep(1000);
    
    MatrixUI::animateMatrixText("WELCOME TO THE TEXT-BASED REALM", 60);
    MatrixUI::sleep(500);
    
    MatrixUI::printGlitchEffect("ENTER THE CHRONICLES");
    
    MatrixUI::pressEnterToContinue();
    
    while (isRunning) {
        mainMenu();
    }
}

// Main menu
void Game::mainMenu() {
    MatrixUI::clearScreen();
    
    // Matrix art
    MatrixUI::printMatrixArt();
    
    // Create menu options
    std::vector<std::string> options = {
        "1. 🎮 NEW GAME",
        "2. 📁 LOAD GAME", 
        "3. 📖 INSTRUCTIONS",
        "4. 🚪 EXIT MATRIX"
    };
    
    MatrixUI::printMatrixMenu("MAIN MENU", options);
    
    std::cout << MatrixUI::BRIGHT_RED << "Choose an option: " << MatrixUI::RESET;
    int choice = getValidInput(1, 4);
    
    switch (choice) {
        case 1:
            newGame();
            break;
        case 2:
            loadGame();
            break;
        case 3:
            displayInstructions();
            break;
        case 4:
            exitGame();
            break;
    }
}

// Display instructions
void Game::displayInstructions() {
    clearScreen();
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    INSTRUCTIONS                        ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n\n";
    
    std::cout << "🎮 OBJECTIVE:\n";
    std::cout << "   • Create a character and battle enemies\n";
    std::cout << "   • Gain experience and level up to become stronger\n";
    std::cout << "   • Defeat the Ancient Dragon to win the game!\n\n";
    
    std::cout << "⚔️ CHARACTER CLASSES:\n";
    std::cout << "   • WARRIOR - High HP and armor, Shield Block ability\n";
    std::cout << "   • MAGE - High damage magic, Fireball spell (costs mana)\n";
    std::cout << "   • ARCHER - Balanced stats, Critical hits, Multi-shot\n\n";
    
    std::cout << "👾 ENEMIES:\n";
    std::cout << "   • GOBLIN - Weak but can dodge attacks\n";
    std::cout << "   • ORC - Strong warrior that becomes enraged\n";
    std::cout << "   • DRAGON - Powerful boss with fire breath\n\n";
    
    std::cout << "💡 TIPS:\n";
    std::cout << "   • Use potions wisely - they're consumed after use\n";
    std::cout << "   • Each class has a special ability - use it strategically\n";
    std::cout << "   • Level up by defeating enemies to increase your stats\n";
    std::cout << "   • Save your progress regularly!\n";
    std::cout << "════════════════════════════════════════════════════════\n";
    
    pressEnterToContinue();
}

// New game - Character creation
void Game::newGame() {
    clearScreen();
    
    // Clean up existing game state
    if (player != nullptr) {
        delete player;
        player = nullptr;
    }
    if (inventory != nullptr) {
        delete inventory;
        inventory = nullptr;
    }
    
    battlesWon = 0;
    
    // Create character
    createCharacter();
    
    // Create inventory and add starting items
    inventory = new Inventory(20);
    inventory->addItem(new Potion("Health Potion", "Restores 50 HP", 50));
    inventory->addItem(new Potion("Health Potion", "Restores 50 HP", 50));
    
    clearScreen();
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║             CHARACTER CREATED SUCCESSFULLY!            ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n";
    player->displayStats();
    std::cout << "\n🎁 Starting items: 2x Health Potions\n";
    std::cout << "\nYour adventure begins!\n";
    pressEnterToContinue();
    
    // Enter game world
    exploreWorld();
}

// Create character with class selection
void Game::createCharacter() {
    clearScreen();
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║                  CHARACTER CREATION                    ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n\n";
    
    std::string playerName;
    std::cout << "Enter your character's name: ";
    std::getline(std::cin, playerName);
    
    clearScreen();
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║                   SELECT YOUR CLASS                    ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n\n";
    
    std::cout << "1. ⚔️  WARRIOR\n";
    std::cout << "   • Health: 120 HP\n";
    std::cout << "   • Attack: 18\n";
    std::cout << "   • Armor: 10\n";
    std::cout << "   • Special: Shield Block (reduces damage by 50%)\n\n";
    
    std::cout << "2. 🔮 MAGE\n";
    std::cout << "   • Health: 80 HP\n";
    std::cout << "   • Attack: 22\n";
    std::cout << "   • Mana: 50\n";
    std::cout << "   • Special: Fireball (double damage, costs 20 mana)\n\n";
    
    std::cout << "3. 🏹 ARCHER\n";
    std::cout << "   • Health: 100 HP\n";
    std::cout << "   • Attack: 20\n";
    std::cout << "   • Arrows: 30\n";
    std::cout << "   • Special: Multi-Shot (3 arrows, critical chance)\n\n";
    
    std::cout << "Choose your class (1-3): ";
    int classChoice = getValidInput(1, 3);
    
    switch (classChoice) {
        case 1:
            player = new Warrior(playerName);
            break;
        case 2:
            player = new Mage(playerName);
            break;
        case 3:
            player = new Archer(playerName);
            break;
    }
    
    pressEnterToContinue();
}

// Generate random enemy
Enemy* Game::generateRandomEnemy() {
    // Use better randomization with current time + battlesWon for variety
    static unsigned int seed = time(0);
    seed = seed * 1103515245 + 12345; // Linear congruential generator
    int roll = (seed >> 16) % 100;
    
    // Adjust probabilities based on battles won for better progression
    int goblinChance, orcChance, dragonChance;
    
    if (battlesWon < 2) {
        // Early game: mostly goblins
        goblinChance = 70;
        orcChance = 25;
        dragonChance = 5;
    } else if (battlesWon < 4) {
        // Mid game: more orcs
        goblinChance = 50;
        orcChance = 40;
        dragonChance = 10;
    } else {
        // Late game: more variety
        goblinChance = 40;
        orcChance = 45;
        dragonChance = 15;
    }
    
    if (roll < goblinChance) {
        return new Goblin();
    } else if (roll < goblinChance + orcChance) {
        return new Orc();
    } else {
        return new Dragon();
    }
}

// Generate boss enemy
Enemy* Game::generateBossEnemy() {
    return new Dragon();
}

// Give rewards after battle
void Game::giveRewards() {
    // Random chance for potion drop
    int potionRoll = rand() % 100;
    if (potionRoll < 40) { // 40% chance
        inventory->addItem(new Potion("Health Potion", "Restores 50 HP", 50));
    }
    
    // Random chance for weapon drop (rare)
    int weaponRoll = rand() % 100;
    if (weaponRoll < 15) { // 15% chance
        inventory->addItem(new Weapon("Iron Sword", "A sturdy iron blade", 5));
    }
}

// Load game from file
void Game::loadGame() {
    if (loadGameFromFile()) {
        std::cout << "\n✅ Game loaded successfully!\n";
        pressEnterToContinue();
        exploreWorld();
    } else {
        std::cout << "\n❌ No saved game found or failed to load.\n";
        pressEnterToContinue();
    }
}

// Load game from file implementation
bool Game::loadGameFromFile() {
    std::ifstream file("savegame.txt");
    if (!file.is_open()) {
        return false;
    }
    
    std::string name, classType;
    int health, maxHealth, level, xp, attackPower, battlesCount;
    
    std::getline(file, name);
    std::getline(file, classType);
    file >> health >> maxHealth >> level >> xp >> attackPower >> battlesCount;
    file.close();
    
    // Clean up existing player
    if (player != nullptr) {
        delete player;
    }
    if (inventory != nullptr) {
        delete inventory;
    }
    
    // Create character based on saved class
    if (classType == "Warrior") {
        player = new Warrior(name);
    } else if (classType == "Mage") {
        player = new Mage(name);
    } else if (classType == "Archer") {
        player = new Archer(name);
    } else {
        return false;
    }
    
    // Restore stats
    player->setHealth(health);
    player->setLevel(level);
    player->setXP(xp);
    battlesWon = battlesCount;
    
    // Create inventory with starting potions
    inventory = new Inventory(20);
    inventory->addItem(new Potion("Health Potion", "Restores 50 HP", 50));
    
    return true;
}

// Explore world
void Game::exploreWorld() {
    while (isRunning && player != nullptr && player->isAlive()) {
        clearScreen();
        std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
        std::cout << "║                    GAME WORLD                          ║\n";
        std::cout << "╚════════════════════════════════════════════════════════╝\n\n";
        
        player->displayHealthBar();
        std::cout << "Level: " << player->getLevel() << " | XP: " << player->getXP() << "\n";
        std::cout << "Battles Won: " << battlesWon << "\n";
        std::cout << "════════════════════════════════════════════════════════\n\n";
        
        std::cout << "What would you like to do?\n";
        std::cout << "  1. 🗺️  Explore (Find enemies)\n";
        std::cout << "  2. 📊 View Stats\n";
        std::cout << "  3. 🎒 View Inventory\n";
        std::cout << "  4. 💾 Save Game\n";
        std::cout << "  5. 🚪 Return to Main Menu\n";
        
        if (battlesWon >= 5) {
            std::cout << "  6. 🐉 CHALLENGE THE DRAGON BOSS!\n";
        }
        
        std::cout << "\nChoose an option: ";
        
        int maxChoice = (battlesWon >= 5) ? 6 : 5;
        int choice = getValidInput(1, maxChoice);
        
        switch (choice) {
            case 1: {
                Enemy* enemy = generateRandomEnemy();
                combat(enemy);
                delete enemy;
                break;
            }
            case 2:
                clearScreen();
                player->displayStats();
                pressEnterToContinue();
                break;
            case 3:
                viewInventory();
                break;
            case 4:
                saveGame();
                pressEnterToContinue();
                break;
            case 5:
                return; // Return to main menu
            case 6:
                if (battlesWon >= 5) {
                    std::cout << "\n🐉 You have earned the right to challenge the Ancient Dragon!\n";
                    std::cout << "This is the final battle. Are you ready? (Press Enter to continue)\n";
                    pressEnterToContinue();
                    Enemy* boss = generateBossEnemy();
                    combat(boss);
                    delete boss;
                } else {
                    std::cout << "\n❌ You need to win " << (5 - battlesWon) << " more battles before challenging the Dragon!\n";
                    pressEnterToContinue();
                }
                break;
        }
    }
    
    if (player != nullptr && !player->isAlive()) {
        clearScreen();
        std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
        std::cout << "║                      GAME OVER                         ║\n";
        std::cout << "╚════════════════════════════════════════════════════════╝\n\n";
        std::cout << "💀 You have been defeated!\n\n";
        std::cout << "Final Stats:\n";
        std::cout << "  • Level Reached: " << player->getLevel() << "\n";
        std::cout << "  • Battles Won: " << battlesWon << "\n";
        std::cout << "\nBetter luck next time, brave adventurer!\n";
        pressEnterToContinue();
    }
}

// View inventory
void Game::viewInventory() {
    while (true) {
        clearScreen();
        inventory->displayInventory();
        
        if (inventory->isEmpty()) {
            pressEnterToContinue();
            return;
        }
        
        std::cout << "\n1. Use Item\n";
        std::cout << "2. View Item Details\n";
        std::cout << "3. Back\n";
        std::cout << "\nChoose an option: ";
        
        int choice = getValidInput(1, 3);
        
        if (choice == 1) {
            useItemFromInventory();
        } else if (choice == 2) {
            std::cout << "Enter item number: ";
            int itemNum = getValidInput(1, inventory->getItemCount());
            inventory->displayItemDetails(itemNum - 1);
            pressEnterToContinue();
        } else {
            return;
        }
    }
}

// Use item from inventory
void Game::useItemFromInventory() {
    std::cout << "Enter item number to use: ";
    int itemNum = getValidInput(1, inventory->getItemCount());
    inventory->useItem(itemNum - 1, player);
    pressEnterToContinue();
}

// Combat system
void Game::combat(Enemy* enemy) {
    clearScreen();
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║                    BATTLE START!                       ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n";
    std::cout << "\n⚔️  A wild " << enemy->getName() << " appears!\n";
    enemy->displayInfo();
    pressEnterToContinue();
    
    // Battle loop
    while (player->isAlive() && !enemy->isDead()) {
        clearScreen();
        std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
        std::cout << "║                       BATTLE                           ║\n";
        std::cout << "╚════════════════════════════════════════════════════════╝\n\n";
        
        player->displayHealthBar();
        enemy->displayHealthBar();
        std::cout << "\n════════════════════════════════════════════════════════\n";
        
        std::cout << "\nYour Turn:\n";
        std::cout << "  1. ⚔️  Attack\n";
        std::cout << "  2. ✨ Use Special Skill\n";
        std::cout << "  3. 🧪 Use Item\n";
        std::cout << "  4. 🏃 Run Away\n";
        std::cout << "\nChoose an action: ";
        
        int choice = getValidInput(1, 4);
        
        if (choice == 1) {
            performAttack(enemy);
        } else if (choice == 2) {
            useSpecialSkill(enemy);
        } else if (choice == 3) {
            useItemInCombat(enemy);
        } else if (choice == 4) {
            std::cout << "\n🏃 You ran away from battle!\n";
            pressEnterToContinue();
            return;
        }
        
        if (enemy->isDead()) {
            std::cout << "\n════════════════════════════════════════════════════════\n";
            std::cout << "🎉 VICTORY! " << enemy->getName() << " has been defeated!\n";
            std::cout << "════════════════════════════════════════════════════════\n";
            player->gainXP(enemy->getXPReward());
            battlesWon++;
            std::cout << "🎯 Total Battles Won: " << battlesWon << "/5\n";
            giveRewards();
            
            // Check for game completion
            if (enemy->getName() == "Ancient Dragon") {
                displayVictory();
                return;
            }
            
            pressEnterToContinue();
            return;
        }
        
        // Enemy's turn
        std::cout << "\n--- Enemy's Turn ---\n";
        enemy->attack(player);
        
        // Reduce cooldowns for Warrior
        if (Warrior* warrior = dynamic_cast<Warrior*>(player)) {
            warrior->reduceCooldown();
        }
        
        if (!player->isAlive()) {
            std::cout << "\n════════════════════════════════════════════════════════\n";
            std::cout << "💀 You have been defeated!\n";
            std::cout << "════════════════════════════════════════════════════════\n";
            pressEnterToContinue();
            return;
        }
        
        pressEnterToContinue();
    }
}

// Perform attack
void Game::performAttack(Enemy* enemy) {
    std::cout << "\n--- Your Attack ---\n";
    if (enemy != nullptr) {
        std::cout << player->getName() << " attacks " << enemy->getName() 
                  << " for " << player->getAttackPower() << " damage!\n";
        enemy->takeDamage(player->getAttackPower());
    }
}

// Use special skill
void Game::useSpecialSkill(Enemy* enemy) {
    std::cout << "\n--- Special Skill ---\n";
    
    if (Warrior* warrior = dynamic_cast<Warrior*>(player)) {
        warrior->useShieldBlock();
    } else if (Mage* mage = dynamic_cast<Mage*>(player)) {
        mage->castFireball(enemy);
    } else if (Archer* archer = dynamic_cast<Archer*>(player)) {
        archer->useMultiShot(enemy);
    }
}

// Use item in combat
void Game::useItemInCombat(Enemy* enemy) {
    if (inventory->isEmpty()) {
        std::cout << "\nInventory is empty!\n";
        return;
    }
    
    int potionIndex = inventory->findPotion();
    if (potionIndex == -1) {
        std::cout << "\nNo potions available!\n";
        return;
    }
    
    std::cout << "\n--- Using Item ---\n";
    inventory->useItem(potionIndex, player);
}

// Save game to file
void Game::saveGame() {
    if (player == nullptr) {
        std::cout << "\n❌ No character to save!\n";
        return;
    }
    
    std::ofstream file("savegame.txt");
    if (!file.is_open()) {
        std::cout << "\n❌ Failed to save game!\n";
        return;
    }
    
    // Determine class type
    std::string classType;
    if (dynamic_cast<Warrior*>(player)) {
        classType = "Warrior";
    } else if (dynamic_cast<Mage*>(player)) {
        classType = "Mage";
    } else if (dynamic_cast<Archer*>(player)) {
        classType = "Archer";
    }
    
    file << player->getName() << "\n";
    file << classType << "\n";
    file << player->getHealth() << " ";
    file << player->getMaxHealth() << " ";
    file << player->getLevel() << " ";
    file << player->getXP() << " ";
    file << player->getAttackPower() << " ";
    file << battlesWon << "\n";
    
    file.close();
    std::cout << "\n💾 Game saved successfully to 'savegame.txt'!\n";
}

// Display victory screen
void Game::displayVictory() {
    clearScreen();
    std::cout << "\n";
    std::cout << "╔═══════════════════════════════════════════════════════════════╗\n";
    std::cout << "║                                                               ║\n";
    std::cout << "║              🎉🎉🎉 CONGRATULATIONS! 🎉🎉🎉                    ║\n";
    std::cout << "║                                                               ║\n";
    std::cout << "║         YOU HAVE DEFEATED THE ANCIENT DRAGON!                ║\n";
    std::cout << "║                                                               ║\n";
    std::cout << "║              The realm is saved thanks to you!               ║\n";
    std::cout << "║                                                               ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════════════╝\n\n";
    
    std::cout << "🏆 FINAL STATS:\n";
    std::cout << "   • Hero: " << player->getName() << "\n";
    std::cout << "   • Final Level: " << player->getLevel() << "\n";
    std::cout << "   • Total Battles Won: " << battlesWon << "\n";
    std::cout << "\n✨ You are now a legend!\n\n";
    
    pressEnterToContinue();
    
    // Reset game
    delete player;
    player = nullptr;
    delete inventory;
    inventory = nullptr;
}

// Exit game
void Game::exitGame() {
    clearScreen();
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║       Thank you for playing Chronicles in Text!       ║\n";
    std::cout << "║              May your adventures continue!             ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n\n";
    isRunning = false;
}
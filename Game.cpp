#include "Game.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>

// Constructor
Game::Game() : player(nullptr), isRunning(true) {}

// Destructor
Game::~Game() {
    if (player != nullptr) {
        delete player;
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

// Start the game
void Game::startGame() {
    clearScreen();
    std::cout << "========================================\n";
    std::cout << "     CHRONICLES IN TEXT - RPG GAME      \n";
    std::cout << "========================================\n\n";
    
    while (isRunning) {
        mainMenu();
    }
}

// Main menu
void Game::mainMenu() {
    clearScreen();
    std::cout << "\n============ MAIN MENU ============\n";
    std::cout << "1. New Game\n";
    std::cout << "2. Load Game\n";
    std::cout << "3. Instructions\n";
    std::cout << "4. Exit\n";
    std::cout << "===================================\n";
    std::cout << "Choose an option: ";
    
    int choice;
    std::cin >> choice;
    
    // Handle invalid input
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number.\n";
        pressEnterToContinue();
        return;
    }
    
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
        default:
            std::cout << "Invalid choice! Please try again.\n";
            pressEnterToContinue();
    }
}

// Display instructions
void Game::displayInstructions() {
    clearScreen();
    std::cout << "\n========== INSTRUCTIONS ==========\n\n";
    std::cout << "Welcome to Chronicles in Text!\n\n";
    std::cout << "OBJECTIVE:\n";
    std::cout << "- Create a character and battle enemies\n";
    std::cout << "- Gain experience and level up\n";
    std::cout << "- Collect items and become stronger\n\n";
    std::cout << "GAMEPLAY:\n";
    std::cout << "- Choose your character class carefully\n";
    std::cout << "- Explore the world to find enemies\n";
    std::cout << "- Use strategy in combat to survive\n";
    std::cout << "- Save your progress regularly\n\n";
    std::cout << "TIPS:\n";
    std::cout << "- Different classes have unique abilities\n";
    std::cout << "- Level up to increase your stats\n";
    std::cout << "- Use potions wisely during battles\n";
    std::cout << "==================================\n";
    pressEnterToContinue();
}

// New game - Character creation
void Game::newGame() {
    clearScreen();
    std::cout << "\n========== CHARACTER CREATION ==========\n\n";
    
    std::string playerName;
    std::cout << "Enter your character's name: ";
    std::cin.ignore();
    std::getline(std::cin, playerName);
    
    // For Phase 1, we'll create a basic character
    // In Phase 2, we'll add class selection
    player = new Character(playerName, 100, 15);
    
    clearScreen();
    std::cout << "\n========== CHARACTER CREATED ==========\n";
    player->displayStats();
    std::cout << "Your adventure begins!\n";
    pressEnterToContinue();
    
    // Enter game world
    exploreWorld();
}

// Load game from file
void Game::loadGame() {
    if (loadGameFromFile()) {
        std::cout << "\nGame loaded successfully!\n";
        pressEnterToContinue();
        exploreWorld();
    } else {
        std::cout << "\nNo saved game found or failed to load.\n";
        pressEnterToContinue();
    }
}

// Load game from file implementation
bool Game::loadGameFromFile() {
    std::ifstream file("savegame.txt");
    if (!file.is_open()) {
        return false;
    }
    
    std::string name;
    int health, maxHealth, level, xp, attackPower;
    
    std::getline(file, name);
    file >> health >> maxHealth >> level >> xp >> attackPower;
    file.close();
    
    // Create character with loaded data
    if (player != nullptr) {
        delete player;
    }
    
    player = new Character(name, maxHealth, attackPower);
    player->setHealth(health);
    player->setLevel(level);
    player->setXP(xp);
    
    return true;
}

// Explore world
void Game::exploreWorld() {
    while (isRunning && player != nullptr && player->isAlive()) {
        clearScreen();
        std::cout << "\n========== GAME WORLD ==========\n";
        player->displayHealthBar();
        std::cout << "Level: " << player->getLevel() << " | XP: " << player->getXP() << "\n";
        std::cout << "================================\n\n";
        std::cout << "What would you like to do?\n";
        std::cout << "1. Explore (Find enemies)\n";
        std::cout << "2. View Stats\n";
        std::cout << "3. Save Game\n";
        std::cout << "4. Return to Main Menu\n";
        std::cout << "\nChoose an option: ";
        
        int choice;
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        switch (choice) {
            case 1: {
                // Create a basic enemy for Phase 1
                Enemy* enemy = new Enemy("Goblin", 50, 10, 50);
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
                saveGame();
                pressEnterToContinue();
                break;
            case 4:
                return; // Return to main menu
            default:
                std::cout << "Invalid choice!\n";
                pressEnterToContinue();
        }
    }
    
    if (player != nullptr && !player->isAlive()) {
        clearScreen();
        std::cout << "\n========== GAME OVER ==========\n";
        std::cout << "You have been defeated!\n";
        std::cout << "Final Level: " << player->getLevel() << "\n";
        std::cout << "===============================\n";
        pressEnterToContinue();
    }
}

// Combat system
void Game::combat(Enemy* enemy) {
    clearScreen();
    std::cout << "\n========== BATTLE START ==========\n";
    std::cout << "A wild " << enemy->getName() << " appears!\n";
    enemy->displayInfo();
    pressEnterToContinue();
    
    // Battle loop
    while (player->isAlive() && !enemy->isDead()) {
        clearScreen();
        std::cout << "\n========== BATTLE ==========\n";
        player->displayHealthBar();
        enemy->displayHealthBar();
        std::cout << "============================\n\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Run\n";
        std::cout << "\nChoose an action: ";
        
        int choice;
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        if (choice == 1) {
            // Player attacks
            std::cout << "\n";
            player->attack(enemy);
            
            if (enemy->isDead()) {
                std::cout << "\n" << enemy->getName() << " has been defeated!\n";
                player->gainXP(enemy->getXPReward());
                pressEnterToContinue();
                return;
            }
            
            // Enemy attacks back
            std::cout << "\n";
            enemy->attack(player);
            
            if (!player->isAlive()) {
                std::cout << "\nYou have been defeated!\n";
                pressEnterToContinue();
                return;
            }
            
            pressEnterToContinue();
            
        } else if (choice == 2) {
            std::cout << "\nYou ran away from battle!\n";
            pressEnterToContinue();
            return;
        }
    }
}

// Save game to file
void Game::saveGame() {
    if (player == nullptr) {
        std::cout << "\nNo character to save!\n";
        return;
    }
    
    std::ofstream file("savegame.txt");
    if (!file.is_open()) {
        std::cout << "\nFailed to save game!\n";
        return;
    }
    
    file << player->getName() << "\n";
    file << player->getHealth() << " ";
    file << player->getMaxHealth() << " ";
    file << player->getLevel() << " ";
    file << player->getXP() << " ";
    file << player->getAttackPower() << "\n";
    
    file.close();
    std::cout << "\nGame saved successfully!\n";
}

// Exit game
void Game::exitGame() {
    std::cout << "\nThank you for playing Chronicles in Text!\n";
    std::cout << "Goodbye!\n";
    isRunning = false;
}
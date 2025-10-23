#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Potion.h"
#include <string>

class Game {
private:
    Character* player;
    Inventory* inventory;
    bool isRunning;
    int battlesWon;
    
    // Helper methods
    void clearScreen();
    void pressEnterToContinue();
    int getValidInput(int min, int max);
    
    // Enemy generation
    Enemy* generateRandomEnemy();
    Enemy* generateBossEnemy();
    
    // Reward system
    void giveRewards();
    
public:
    // Constructor & Destructor
    Game();
    ~Game();
    
    // Main game flow
    void startGame();
    void mainMenu();
    void displayInstructions();
    void newGame();
    void loadGame();
    void exploreWorld();
    void combat(Enemy* enemy);
    
    // Character creation
    void createCharacter();
    
    // Inventory management
    void viewInventory();
    void useItemFromInventory();
    
    // Combat actions
    void performAttack(Enemy* enemy);
    void useSpecialSkill(Enemy* enemy);
    void useItemInCombat(Enemy* enemy);
    
    // Save/Load
    void saveGame();
    bool loadGameFromFile();
    
    // Utility
    void exitGame();
    void displayVictory();
};

#endif
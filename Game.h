#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Enemy.h"
#include <string>
#include <memory>

class Game {
private:
    Character* player;
    bool isRunning;
    
    // Helper methods
    void clearScreen();
    void pressEnterToContinue();
    
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
    
    // Save/Load
    void saveGame();
    bool loadGameFromFile();
    
    // Utility
    void exitGame();
};

#endif
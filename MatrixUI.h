#ifndef MATRIXUI_H
#define MATRIXUI_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <iomanip>

class MatrixUI {
public:
    // ANSI Color Codes for Matrix Red Theme
    static const std::string RESET;
    static const std::string BRIGHT_RED;
    static const std::string DARK_RED;
    static const std::string RED_BG;
    static const std::string BRIGHT_WHITE;
    static const std::string DIM_RED;
    static const std::string CYAN;
    static const std::string YELLOW;
    static const std::string GREEN;
    
    // Matrix-style effects
    static void clearScreen();
    static void printMatrixTitle(const std::string& title);
    static void printMatrixBox(const std::string& title, const std::string& content);
    static void printMatrixSeparator(char ch = '═', int width = 60);
    static void animateMatrixText(const std::string& text, int delay = 50);
    static void printMatrixRain(int lines = 10);
    static void printMatrixLogo();
    static void pressEnterToContinue();
    static void printMatrixMenu(const std::string& title, const std::vector<std::string>& options);
    static void printMatrixArt();
    static void printGlitchEffect(const std::string& text);
    static void printLoadingBar(int duration = 3);
    
    // Enhanced UI functions
    static void printCharacterCreationHeader();
    static void printClassSelection(const std::string& className, const std::string& description, const std::vector<std::string>& stats);
    static void printCombatHeader(const std::string& playerName, const std::string& enemyName);
    static void printHealthBar(int current, int max, const std::string& name, bool isPlayer = true);
    static void printCombatMenu();
    static void printInventoryHeader();
    static void printItemBox(const std::string& itemName, const std::string& description, int quantity = 1);
    static void printStatsDisplay(const std::string& name, int level, int health, int maxHealth, int attack, int xp, int xpToNext);
    static void printVictoryScreen(const std::string& enemyName, int xpGained);
    static void printGameOverScreen(int finalLevel, int battlesWon);
    static void printBossWarning();
    static void printLevelUpAnimation(const std::string& name, int newLevel);
    
    // Utility functions
    static void sleep(int milliseconds);
    static int getRandom(int min, int max);
    static std::string getMatrixChar();
};

#endif

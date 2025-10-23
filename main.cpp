#include "Game.h"
#include <iostream>

/*
 * CHRONICLES IN TEXT - Text-Based RPG Game
 * 
 * A console-based Role-Playing Game demonstrating OOP concepts:
 * - Inheritance (Character classes, Enemy types)
 * - Polymorphism (Different attack behaviors)
 * - Encapsulation (Private attributes, public methods)
 * - Abstraction (Pure virtual functions in Item class)
 * - Composition (Inventory HAS-A collection of Items)
 * 
 * Created as an educational C++ OOP project
 */

int main() {
    try {
        // Create game instance
        Game game;
        
        // Start the game
        game.startGame();
        
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
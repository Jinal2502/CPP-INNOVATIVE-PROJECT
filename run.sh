#!/bin/bash
echo "🎮 Compiling Chronicles in Text..."
g++-15 -std=c++17 main.cpp Game.cpp Character.cpp Warrior.cpp Mage.cpp Archer.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp Item.cpp Weapon.cpp Potion.cpp Inventory.cpp -o rpg_game

if [ $? -eq 0 ]; then
    echo "✅ Compilation successful!"
    echo "🎮 Starting game..."
    ./rpg_game
else
    echo "❌ Compilation failed!"
fi
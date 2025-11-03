@echo off
echo 🎮 Compiling Chronicles in Text...
g++ -std=c++17 main.cpp Game.cpp Character.cpp Warrior.cpp Mage.cpp Archer.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp Item.cpp Weapon.cpp Potion.cpp Inventory.cpp MatrixUI.cpp -o rpg_game.exe

if %errorlevel% == 0 (
    echo ✅ Compilation successful!
    echo 🎮 Starting game...
    rpg_game.exe
) else (
    echo ❌ Compilation failed!
)


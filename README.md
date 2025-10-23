# 📜 Chronicles in Text - RPG Game

A console-based Role-Playing Game built in C++ demonstrating Object-Oriented Programming concepts.

## 🎮 Game Overview

Chronicles in Text is a text-based RPG where you create a character, battle enemies, collect items, and progress through levels to ultimately defeat the Ancient Dragon and save the realm!

## ✨ Features

- **3 Character Classes**: Warrior, Mage, Archer (each with unique abilities)
- **3 Enemy Types**: Goblin, Orc, Dragon (with different behaviors)
- **Turn-Based Combat**: Strategic battle system
- **Leveling System**: Gain XP and level up to become stronger
- **Inventory Management**: Collect and use items
- **Save/Load System**: Continue your adventure anytime
- **Boss Battle**: Epic final battle against the Ancient Dragon

## 🛠️ Technologies Used

- **Language**: C++ (C++11 or higher)
- **Compiler**: g++ (MinGW for Windows / GCC for Linux/Mac)
- **IDE**: VS Code (or any C++ IDE)
- **Libraries**: Standard Template Library (STL)

## 📦 File Structure

```
RPG-Game/
├── main.cpp              # Entry point
├── Game.h/.cpp           # Game controller
├── Character.h/.cpp      # Base character class
├── Warrior.h/.cpp        # Warrior class
├── Mage.h/.cpp           # Mage class
├── Archer.h/.cpp         # Archer class
├── Enemy.h/.cpp          # Base enemy class
├── Goblin.h/.cpp         # Goblin enemy
├── Orc.h/.cpp            # Orc enemy
├── Dragon.h/.cpp         # Dragon boss
├── Item.h/.cpp           # Base item class
├── Weapon.h/.cpp         # Weapon item
├── Potion.h/.cpp         # Potion item
├── Inventory.h/.cpp      # Inventory system
└── savegame.txt          # (created at runtime)
```

## 🔧 Compilation Instructions

### Windows (MinGW):
```bash
g++ -std=c++11 main.cpp Game.cpp Character.cpp Warrior.cpp Mage.cpp Archer.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp Item.cpp Weapon.cpp Potion.cpp Inventory.cpp -o rpg_game.exe
rpg_game.exe
```

### Linux/Mac:
```bash
g++ -std=c++11 main.cpp Game.cpp Character.cpp Warrior.cpp Mage.cpp Archer.cpp Enemy.cpp Goblin.cpp Orc.cpp Dragon.cpp Item.cpp Weapon.cpp Potion.cpp Inventory.cpp -o rpg_game
./rpg_game
```

### Using Makefile (if provided):
```bash
make
./rpg_game
```

## 🎯 How to Play

1. **Start the Game**: Run the executable
2. **Main Menu**: Choose "New Game" or "Load Game"
3. **Character Creation**: 
   - Enter your character's name
   - Choose a class (Warrior, Mage, or Archer)
4. **Exploration**: Navigate the game world
5. **Combat**: Fight enemies using attacks, special skills, or items
6. **Level Up**: Gain XP by defeating enemies
7. **Boss Battle**: Win 5 battles to unlock the Dragon boss
8. **Victory**: Defeat the Ancient Dragon to win!

## ⚔️ Character Classes

### 🛡️ Warrior
- **Health**: 120 HP
- **Attack**: 18
- **Armor**: 10 points
- **Special Ability**: Shield Block (reduces damage by 50% for 1 turn)
- **Best For**: Tanky playstyle, surviving long battles

### 🔮 Mage
- **Health**: 80 HP
- **Attack**: 22
- **Mana**: 50
- **Special Ability**: Fireball (double damage, costs 20 mana)
- **Best For**: High damage output, quick battles

### 🏹 Archer
- **Health**: 100 HP
- **Attack**: 20
- **Arrows**: 30
- **Special Ability**: Multi-Shot (3 arrows, 25% critical chance)
- **Best For**: Balanced gameplay, consistent damage

## 👾 Enemies

### 👺 Goblin
- **Difficulty**: Easy
- **Health**: 40 HP
- **Attack**: 8
- **XP Reward**: 30
- **Special**: Can dodge attacks (20% chance)

### ⚔️ Orc Warrior
- **Difficulty**: Medium
- **Health**: 80 HP
- **Attack**: 15 (+5 when enraged)
- **XP Reward**: 60
- **Special**: Becomes enraged when damaged

### 🐉 Ancient Dragon (Boss)
- **Difficulty**: Hard
- **Health**: 200 HP
- **Attack**: 25
- **XP Reward**: 150
- **Special**: Fire Breath (double damage, 3 turn cooldown)

## 💡 Tips & Strategies

- **Save Often**: Don't lose your progress!
- **Use Potions Wisely**: They're consumed after use
- **Special Abilities**: Each class has a powerful special - use strategically
- **Level Up**: Higher levels mean better stats
- **Boss Preparation**: Stock up on potions before fighting the Dragon

## 🎓 OOP Concepts Demonstrated

This project showcases key Object-Oriented Programming principles:

1. **Inheritance**: Character classes inherit from base Character class; Enemy types inherit from Enemy class
2. **Polymorphism**: Different attack behaviors for each class and enemy type
3. **Encapsulation**: Private attributes with public getter/setter methods
4. **Abstraction**: Pure virtual functions in Item base class
5. **Composition**: Inventory HAS-A collection of Item objects

## 💾 Save System

Game progress is saved to `savegame.txt` including:
- Character name and class
- Current health, level, and XP
- Number of battles won

## 🐛 Troubleshooting

### Compilation Errors:
- Ensure all `.h` and `.cpp` files are in the same directory
- Use C++11 or higher: `-std=c++11` flag
- Check that all header guards are correct

### Runtime Issues:
- **Screen not clearing**: Normal behavior on some terminals
- **Random not working**: Ensure proper seeding in main
- **Save file not found**: File is created after first save

## 📝 Future Enhancements

Potential additions for learning purposes:
- More character classes and enemies
- Equipment system with multiple weapon slots
- Magic spell system expansion
- Multiplayer/co-op mode
- Dungeon generation
- Quest system
- Character stats customization

## 👨‍💻 Author

Created as an educational C++ project demonstrating OOP concepts in a practical, engaging application.

## 📄 License

Free to use for educational purposes.

---

**Happy Gaming! May your adventures be legendary! ⚔️🐉**
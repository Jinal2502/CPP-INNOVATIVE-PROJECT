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

## 🎓 Object-Oriented Programming (OOP) Concepts

This project comprehensively demonstrates all core Object-Oriented Programming principles through a practical, real-world application. Below is a detailed explanation of each OOP concept implemented in the codebase.

### 1. 🔗 **Inheritance**

**Concept**: Inheritance allows a new class (derived/child class) to acquire the properties and behaviors of an existing class (base/parent class), promoting code reusability and establishing an "is-a" relationship.

**Implementation in Project**:

#### **Character Inheritance Hierarchy**
- **Base Class**: `Character` (defined in `Character.h/.cpp`)
  - Contains common attributes: `name`, `health`, `maxHealth`, `level`, `xp`, `attackPower`
  - Provides common methods: `attack()`, `takeDamage()`, `gainXP()`, `levelUp()`
  
- **Derived Classes**:
  - `Warrior : public Character` - Inherits from Character, adds `armorPoints`, `shieldBlockActive`
  - `Mage : public Character` - Inherits from Character, adds `mana`, `maxMana`, `manaRegen`
  - `Archer : public Character` - Inherits from Character, adds `arrows`, `criticalChance`

**Example**:
```cpp
class Warrior : public Character {
    // Warrior-specific attributes
    int armorPoints;
    bool shieldBlockActive;
    // Inherits all Character attributes and methods
};
```

#### **Enemy Inheritance Hierarchy**
- **Base Class**: `Enemy` (defined in `Enemy.h/.cpp`)
  - Contains common enemy attributes: `name`, `health`, `maxHealth`, `attackPower`, `xpReward`
  
- **Derived Classes**:
  - `Goblin : public Enemy` - Weak enemy with dodge ability
  - `Orc : public Enemy` - Medium enemy with enrage mechanic
  - `Dragon : public Enemy` - Boss enemy with fire breath special attack

#### **Item Inheritance Hierarchy**
- **Base Class**: `Item` (defined in `Item.h/.cpp`)
  - Contains common item attributes: `name`, `description`, `type`
  
- **Derived Classes**:
  - `Weapon : public Item` - Adds `attackBonus` attribute
  - `Potion : public Item` - Adds `healAmount` attribute

**Benefits**: Eliminates code duplication, makes the codebase easier to maintain, and allows for consistent interfaces across related classes.

---

### 2. 🔀 **Polymorphism**

**Concept**: Polymorphism enables objects of different types to be accessed through the same interface. In C++, this is achieved through virtual functions and runtime binding, allowing "one interface, multiple implementations."

**Implementation in Project**:

#### **Virtual Functions**
- Base class methods declared with `virtual` keyword allow derived classes to override them
- Enables runtime polymorphism through base class pointers

**Character Polymorphism**:
- `Character::attack(Character* target)` - Virtual method
- `Warrior::attack()` - Overrides with physical melee attack
- `Mage::attack()` - Overrides with magical attack
- `Archer::attack()` - Overrides with ranged arrow attack

**Example**:
```cpp
class Character {
public:
    virtual void attack(Character* target);  // Virtual function
    virtual void displayStats() const;        // Virtual function
};

class Warrior : public Character {
public:
    void attack(Character* target) override;      // Polymorphic override
    void displayStats() const override;           // Polymorphic override
};
```

**Enemy Polymorphism**:
- `Enemy::attack(Character* target)` - Virtual method
- Each enemy type (`Goblin`, `Orc`, `Dragon`) overrides with unique attack behaviors
- `Enemy::displayInfo()` - Virtual method with different displays per enemy type

**Item Polymorphism**:
- `Item::use(Character* target) = 0` - Pure virtual function (abstract)
- `Weapon::use()` - Implements weapon usage (increases attack power)
- `Potion::use()` - Implements potion usage (restores health)

**Runtime Polymorphism Example**:
```cpp
Character* player = new Warrior("Hero");  // Base pointer to derived object
player->attack(enemy);                     // Calls Warrior::attack() at runtime
```

**Benefits**: Allows flexible, extensible code where new character/enemy/item types can be added without modifying existing code that uses base class pointers.

---

### 3. 🔒 **Encapsulation**

**Concept**: Encapsulation is the bundling of data (attributes) and methods (functions) that operate on that data within a single unit (class), while hiding internal implementation details from the outside world. This is achieved through access specifiers (`private`, `protected`, `public`).

**Implementation in Project**:

#### **Access Modifiers Used**:
- **Private**: Data members that should not be accessed directly from outside the class
  - Example: `Character::name`, `Character::health`, `Warrior::armorPoints`, `Mage::mana`
  
- **Protected**: Data members accessible by derived classes but not by external code
  - Example: `Character::name`, `Character::health` (accessible to Warrior, Mage, Archer)
  - Example: `Enemy::health`, `Enemy::attackPower` (accessible to Goblin, Orc, Dragon)
  
- **Public**: Interface methods that external code can use
  - Example: `Character::getName()`, `Character::getHealth()`, `Character::attack()`

#### **Data Hiding with Getters/Setters**:
- Attributes are accessed through controlled public methods
- Example: `Character::getHealth()`, `Character::setHealth(int hp)`
- Example: `Warrior::getArmorPoints()`, `Mage::getMana()`

**Example**:
```cpp
class Character {
private:
    int health;  // Encapsulated - cannot be accessed directly
    
public:
    int getHealth() const;  // Controlled access
    void setHealth(int hp); // Controlled modification
};
```

**Benefits**: 
- Prevents unauthorized access and modification of internal state
- Allows validation in setters
- Makes the class interface clear and stable, even if internal implementation changes
- Reduces bugs from direct state manipulation

---

### 4. 🎭 **Abstraction**

**Concept**: Abstraction is the process of hiding complex implementation details and showing only essential features. In C++, this is achieved through abstract classes (classes with pure virtual functions) and interfaces.

**Implementation in Project**:

#### **Abstract Base Class - Item**
The `Item` class serves as an abstract base class with a pure virtual function:

```cpp
class Item {
public:
    virtual void use(Character* target) = 0;  // Pure virtual - MUST be overridden
    virtual void displayInfo() const;         // Virtual - can be overridden
};
```

**Characteristics**:
- Contains at least one pure virtual function (`= 0` syntax)
- Cannot be instantiated directly - `Item item;` would cause a compilation error
- Forces derived classes (`Weapon`, `Potion`) to implement the `use()` method
- Provides a common interface for all item types

**Concrete Implementations**:
- `Weapon::use()` - Implements weapon-specific behavior (boosts attack power)
- `Potion::use()` - Implements potion-specific behavior (restores health)

**Benefits**:
- Defines a contract that all derived classes must follow
- Ensures consistent interface across different item types
- Allows polymorphic behavior through base class pointers
- Simplifies code that works with items - code using `Item*` pointers doesn't need to know specific item types

**Example Usage**:
```cpp
Item* item1 = new Weapon("Sword", "A sharp blade", 10);
Item* item2 = new Potion("Health Potion", "Restores health", 50);
// Both can be used polymorphically through Item pointer
```

---

### 5. 🧩 **Composition**

**Concept**: Composition is a "has-a" or "part-of" relationship where a class contains objects of other classes as member variables. It represents a stronger relationship than aggregation and is fundamental to building complex systems from simpler parts.

**Implementation in Project**:

#### **Game Class Composition**:
```cpp
class Game {
private:
    Character* player;      // Game HAS-A Character
    Inventory* inventory;   // Game HAS-A Inventory
    // ... other members
};
```
- The `Game` class contains a `Character` object (the player)
- The `Game` class contains an `Inventory` object
- `Game` manages the lifecycle of these objects (creation, destruction)

#### **Inventory Class Composition**:
```cpp
class Inventory {
private:
    std::vector<Item*> items;  // Inventory HAS-A collection of Items
    int maxCapacity;
};
```
- The `Inventory` class contains a collection of `Item` objects
- Items are stored in a `std::vector<Item*>`, allowing multiple items
- Inventory manages items (add, remove, use, display)

#### **Character-Item Relationship**:
- Characters use items through composition (items are separate objects)
- Items can affect character state when used
- Items exist independently but interact with characters

**Benefits**:
- Promotes code reuse without inheritance
- Allows flexible system design
- Easier to modify - can change inventory without changing character
- Supports building complex objects from simpler components

---

### 6. 🔄 **Method Overriding**

**Concept**: Method overriding occurs when a derived class provides a specific implementation of a method that is already defined in its base class. In C++, this uses the `override` keyword (C++11+) for clarity and safety.

**Implementation in Project**:

#### **Override Examples**:

**Character Class Hierarchy**:
- `Character::attack()` - Base implementation
- `Warrior::attack()` - Overridden with armor-enhanced attack
- `Mage::attack()` - Overridden with magical attack
- `Archer::attack()` - Overridden with ranged attack

- `Character::takeDamage()` - Base implementation
- `Warrior::takeDamage()` - Overridden to account for armor reduction

- `Character::displayStats()` - Base implementation
- `Warrior::displayStats()` - Overridden to show armor points
- `Mage::displayStats()` - Overridden to show mana
- `Archer::displayStats()` - Overridden to show arrows

**Enemy Class Hierarchy**:
- `Enemy::attack()` - Overridden in each enemy type with unique behavior
- `Enemy::displayInfo()` - Overridden to show enemy-specific information

**Item Class Hierarchy**:
- `Item::use()` - Pure virtual, must be overridden
- `Weapon::use()` - Overridden to modify character's attack power
- `Potion::use()` - Overridden to restore character's health

**Example**:
```cpp
class Character {
public:
    virtual void attack(Character* target);
};

class Warrior : public Character {
public:
    void attack(Character* target) override;  // Explicit override
};
```

**Benefits**: 
- Allows derived classes to customize base class behavior
- Enables polymorphic behavior
- `override` keyword provides compile-time safety (compiler checks if method exists in base class)

---

### 7. 🛡️ **Virtual Destructor**

**Concept**: A virtual destructor ensures that when an object is deleted through a base class pointer, the correct destructor (derived class destructor) is called, preventing memory leaks and ensuring proper cleanup.

**Implementation in Project**:

All base classes use virtual destructors:
```cpp
class Character {
public:
    virtual ~Character();  // Virtual destructor
};

class Enemy {
public:
    virtual ~Enemy();      // Virtual destructor
};

class Item {
public:
    virtual ~Item();       // Virtual destructor
};
```

**Why It's Important**:
- When deleting through base pointer: `Character* player = new Warrior("Hero"); delete player;`
- Without virtual destructor: Only `Character` destructor would be called
- With virtual destructor: First `Warrior` destructor is called, then `Character` destructor

**Benefits**:
- Prevents memory leaks
- Ensures proper resource cleanup
- Critical when using polymorphism with dynamic memory allocation

---

### 8. 🔐 **Access Control and Data Protection**

**Concept**: C++ provides three access levels (`private`, `protected`, `public`) to control visibility and access to class members.

**Implementation in Project**:

#### **Private Members**:
- Internal implementation details not accessible outside the class
- Example: `Warrior::shieldBlockActive`, `Mage::mana`, `Inventory::maxCapacity`

#### **Protected Members**:
- Accessible to derived classes but not to external code
- Example: `Character::name`, `Character::health`, `Enemy::attackPower`
- Allows derived classes to access base class members while maintaining encapsulation

#### **Public Members**:
- Interface methods accessible to all code
- Example: `Character::attack()`, `Character::getName()`, `Inventory::addItem()`

**Benefits**:
- Enforces information hiding
- Protects internal state from unauthorized access
- Provides clear public API
- Supports maintainability and extensibility

---

### 9. 📋 **Constructors and Destructors**

**Concept**: Constructors initialize objects when created, and destructors clean up when objects are destroyed. This ensures proper resource management.

**Implementation in Project**:

#### **Constructor Chaining**:
- Base class constructors are called before derived class constructors
- Example: `Warrior` constructor calls `Character` constructor first

#### **Destructor Chain**:
- Derived class destructors are called before base class destructors
- Virtual destructors ensure correct order when deleting through base pointers

**Example**:
```cpp
Warrior::Warrior(std::string name) : Character(name, 120, 18) {
    // Character constructor called first
    // Then Warrior-specific initialization
    armorPoints = 10;
    shieldBlockActive = false;
}
```

---

### 10. 🎯 **Forward Declarations**

**Concept**: Forward declarations allow referencing a class before it's fully defined, breaking circular dependencies and reducing compilation dependencies.

**Implementation in Project**:

```cpp
class Character; // Forward declaration
class Enemy;     // Forward declaration

class Enemy {
    void attack(Character* target);  // Uses forward declaration
};
```

**Benefits**:
- Reduces compilation dependencies
- Breaks circular dependencies
- Faster compilation times
- Cleaner header files

---

## 📊 OOP Concept Summary

| OOP Concept | Implementation Example | Files Involved |
|------------|----------------------|----------------|
| **Inheritance** | `Warrior : public Character` | Character.h, Warrior.h, Mage.h, Archer.h |
| **Polymorphism** | Virtual `attack()` methods | Character.cpp, Warrior.cpp, Mage.cpp, Archer.cpp |
| **Encapsulation** | Private members + public getters | All class headers |
| **Abstraction** | Pure virtual `Item::use()` | Item.h, Weapon.h, Potion.h |
| **Composition** | `Game` contains `Character*` and `Inventory*` | Game.h, Inventory.h |
| **Method Overriding** | `Warrior::attack()` overrides `Character::attack()` | All derived classes |
| **Virtual Destructor** | `virtual ~Character()` | All base classes |
| **Access Control** | `private`, `protected`, `public` | All class headers |
| **Constructors/Destructors** | Initialization and cleanup | All class files |
| **Forward Declarations** | `class Character;` | Multiple headers |

---

## 🎓 Educational Value

This project serves as an excellent learning resource for understanding OOP principles because:

1. **Real-World Application**: OOP concepts are demonstrated in a practical, engaging game rather than abstract examples
2. **Clear Separation**: Each concept is clearly visible and isolated in specific class hierarchies
3. **Best Practices**: Follows C++ best practices (virtual destructors, `override` keyword, access control)
4. **Complete Coverage**: Demonstrates all major OOP concepts in a single cohesive project
5. **Extensible Design**: Easy to add new features (new character classes, items, enemies) without breaking existing code

---

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
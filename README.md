# CPP Module 03 – Inheritance

This module focuses on C++ inheritance. You’ll learn how to create and extend classes, how to chain constructors/destructors, and even explore multiple inheritance. Through four exercises, you will build a hierarchy of robot-like classes: starting with a base class (`ClapTrap`), and then extending it with `ScavTrap`, `FragTrap`, and finally merging behaviors in a multiple-inheritance monster called `DiamondTrap`.

*(Subject reference: citeturn4file0)*

---

## Table of Contents

- [Introduction & Overview](#introduction--overview)
- [Key Inheritance Concepts](#key-inheritance-concepts)
- [Exercise 00: Aaaaand... OPEN!](#exercise-00-aaaand-open)
- [Exercise 01: Serena, my love!](#exercise-01-serena-my-love)
- [Exercise 02: Repetitive work](#exercise-02-repetitive-work)
- [Exercise 03: Now it’s weird!](#exercise-03-now-its-weird)
- [Conclusion](#conclusion)

---

## Introduction & Overview

In this module, you build a family of robot classes that demonstrate real-world uses of inheritance. You start with a simple base class—`ClapTrap`—which encapsulates basic characteristics (name, hit points, energy, and attack damage) and actions (attack, take damage, and repair). Later, you derive new classes from `ClapTrap` that customize these attributes and behaviors to create more specialized robots. Finally, you experiment with multiple inheritance in the creation of `DiamondTrap`, which combines behaviors from both `FragTrap` and `ScavTrap`.

---

## Key Inheritance Concepts

### Inheritance Hierarchy & Constructor Chaining

- **Inheritance** lets derived classes reuse and extend the functionality of a base class.
- **Constructor Chaining** ensures that when a derived class object is created, the base class sub-object is created first. This is crucial for correctly initializing attributes.
- **Destruction Order** is the reverse of construction order: the derived class destructor is called first, followed by the base class destructor.

### Overriding and Specialization

- Derived classes can override base class methods to provide specialized behavior.
- In our exercises, the `attack()` method is overridden to print different messages that reflect the character of the robot (for example, ScavTrap vs. FragTrap).

### Multiple Inheritance

- **Multiple Inheritance** allows one class to inherit features from more than one base class. However, this requires careful handling of ambiguities.
- In `DiamondTrap`, you will see how data members and methods from multiple parents are combined, and how you can control which implementation to use (for example, selecting the attack method from ScavTrap).

---

## Exercise 00: Aaaaand... OPEN!

### Objective

Implement the base class **ClapTrap**. This class represents a simple robot with the following attributes:
- **Name** (provided via constructor)
- **Hit Points** (initially 10)
- **Energy Points** (initially 10)
- **Attack Damage** (initially 0)

It must also provide three public methods:
- `attack(const std::string &target);`
- `takeDamage(unsigned int amount);`
- `beRepaired(unsigned int amount);`

Each action must print a message that details what happens (e.g., when a ClapTrap attacks, it prints its name, target, and damage).

### Example Code

**ClapTrap.hpp**
```cpp
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
```

**ClapTrap.cpp**
```cpp
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap copy constructor called." << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;  // Each attack costs one energy point
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints = (amount >= hitPoints ? 0 : hitPoints - amount);
    std::cout << "ClapTrap " << name << " takes " << amount 
              << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " is repaired by " << amount 
                  << " points!" << std::endl;
    }
}
```

### Explanation

- **Encapsulation:**  
  The data members are `protected` so that derived classes can reuse them.
- **Method Behavior:**  
  Each method checks if the ClapTrap can act (has energy or remaining hit points) before changing state.
- **Output Messages:**  
  Messages in constructors, destructors, and methods help track object lifecycle and actions during testing.

---

## Exercise 01: Serena, my love!

### Objective

Create a derived class **ScavTrap** from ClapTrap. A ScavTrap represents an upgraded robot with different default attribute values and an additional special action.

### Requirements

- Inherit from ClapTrap.
- Initialize with new default values:
  - **Hit Points:** 100
  - **Energy Points:** 50
  - **Attack Damage:** 20
- Implement a special function: `guardGate();` which prints that the ScavTrap is in "Gate keeper" mode.
- Modify the `attack()` method to print a message that distinguishes it from the base class.

### Example Code

**ScavTrap.hpp**
```cpp
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif
```

**ScavTrap.cpp**
```cpp
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap copy assignment operator called." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ScavTrap " << name << " aggressively attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
```

### Explanation

- **Constructor Chaining:**  
  The ScavTrap constructor calls the ClapTrap constructor to set the name and then customizes the inherited attributes.
- **Special Ability:**  
  The `guardGate()` function provides behavior unique to ScavTrap.
- **Overriding:**  
  The `attack()` method is overridden to display a ScavTrap-specific message.

---

## Exercise 02: Repetitive work

### Objective

Implement the **FragTrap** class, a second derivative of ClapTrap. FragTrap has yet another set of default values and a unique special action.

### Requirements

- Inherit from ClapTrap.
- Initialize with different attributes:
  - **Hit Points:** 100
  - **Energy Points:** 100
  - **Attack Damage:** 30
- Implement a special function: `highFivesGuys();` which prompts a high-five.

### Example Code

**FragTrap.hpp**
```cpp
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();

    void attack(const std::string &target);
    void highFivesGuys(void);
};

#endif
```

**FragTrap.cpp**
```cpp
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap copy assignment operator called." << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "FragTrap " << name << " launches an attack on " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
```

### Explanation

- **Attribute Customization:**  
  FragTrap redefines the base attributes to reflect its role.
- **Unique Behavior:**  
  `highFivesGuys()` displays a message that distinguishes FragTrap from other derived classes.
- **Reusing Base Implementation:**  
  Most common functionality is inherited from ClapTrap, reducing code duplication.

---

## Exercise 03: Now it’s weird!

### Objective

Implement **DiamondTrap**, a class that combines aspects of both FragTrap and ScavTrap through multiple inheritance. This exercise requires careful handling of inherited attributes and methods.

### Requirements

- **DiamondTrap** should:
  - Inherit from both FragTrap and ScavTrap.
  - Have its own private attribute `name` (exactly the same as the base ClapTrap’s variable name, but used exclusively in DiamondTrap).
  - When constructed, initialize the ClapTrap part of the object with `<DiamondTrap's name>_clap_name`.
  - Use the following default attribute sources:
    - **Hit Points:** From FragTrap.
    - **Energy Points:** From ScavTrap.
    - **Attack Damage:** From FragTrap.
  - Use ScavTrap’s implementation of the `attack()` method.
  - Include a special method `whoAmI()` that prints both its own name and its ClapTrap name.

### Example Code

**DiamondTrap.hpp**
```cpp
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name; // DiamondTrap's own name
public:
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void whoAmI();
    // Inherit attack() from ScavTrap
};

#endif
```

**DiamondTrap.cpp**
```cpp
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    // Note: The ClapTrap constructor is explicitly called with the modified name.
    // FragTrap and ScavTrap constructors further initialize other attributes.
    std::cout << "DiamondTrap " << this->name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other.name + "_clap_name"), FragTrap(other), ScavTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        // Assign members as needed. Note: assignment in multiple inheritance must be handled carefully.
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "DiamondTrap copy assignment operator called." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    // Outputs its own name and its ClapTrap name.
    std::cout << "DiamondTrap name: " << name 
              << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
```

### Explanation

- **Multiple Inheritance:**  
  DiamondTrap inherits from both FragTrap and ScavTrap. Notice the call to the ClapTrap constructor with a modified name (`<DiamondTrap's name>_clap_name`) to resolve ambiguities.
- **Attribute Selection:**  
  DiamondTrap uses FragTrap’s hit points and attack damage while adopting ScavTrap’s energy and `attack()` method.
- **Special Behavior:**  
  The `whoAmI()` method demonstrates how to access data from both its own class and its base class.

---

## Conclusion

Happy coding!

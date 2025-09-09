# CPP Module 03

## Inheritance

This module focuses on C++ inheritance. You’ll learn how to create and extend classes, how to chain constructors/destructors, and even explore multiple inheritance. Through four exercises, you will build a hierarchy of robot-like classes: starting with a base class (`ClapTrap`), and then extending it with `ScavTrap`, `FragTrap`, and finally merging behaviors in a multiple-inheritance monster called `DiamondTrap`.

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

## Overview

In this module, you build a family of robot classes that demonstrate real-world uses of inheritance. You start with a simple base class—`ClapTrap`—which encapsulates basic characteristics (name, hit points, energy, and attack damage) and actions (attack, take damage, and repair). Later, you derive new classes from `ClapTrap` that customize these attributes and behaviors to create more specialized robots. Finally, you experiment with multiple inheritance in the creation of `DiamondTrap`, which combines behaviors from both `FragTrap` and `ScavTrap`.

---

## Inheritance Concepts

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

### Explanation

- **Multiple Inheritance:**  
  DiamondTrap inherits from both FragTrap and ScavTrap. Notice the call to the ClapTrap constructor with a modified name (`<DiamondTrap's name>_clap_name`) to resolve ambiguities.
- **Attribute Selection:**  
  DiamondTrap uses FragTrap’s hit points and attack damage while adopting ScavTrap’s energy and `attack()` method.
- **Special Behavior:**  
  The `whoAmI()` method demonstrates how to access data from both its own class and its base class.

---

Happy coding and hope to see you for the next project's explanation

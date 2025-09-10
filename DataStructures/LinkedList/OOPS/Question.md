# Employee Management System - C++ (OOP Concepts)

## Problem Statement
Design a C++ program to manage different types of employees in a company using all four pillars of Object-Oriented Programming (OOP).

---

## Requirements

### 1. Abstract Class: `Employee` (Base Blueprint)
- **Protected Data Members**:
  - `name` (string)
  - `id` (int)
- **Constructor**:
  - Initializes the above members.
- **Pure Virtual Function**:
  - `calculateSalary()` to be implemented by derived classes.
- **Virtual Function**:
  - `displayInfo()` to show employee details.
- **Copy Constructor**:
  - Creates a duplicate of an employee object.

---

### 2. Derived Classes

#### `FullTimeEmployee` (Public Inheritance)
- **Private Member**:
  - `monthlySalary` (double)
- **Implements**:
  - `calculateSalary()` → returns monthly salary.

#### `PartTimeEmployee` (Protected Inheritance)
- **Private Members**:
  - `hourlyRate` (double)
  - `hoursWorked` (int)
- **Implements**:
  - `calculateSalary()` → returns `hourlyRate * hoursWorked`.

---

### 3. Encapsulation
- All data members must be `private` or `protected`.
- Provide **getters/setters** where needed.

---

### 4. Polymorphism
- Use a **base class pointer** to call `calculateSalary()` and `displayInfo()` for different employee types at runtime.

---

### 5. Inheritance
- Demonstrate **public** and **protected** inheritance.

---

### 6. Abstraction
- The `Employee` class must be **abstract**.

---

### 7. Main Function
1. Create objects of `FullTimeEmployee` and `PartTimeEmployee`.
2. Use the **copy constructor** to clone an object.
3. Store pointers to both in an array/vector of `Employee*`.
4. Display their details and calculated salary using **runtime polymorphism**.

---


# 🏦 Bank Client & User Management System

A comprehensive Command-Line Interface (CLI) application built entirely in C++ that simulates a core banking system. Utilizing a Flat-File Database approach, it ensures reliable data persistence and state management without external database dependencies.

Developed as the capstone project for Course 7 of the C++ foundational roadmap, it demonstrates a practical implementation of structural programming, memory management, file handling, and advanced bitwise access control.

## 🚀 Key Features

* **User Management & Security:** Role-based access control (RBAC) using bitwise operations to grant or restrict user permissions for specific system screens and features.
* **Financial Transactions:** Secure deposit and withdrawal mechanics with real-time balance validation, plus a comprehensive system-wide "Total Balances" dashboard.
* **Core CRUD Operations:**
  * **Create:** Register new clients or system users with built-in smart validation to prevent duplicate primary keys.
  * **Read:** Fetch and render client records in cleanly formatted, responsive tabular layouts.
  * **Update:** Modify client details or user passwords/permissions on the fly, instantly syncing changes to the physical text files.
  * **Delete:** Employs a "Logical Deletion" (Mark for Delete) mechanism to safely isolate records before re-syncing the database.
  * **Find:** Quick query system utilizing Account Numbers or Usernames to retrieve full entity details.

## 🛠️ Technologies & Core Concepts

* **Language:** C++
* **Data Structures:** `Structs` for modeling data entities and `std::vector` for dynamic memory allocation and real-time state management.
* **File Handling & Serialization:** Extensive use of `<fstream>`, coupled with custom string manipulation (Split/Join) using a unique `#//#` delimiter to parse raw text lines into usable objects.
* **Access Control Logic:** Implementation of Bitwise operators for efficient, single-integer permission tracking and validation.
* **Defensive Programming:** Robust error handling (`cin.fail()`, `cin.ignore()`) to prevent infinite loops, system crashes, and invalid numeric inputs.
* **Clean Architecture:** Modular code design featuring single-responsibility functions and `Enums` for precise menu state routing.

## 💻 How to Run

Clone the repository to your local machine:
```bash
git clone [https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git](https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git)

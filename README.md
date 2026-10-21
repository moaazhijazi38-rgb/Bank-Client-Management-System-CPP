# Bank Client Management System

A secure, modular, and feature-rich banking management system developed in C++ using object-oriented programming (OOP) principles. This project simulates a real-world banking environment where users can manage customer accounts, perform transactions, handle permissions, and work with multi-currency financial operations — all through a console-based user interface.

Built as a practical software engineering project, it focuses on clean architecture, maintainability, and separation of concerns by dividing the application into logical modules such as `Core`, `Lib`, and `Screens`.

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-Modern%20OOP-00599C?logo=c%2B%2B&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Architecture-Console%20App-512BD4" alt="Console App" />
  <img src="https://img.shields.io/badge/Storage-Text%20Files-4B8BBE" alt="Text Files" />
  <img src="https://img.shields.io/badge/Status-Portfolio%20Project-28A745" alt="Portfolio" />
</p>

## Overview

The Bank Client Management System is designed to provide a complete banking workflow in a simplified yet realistic manner. It allows administrators and authorized users to:

- Manage customer records
- Handle user authentication and authorization
- Perform deposits, withdrawals, and transfers
- Track transaction history
- Manage currency conversion
- Navigate a structured console-based screen system

The project is intentionally organized into separate layers to improve scalability and make it easier to extend functionality over time.

---

## Key Features

- 🔐 **Secure login system** with role-based permissions and login history tracking.
- 👤 **Complete customer management:** Add, update, delete, search, and list customers.
- 🧑‍💼 **Full user management:** Create users, modify data, and enforce access control.
- 💰 **Banking operations:** Deposit, withdraw, quick withdraw, internal transfer, and detailed transfer log.
- 💱 **Currency system:** View available currencies, search currencies, and convert amounts using the currency calculator.
- 🖥️ **Console UI** with organized screen-based navigation.
- 🧩 **Modular architecture** using OOP concepts.
- 📝 **Persistent data storage** using structured text files.

---

## Architecture & Folder Structure

The project is organized into separate physical folders to keep the codebase clean and easy to maintain:

<pre>
Bank-Client-Management-System-CPP/
├── Core/
│   └── clsBankClient (Client, User, and Currency core logic)
├── Lib/
│   ├── clsDate (Date and time utilities)
│   └── clsInputValidate (Input validation and verification)
├── Screens/
│   ├── Client Screens (clsClientListScreen, clsAddNewClientScreen, clsDeleteClientScreen, clsUpdateClientScreen, clsFindClientScreen)
│   ├── User Screens (clsListUsersScreen, clsAddNewUserScreen, clsDeleteUserScreen, clsFindUserScreen)
│   ├── Transaction Screens (clsDepositeScreen, clsWithdrawScreen, clsTransferLogScreen)
│   └── Currency Screens (clsCurrenciesListScreen, clsFindCurrencyScreen, clsCurrencyCalculatorScreen)
├── Global.h (Global session state and current user management)
├── Data Files/
│   ├── MyFile.text (Client records)
│   ├── Users.text (System users & permissions)
│   ├── LoginRegister.text (Login history logs)
│   ├── Transfer.text (Balance transfer logs)
│   └── Currencies.txt (Exchange rates database)
├── Project1.vcxproj (Visual Studio Project File)
└── README.md
</pre>

### Folder & File Responsibilities
- **`Core/`**: Contains the main business logic and domain models of the application, including client operations, user authentication, permissions, and currency processing.
- **`Lib/`**: Stores reusable utility classes (`clsDate`, `clsInputValidate`, string helpers) used across the entire project.
- **`Screens/`**: Contains the console interface screens. Each class manages a specific view or operation in the system.
- **`Global.h`**: Holds the active user session across different screens.
- **Data Text Files (`.text` / `.txt`)**: Act as the persistent storage layer for clients, users, login registers, transfers, and currencies.

---

## Tech Stack

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP — Inheritance, Encapsulation, Abstraction)
- **Libraries:** Standard Template Library (STL — `std::vector`, `std::string`, `fstream`)
- **Interface:** Windows Console UI
- **Data Storage:** Flat-file persistence (Text files)
- **IDE:** Microsoft Visual Studio

---

## Getting Started

### Prerequisites
- Windows OS
- Visual Studio (with **Desktop development with C++** workload installed)

### How to Run in Visual Studio
1. Download or clone the repository to your local machine:
   <pre>git clone https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git</pre>
2. Open **Visual Studio**.
3. Click on **Open a project or solution** and select **`Project1.vcxproj`**.
4. Ensure all data files (`MyFile.text`, `Users.text`, `Currencies.txt`, `Transfer.text`, `LoginRegister.text`) are in the project directory.
5. Build the project (`Ctrl + Shift + B`) and run it (`Ctrl + F5`).

---

## Contact

If you want to connect, collaborate, or discuss software engineering ideas:
- **GitHub:** [@moaazhijazi38-rgb](https://github.com/moaazhijazi38-rgb)

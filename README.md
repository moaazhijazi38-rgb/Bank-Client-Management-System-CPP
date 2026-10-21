# Bank Client Management System

A console-based banking management system developed in C++ using Object-Oriented Programming (OOP) principles. This project simulates a banking environment where authorized users can manage client accounts, perform financial transactions, handle user permissions, and use a currency calculator through an organized screen-based console interface.

## Overview

The system provides a complete banking workflow divided into logical folders (`Core`, `Lib`, and `Screens`) to separate the console interface from the core classes and utility libraries.

---

## Key Features

- **Login & Permissions System:** User authentication with access control for different screens and operations (`Global.h`).
- **Client Management:**
  
  - Add new client (`clsAddNewClientScreen`)
  - Delete client (`clsDeleteClientScreen`)
  - Update client info (`clsUpdateClientScreen`)
  - Find client (`clsFindClientScreen`)
  - List all clients (`clsClientListScreen`)
    
- **User Management:**
  - Add new user (`clsAddNewUserScreen`)
  - Delete user (`clsDeleteUserScreen`)
  - Find user (`clsFindUserScreen`)
  - List users (`clsListUsersScreen`)
    
- **Banking Transactions:**
  - Deposit funds (`clsDepositeScreen`)
  - Withdraw funds (`clsWithdrawScreen`)
  - Transfer balances between accounts and view transfer history (`clsTransferLogScreen`)
    
- **Currency Exchange System:**
  - List available currencies (`clsCurrenciesListScreen`)
  - Find currency (`clsFindCurrencyScreen`)
  - Currency calculator for conversions (`clsCurrencyCalculatorScreen`)

---

## Project Structure

- **Core:** Contains the core banking classes and data models (such as `clsBankClient` and user/currency management classes).
- **Lib:** Contains reusable utility and helper classes such as `clsDate` and `clsInputValidate`.
- **Screens:** Contains the console UI screens for navigating menus and handling operations.
- **Data Text Files:** Stores persistent application data directly in text files:
  - `MyFile.text` (Clients data)
  - `Users.text` (System users and permissions)
  - `LoginRegister.text` (Login history records)
  - `Transfer.text` (Transfer logs)
  - `Currencies.txt` (Exchange rates data)
- **Project File:** `Project1.vcxproj` (Visual Studio C++ Project).

---

## Built With

- **C++** (Object-Oriented Programming - OOP)
- **Standard Template Library (STL)** (`std::vector`, `std::string`, `fstream`)
- **Visual Studio** (Windows Console Application)

---

## How to Run the Project

1. Download or clone the repository files to your computer.
2. Open **Visual Studio**.
3. Open the project file `Project1.vcxproj`.
4. Build and run the project using `Ctrl + F5`.

---

## Author

- **GitHub:** [moaazhijazi38-rgb](https://github.com/moaazhijazi38-rgb)

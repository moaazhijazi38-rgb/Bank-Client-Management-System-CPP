# Bank Client Management System

A secure, modular, and feature-rich banking management system developed in C++ using object-oriented programming (OOP) principles. This project simulates a real-world banking environment where users can manage customer accounts, perform transactions, handle permissions, and work with multi-currency financial operations — all through a console-based user interface.

Built as a practical software engineering project, it focuses on clean architecture, maintainability, and separation of concerns by dividing the application into logical modules such as `Core`, `Lib`, and `Screens`.

<p align="center">
  <img src="[https://img.shields.io/badge/C%2B%2B-Modern%20OOP-00599C?logo=c%2B%2B&logoColor=white](https://img.shields.io/badge/C%2B%2B-Modern%20OOP-00599C?logo=c%2B%2B&logoColor=white)" alt="C++" />
  <img src="[https://img.shields.io/badge/Architecture-Console%20App-512BD4](https://img.shields.io/badge/Architecture-Console%20App-512BD4)" alt="Console App" />
  <img src="[https://img.shields.io/badge/Storage-Text%20Files-4B8BBE](https://img.shields.io/badge/Storage-Text%20Files-4B8BBE)" alt="Text Files" />
  <img src="[https://img.shields.io/badge/Status-Portfolio%20Project-28A745](https://img.shields.io/badge/Status-Portfolio%20Project-28A745)" alt="Portfolio" />
</p>

---

## Overview

The Bank Client Management System is designed to provide a complete banking workflow in a simplified yet realistic manner. It allows administrators and authorized users to:

- Manage customer records
- Handle user authentication and authorization
- Perform deposits, withdrawals, and transfers
- Track transaction history
- Manage currency conversion
- Navigate a structured console-based screen system

---

## Key Features

- 🔐 **Secure login system** with role-based permissions
- 👤 **Complete customer management:**
  - Add customer
  - Update customer information
  - Delete records
  - Search by ID or name
  - Display customer list
- 🧑‍💼 **Full user management:**
  - Create users
  - Modify user data
  - Manage accounts
  - Enforce access control
- 💰 **Banking operations:**
  - Deposit funds
  - Withdraw funds
  - Quick withdrawal
  - Internal balance transfer
  - Detailed transfer log
- 💱 **Currency system:**
  - View available currencies
  - Search currencies
  - Perform currency conversion calculations
- 🖥️ **Console UI** with organized screen-based navigation
- 🧩 **Modular architecture** using OOP concepts
- 📝 **Persistent data storage** using text files

---

## Architecture & Folder Structure

The project is organized into separate folders to keep the system structured and easy to maintain:

```text
Bank-Client-Management-System-CPP/
├── Core/
├── Lib/
├── Screens/
├── README.md
└── Project1.vcxproj
```

### Folder Responsibilities
- **Core:** Contains the main business logic of the application, including client management, user authentication, permissions, transactions, and currency management.
- **Lib:** Stores reusable utility functions (`clsUtil`), date handling (`clsDate`), string operations (`clsString`), and input validation (`clsInputValidate`).
- **Screens:** Contains the screen-driven console interface. Each screen represents a specific module or function, such as login, main dashboard, client management, or banking operations.

---

## Tech Stack

- **C++** (Object-Oriented Programming - OOP)
- **Standard Template Library (STL)** (`std::vector`, `std::string`, `fstream`)
- **Console-based UI**
- **Text file persistence**
- **Modular architecture** & **Role-based access control**

---

## Getting Started

### Prerequisites
- Windows OS
- Visual Studio 2019 or later (with C++ desktop development workload installed)

### Clone the Repository
```bash
git clone https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git
cd Bank-Client-Management-System-CPP
```

### Open and Run in Visual Studio
1. Open **Visual Studio**.
2. Click on **Open a project or solution**.
3. Select the project/solution file from the folder.
4. Build the solution (`Ctrl + Shift + B`).
5. Run the program (`Ctrl + F5`).

---

## Future Improvements

- 🗄️ Integrate **SQLite** instead of text files for structured and efficient data storage.
- 🔒 Add **password hashing** (e.g., SHA-256 / bcrypt) for secure authentication.
- 🛡️ Improve **error handling** (`try/catch`) and strict input validation.
- 🔄 Implement transactional rollback safety for balance transfers.

---

## Contact

If you want to connect, collaborate, or discuss software engineering ideas:
- **GitHub:** [@moaazhijazi38-rgb](https://github.com/moaazhijazi38-rgb)

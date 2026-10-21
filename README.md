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

The project is organized into separate folders to keep the system structured and easy to maintain.

```text
Bank-Client-Management-System-CPP/
├── Core/
│   ├── Authentication/
│   ├── Banking/
│   └── Data/
├── Lib/
│   ├── Utils/
│   ├── Models/
│   └── Shared/
├── Screens/
├── Data/
├── README.md
├── .gitignore
└── solution/
    └── BankClientManagementSystem.sln
    Folder Responsibilities
Core: Contains the main business logic of the application, including authentication, account processing, transactions, and data handling.

Lib: Stores reusable utility functions, model definitions, and shared project components. This folder helps maintain clean and reusable code.

Screens: Contains the screen-driven console interface. Each screen represents a specific module or function, such as login, dashboard, customer management, or banking operations.

Data: Stores the text-based persistent files used for customer records, users, transactions, and currency data.

Tech Stack
This project is built using the following technologies and concepts:

C++ (Modern C++ programming practices)

Object-Oriented Programming (OOP)

Standard Template Library (STL)

Console-based UI

Text file persistence

Modular architecture

Getting Started
Prerequisites
Before running the project, make sure you have:

Windows OS

Visual Studio 2019 or later

C++ desktop development workload installed

Clone the Repository
Bash
git clone [https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git](https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git)
cd Bank-Client-Management-System-CPP
Open in Visual Studio
Open Visual Studio.

Click on Open a project or solution.

Select the solution file (.sln) from the project folder.

Set the project as the startup project.

Build the solution using Debug or Release configuration.

Run the program (Ctrl + F5).

Future Improvements
This project is a strong foundation, and I plan to improve it further in future iterations:

🗄️ Integrate SQLite instead of text files for structured and efficient data storage

🔒 Add password hashing and secure authentication using modern hashing algorithms

🛡️ Improve error handling and validation for invalid inputs

📊 Add transaction reporting and financial summaries

🖼️ Upgrade the UI with a richer console formatting

Screenshots
(Placeholder sections for application screenshots. Upload images to a screenshots folder and update the links below)

Login Screen: ![Login Screen](./screenshots/login-screen.png)

Main Dashboard: ![Main Dashboard](./screenshots/main-dashboard.png)

Banking Operations: ![Banking Operations](./screenshots/banking-operations.png)

Contact
If you want to connect, collaborate, or discuss software engineering ideas:

GitHub: moaazhijazi38-rgb

This project is a strong example of an engineering-focused application suitable for showcasing technical skills in C++ software development and system design.

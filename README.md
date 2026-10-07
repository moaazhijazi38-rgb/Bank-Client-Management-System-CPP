# 🏦 Bank & ATM Management System

A comprehensive Command-Line Interface (CLI) application built entirely in C++ that simulates a core banking system[cite: 1]. Utilizing a Flat-File Database approach, it ensures reliable data persistence and state management without external database dependencies[cite: 1].

## 🚀 Recent Updates
- **Added ATM System (`ATMSystem.cpp`):** A fully functional ATM interface for clients to interact with their accounts securely.
- **Shared Flat-File Database:** Both the Bank System and the ATM System now seamlessly read from and write to the same text file database. Any deposit or withdrawal made in the ATM reflects instantly in the Bank System, simulating a real-world integrated banking environment.

## ✨ Features

### 👨‍💼 Bank System (Admin Interface)
*(Handled via `BankSystem.cpp`)*
- Manage client accounts (Add, Delete, Update, Find Clients).
- View all clients and total bank balances.
- Secure access for bank employees.

### 💳 ATM System (Client Interface)
*(Handled via `ATMSystem.cpp`)*
- **Secure Login:** Authentication using Account Number and PIN Code.
- **Quick Withdraw:** Withdraw pre-defined amounts instantly.
- **Normal Withdraw:** Withdraw custom amounts (includes business rules like multiples of 5).
- **Deposit:** Add funds to the account securely.
- **Check Balance:** View the current account balance.
- **Robust Input Validation:** Complete protection against invalid inputs (e.g., entering characters instead of numbers, or negative values).

## 🛠️ Technologies & Concepts Used
- **Language:** C++
- **Data Structures:** `std::vector`, `struct`
- **Storage:** Flat-File Database using File I/O (`<fstream>`)
- **Programming Paradigm:** Procedural Programming with clean, modular functions.
- **Error Handling:** Advanced input validation and stream clearing (`cin.fail()`, `cin.clear()`, `cin.ignore()`).

## ⚙️ How to Run

1. **Database Setup:** Ensure the text database file (e.g., `MyFile.text` or `Clients.txt`) is in the same directory as your executables.
2. **Bank Interface:** Compile and run `BankSystem.cpp` to manage clients as an admin.
3. **ATM Interface:** Compile and run `ATMSystem.cpp` to simulate a client logging into an ATM.

---
*Built with ❤️ using C++*

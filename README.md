# 🏦 Bank Client Management System

A comprehensive Bank Client Management System built entirely in **C++**. This Command-Line Interface (CLI) application relies on a Flat-File Database approach for data persistence, managing client records efficiently without external database dependencies. 

Developed as the final capstone project for Course 7 of the C++ foundational roadmap, it serves as a practical implementation of structural programming, memory management, and file handling.

---

## 🚀 Key Features (CRUD Operations)
* **Create (Add Clients):** Input client details (Account Number, PIN, Name, Phone, Balance) with built-in smart validation to prevent duplicate account numbers.
* **Read (Display Data):** Fetch all client records from the text file and render them in a clean, strictly formatted tabular layout.
* **Update (Modify Records):** Search for a specific client and overwrite their information, instantly rewriting the text file to save changes.
* **Delete (Remove Clients):** Utilizes a "Logical Deletion" (Mark for Delete) mechanism to safely isolate and remove client records before re-syncing with the physical file.
* **Find (Search):** Quick query system to retrieve and display full details of any client using their Account Number as a primary key.

---

## 🛠️ Technologies & Core Concepts
* **Language:** C++
* **File Handling:** Extensive use of the `<fstream>` library for reliable File I/O operations.
* **Data Structures:** Utilizing `Structs` to model data entities and `std::vector` for dynamic memory allocation and real-time state management.
* **Data Serialization:** Implementing custom string manipulation (Split/Join) using a unique delimiter (`#//#`) to parse raw text lines into usable objects and vice versa.
* **Defensive Programming:** Robust error handling for invalid user inputs (utilizing `cin.fail()` and `cin.ignore()`) to prevent infinite loops and system crashes.
* **Clean Architecture:** Modular code design featuring single-responsibility functions and `Enums` for precise menu state routing.

---

## 💻 How to Run
1. Clone the repository to your local machine:
   ```bash
   git clone [https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git](https://github.com/moaazhijazi38-rgb/Bank-Client-Management-System-CPP.git)

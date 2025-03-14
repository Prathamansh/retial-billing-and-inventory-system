# Inventory and Billing System

## Overview
This is a console-based **Inventory and Billing System** developed in C++ for managing items, generating bills, and performing basic inventory operations. The program allows users to add, display, edit, and delete items, as well as generate bills based on available stock. It uses file handling to persistently store item data in a text file (`items.txt`) and includes predefined sample data for testing.

The system is designed for small-scale inventory management, such as in a store or shop, and provides a simple interface for tracking items and calculating costs with tax and discounts.

---

## Features
1. **Add Item**: Add a new item to the inventory with details like item number, name, manufacturing date, price, quantity, tax, and discount.
2. **Display Items**: View all items currently stored in the inventory with their details.
3. **Edit Item**: Modify the details of an existing item by providing its item number.
4. **Delete Item**: Remove an item from the inventory using its item number.
5. **Generate Bill**: Create a bill by selecting items and specifying quantities, with automatic stock updates and total amount calculation.
6. **Persistent Storage**: Item data is saved to `items.txt` and loaded automatically when the program starts.
7. **Predefined Data**: Includes 10 sample items for immediate use upon first run.

---

## Requirements
- **Operating System**: Windows (due to the use of `windows.h` and console cursor functions like `gotoxy`).
- **Compiler**: Any C++ compiler supporting standard libraries (e.g., GCC, MSVC).
- **Libraries**: Standard C++ libraries (`iostream`, `fstream`, `vector`, etc.) and Windows-specific headers (`windows.h`, `conio.h`).

---

## How to Use
### Setup
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/your-repo-name.git

# Inventory and Billing System

## Overview
This is a console-based **Inventory and Billing System** developed in C++ for managing items, generating bills, and performing basic inventory operations. The program allows users to:
- Add, display, edit, and delete items.
- Generate bills based on available stock.
- Persistently store item data using file handling.

This system is ideal for small-scale inventory management in retail shops and provides a simple interface for tracking items and calculating costs, including tax and discounts.

---

## Features
✅ **Add Item** – Add new items with details (item number, name, date, price, quantity, tax, discount).  
✅ **Display Items** – View all stored inventory items with details.  
✅ **Edit Item** – Modify existing item details by item number.  
✅ **Delete Item** – Remove an item from inventory.  
✅ **Generate Bill** – Create a bill, update stock, and calculate total amount.  
✅ **Persistent Storage** – Item data is saved in `items.txt` and auto-loaded on startup.  
✅ **Predefined Sample Data** – Comes with 10 sample items for immediate use.

---

## Requirements
- **Operating System**: Windows (due to `windows.h` usage)
- **Compiler**: Any C++ compiler (GCC, MSVC, etc.)
- **Libraries**: Standard C++ libraries (`iostream`, `fstream`, `vector`, etc.), Windows-specific headers (`windows.h`, `conio.h`).

---

## How to Use
### **Setup**
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Prathamansh/retial-billing-and-inventory-system.git
   ```
2. **Compile the Code** (using g++ or any C++ compiler):
   ```bash
   g++ main.cpp -o inventory_system
   ```
3. **Run the Program**:
   ```bash
   ./inventory_system.exe
   ```
4. On the first run, `items.txt` is created with 10 predefined items (if not already present).

### **Usage Instructions**
Upon running the program, the menu provides options:
- **Add Item** – Enter item details, which are stored in `items.txt`.
- **Display Items** – View all stored inventory items.
- **Edit Item** – Update item details using item number.
- **Delete Item** – Remove an item from inventory.
- **Generate Bill** – Select items, specify quantity, and generate a bill.
- **Exit** – Closes the program.

Navigation: After each operation, press any key to return to the main menu.

---

## File Structure
```
├── main.cpp  # Source code
└── items.txt # Inventory data (generated automatically)
```

### **Sample `items.txt` Format**
Each line represents an item with space-separated fields:
```
item_no name mm dd yyyy price quantity tax discount net_amount
```
Example:
```
1 Rice 01 01 2024 50 100 5 10 4500
```

---

## **Functions in the Code**
### **Utility Functions**
- `gotoxy(int x, int y)`: Moves console cursor (Windows-specific).

### **Item Class Methods**
- `add()`: Inputs item details.
- `calculate()`: Computes the net amount.
- `show()`: Displays item details.
- `saveToFile()`: Writes item data to `items.txt`.
- `loadPredefinedItems()`: Initializes `items.txt` with 10 sample items.
- `displayItems()`: Reads and displays all items.
- `editItem(int ino)`: Edits an item.
- `deleteItem(int ino)`: Deletes an item.
- `generateBill()`: Handles billing, stock updates, and total calculation.

---

## **Limitations**
🚨 **Platform Dependency** – Works only on Windows due to `windows.h`.
🚨 **Minimal Input Validation** – Assumes valid user input.
🚨 **Basic File Handling** – Uses text files, not suitable for large-scale inventory.
🚨 **Console-Based** – No GUI.

---

## **Future Improvements**
✅ Add input validation.  
✅ Support cross-platform functionality (remove Windows-specific code).  
✅ Implement a database (e.g., SQLite) for better scalability.  
✅ Develop a GUI using Qt/SFML.  
✅ Add search functionality.

---

## **Contributing**
Feel free to **fork**, submit **pull requests**, or open **issues** for improvements!

---

## **License**
This project is open-source and available under the **MIT License**.

---

## **Author**
👤 **Your Name** – [Prathamansh](https://github.com/Prathamansh)

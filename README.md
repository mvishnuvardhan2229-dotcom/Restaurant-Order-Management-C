# Restaurant Order Management System (in C)

This is a simple console-based application for managing restaurant orders, built as a project for my C programming course. It demonstrates all core CRUD (Create, Read, Update, Delete) operations and persists data to a text file.

## Features
This program meets all the project requirements:
* **Add Order:** Add a new order with ID, item name, quantity, and price.
* **Display All Orders:** Show a formatted table of all existing orders.
* **Search by ID:** Find and display a single order using its unique ID.
* **Update Existing Order:** Modify the details of an existing order.
* **Delete Order:** Remove an order from the system by its ID.
* **Persistent Storage:** All order records are saved to `orders.txt` and re-loaded every time the program starts.

## Core C Concepts Used
This project was built using foundational C concepts from the syllabus, including:
* **Structs (`struct`):** To define the `Order` data type.
* **Arrays:** An array of `structs` (`orderBook[]`) is used to hold all records in memory.
* **Functions:** The program is modular, with a separate function for each feature (e.g., `addOrder()`, `deleteOrder()`).
* **File I/O (`stdio.h`):** Uses `FILE*` pointers with `fopen()`, `fclose()`, `fprintf()`, and `fscanf()` to manage text file data.
* **Loops & Conditionals:** `do-while` loop for the main menu and `switch` statement for user choices.
* **Pointers:** Used implicitly for passing arrays to functions and explicitly for file handling.

## How to Compile and Run
1.  Make sure you have a C compiler (like `gcc`) installed.
2.  Save the `restaurant_management.c` file to your computer.
3.  Open a terminal and navigate to the folder containing the file.
4.  Compile the program by running:
    ```bash
    gcc restaurant_management.c -o restaurant
    ```
5.  Run the compiled program:
    ```bash
    ./restaurant 
    ```
    (On Windows, you would just type `restaurant.exe`)

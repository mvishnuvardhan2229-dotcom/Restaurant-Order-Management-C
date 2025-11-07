/**
NAME=MACHABATHUNI VISHNU VARDHAN
ID NO=O230711
BRANCH=AI-ML
SECTION=AI
ROLL NO.39
PROJECT NAME=RESTURANT_ORDER_MANAGEMENT_SYSTEM
**/




/**
Restaurant Order Management System
**/



#include <stdio.h>    
#include <stdlib.h>   // For exit()



#define MAX_RECORDS 100
#define FILENAME "orders.txt"



typedef struct {
    int id;            
    char itemName[50];  
    int quantity;
    float price;       
} Order;



Order orderBook[MAX_RECORDS];		// Array of structures to store all order records
int recordCount = 0;		// Variable to keep track of the current number of records




void addOrder();
void displayAllOrders();
void searchOrder();
void updateOrder();
void deleteOrder();
void saveOrdersToFile();
void loadOrdersFromFile();


int main() {
    int choice;

    // Load existing records from the file at the start and returns correct recordCount variable value
    loadOrdersFromFile();


    do {
        printf("\n******************************************\n");
        printf("\n--- Restaurant Order Management System ---\n");
        printf("1. Add New Order\n");
        printf("2. Display All Orders\n");
        printf("3. Search for an Order (by ID)\n");
        printf("4. Update an Existing Order\n");
        printf("5. Delete an Order\n");
        printf("0. Save and Exit\n");
        
        
        
        printf("\nEnter your choice: ");
	scanf("%d", &choice);

        
        while (getchar() != '\n');		// Clear the input buffer

      
        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                displayAllOrders();
                break;
            case 3:
                searchOrder();
                break;
            case 4:
                updateOrder();
                break;
            case 5:
                deleteOrder();
                break;
            case 0:
                printf("Saving and exiting...\n");
                saveOrdersToFile(); // Save before exiting
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice != 0) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n'); // Wait for user to press Enter
        }

    } while (choice != 0);

    return 0;
}



void addOrder() {
    printf("\n******************************************\n");
    printf("--- Add New Order ---\n");

    // Check if the array is full
    if (recordCount >= MAX_RECORDS) {
        printf("Error: Order book is full. Cannot add more orders.\n");
        return;
    }

    // Get details for the new order
    Order newOrder;
    printf("Enter Order ID (must be unique): ");
    scanf("%d", &newOrder.id);

    // Check for duplicate ID
    for (int i = 0; i < recordCount; i++) {
        if (orderBook[i].id == newOrder.id) {
            printf("Error: An order with ID %d already exists.\n", newOrder.id);
            return;
        }
    }
    
    // Clear buffer before reading string
    while (getchar() != '\n'); 
    
    printf("Enter Item Name: ");
    scanf(" %[^\n]s", newOrder.itemName); // Read string with spaces
    
    printf("Enter Quantity: ");
    scanf("%d", &newOrder.quantity);
    printf("Enter Price per Item: ");
    scanf("%f", &newOrder.price);

    // Add the new order to the array
    orderBook[recordCount] = newOrder;
    recordCount++; // Increment the total count

    printf("\nSuccess: Order added successfully!\n");
}







void displayAllOrders() {
    printf("\n******************************************\n");
    printf("--- Display All Orders ---\n");

    if (recordCount == 0) {
        printf("No orders found.\n");
        return;
    }

    // Print table header
    printf("%-10s | %-20s | %-10s | %-10s | %-10s\n",
           "Order ID", "Item Name", "Quantity", "Price", "Total");
    printf("------------------------------------------------------------------------\n");

    // Loop through the array and print each record
    float grandTotal = 0.0;
    for (int i = 0; i < recordCount; i++) {
        float total = orderBook[i].quantity * orderBook[i].price;
        printf("%-10d | %-20s | %-10d | $%-9.2f | $%-9.2f\n",
               orderBook[i].id,
               orderBook[i].itemName,
               orderBook[i].quantity,
               orderBook[i].price,
               total);
        grandTotal += total;
    }
    printf("------------------------------------------------------------------------\n");
    printf("Grand Total of all orders: $%.2f\n", grandTotal);
}









void searchOrder() {
    int searchId;
    int foundIndex = -1; // -1 means not found

   printf("\n******************************************\n");
    printf("--- Search for an Order ---\n");
    printf("Enter Order ID to search for: ");
    scanf("%d", &searchId);

    // Loop to find the record
    for (int i = 0; i < recordCount; i++) {
        if (orderBook[i].id == searchId) {
            foundIndex = i;
            break; // Stop searching once found
        }
    }

    // Check if found
    if (foundIndex != -1) {
        printf("Order found!\n");
        printf("-------------------\n");
        printf("Order ID:    %d\n", orderBook[foundIndex].id);
        printf("Item Name:   %s\n", orderBook[foundIndex].itemName);
        printf("Quantity:    %d\n", orderBook[foundIndex].quantity);
        printf("Price:       $%.2f\n", orderBook[foundIndex].price);
        printf("Total Cost:  $%.2f\n", orderBook[foundIndex].quantity * orderBook[foundIndex].price);
        printf("-------------------\n");
    } else {
        printf("Error: Order with ID %d not found.\n", searchId);
    }
}






void updateOrder() {
    int searchId;
    int foundIndex = -1;

    printf("\n******************************************\n");
    printf("--- Update an Existing Order ---\n");
    printf("Enter Order ID to update: ");
    scanf("%d", &searchId);

    // Loop to find the record
    for (int i = 0; i < recordCount; i++) {
        if (orderBook[i].id == searchId) {
            foundIndex = i;
            break;
        }
    }

    // Check if found
    if (foundIndex != -1) {
        printf("Order found. Enter new details (current details in [ ]):\n");

        // Clear buffer before reading string
        while (getchar() != '\n'); 
        
        // Get new details
        printf("Enter new Item Name [%s]: ", orderBook[foundIndex].itemName);
        scanf(" %[^\n]s", orderBook[foundIndex].itemName);

        printf("Enter new Quantity [%d]: ", orderBook[foundIndex].quantity);
        scanf("%d", &orderBook[foundIndex].quantity);

        printf("Enter new Price [%.2f]: ", orderBook[foundIndex].price);
        scanf("%f", &orderBook[foundIndex].price);

        printf("\nSuccess: Order ID %d updated successfully!\n", searchId);
    } else {
        printf("Error: Order with ID %d not found.\n", searchId);
    }
}








void deleteOrder() {
    int searchId;
    int foundIndex = -1;

    printf("\n******************************************\n");
    printf("--- Delete an Order ---\n");
    printf("Enter Order ID to delete: ");
    scanf("%d", &searchId);

    // Loop to find the record
    for (int i = 0; i < recordCount; i++) {
        if (orderBook[i].id == searchId) {
            foundIndex = i;
            break;
        }
    }

    // Check if found
    if (foundIndex != -1) {
        // Shift all subsequent elements one position to the left
        // This overwrites the record to be deleted.
        for (int i = foundIndex; i < recordCount - 1; i++) {
            orderBook[i] = orderBook[i + 1];
        }

        // Decrement the total record count
        recordCount--;

        printf("Success: Order ID %d deleted successfully!\n", searchId);
    } else {
        printf("Error: Order with ID %d not found.\n", searchId);
    }
}







void saveOrdersToFile() {
    FILE *file_pointer;

    // Open the file in "write text" ("w") mode
    file_pointer = fopen(FILENAME, "w");

    if (file_pointer == NULL) {
        printf("Error: Could not open file %s for writing.\n", FILENAME);
        return;
    }

    // Loop through the array and write each record to the file as a new line
    // We use a comma-separated format (like a simple CSV)
    for (int i = 0; i < recordCount; i++) {
        fprintf(file_pointer, "%d,%s,%d,%.2f\n",
                orderBook[i].id,
                orderBook[i].itemName,
                orderBook[i].quantity,
                orderBook[i].price);
    }

    // Close the file
    fclose(file_pointer);
}






void loadOrdersFromFile() {
    FILE *file_pointer;

    // Open the file in "read text" ("r") mode
    file_pointer = fopen(FILENAME, "r");

    // If the file doesn't exist (e.g., first time running), just return
    if (file_pointer == NULL) {
        printf("Info: No existing data file found. Starting fresh.\n");
        recordCount = 0; // Ensure count is zero
        return;
    }

    // Reset record count before loading
    recordCount = 0;

    // Read from the file line by line until we reach the end (EOF)
    // or the array is full.
    // fscanf returns the number of items successfully read. We expect 4.
    // The "%[^,]" format reads a string until it hits a comma.
    while (recordCount < MAX_RECORDS &&
           fscanf(file_pointer, "%d,%[^,],%d,%f\n",
                  &orderBook[recordCount].id,
                  orderBook[recordCount].itemName,
                  &orderBook[recordCount].quantity,
                  &orderBook[recordCount].price) == 4) {
        recordCount++; // Increment count for each successful read
    }

    // Close the file
    fclose(file_pointer);

    if (recordCount > 0) {
         printf("Info: Loaded %d record(s) from %s.\n", recordCount, FILENAME);
    }
}

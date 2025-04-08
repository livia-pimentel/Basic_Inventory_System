#include "inventory.h"
#include <iostream>

int main() {
    Inventory inventory;

    // Loads the file data
    inventory.readFile("inventory.txt");
    
    // Create the object item
    // Item newItem("PlayStation", 10, 750.59);

    // Add the object item 
    // inventory.addItem(newItem);

    inventory.deleteItem("Laptop");

    // Displays inventory list
    std::cout << "Inventory List:\n";
    inventory.displayInventory();

    // Save the inventory
    // inventory.writeFile("inventory.txt");

    std::cout << "\nEnd of Inventory List\n";

    return 0;
}
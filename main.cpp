#include "inventory.h"
#include <iostream>

int main() {
    Inventory inventory;

    // Loads the file data
    inventory.readFile("inventory.txt");

    // Displays inventory list
    std::cout << "Inventory List:\n";
    inventory.displayInventory();

    std::cout << "\nEnd of Inventory List\n";

    return 0;
}
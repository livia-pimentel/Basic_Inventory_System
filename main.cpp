#include "inventory.h"
#include <iostream>

int main() {
    Inventory inventory;

    // Loads the file data
    inventory.readFile("inventory.txt");
    
    // Menu option
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Delete Item\n";
        std::cout << "3. Search Item\n";
        std::cout << "4. Display Inventory\n";
        std::cout << "5. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int quantity;
                double price;
                std::cout << "Enter item name: ";
                std:: cin >> name;
                std::cout << "Enter item quantity: ";
                std:: cin >> quantity;
                std::cout << "Enter item price: ";
                std:: cin >> price;
                inventory.addItem(Item(name, quantity, price));
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter item name to delete: ";
                std::cin >> name;
                inventory.deleteItem(name);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Enter item name to search: ";
                std::cin >> name;
                Item foundItem = inventory.searchItem(name);
                if (foundItem.getName() != "") {
                    std::cout << "Item found:\n";
                    foundItem.display();
                }
                break;
            }
            case 4: {
                inventory.displayInventory();
                break;
            }
            case 5:
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    
    // Salve the inventory file
    inventory.writeFile("inventory.txt");

    return 0;
}
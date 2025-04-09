#include "inventory.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>


// Validate item name
bool isValidName(const std::string& name) {
    if (name.empty()) {
        return false;
    }
    if (std::all_of(name.begin(), name.end(), ::isspace)) {
        return false;
    }

    return true;   
}

std::string capitalizeName(std::string name) {
    if (!name.empty()) {
        name[0] = std::toupper(name[0]);
        
        for (size_t i = 1; i < name.length(); i++) {
            name[i] = std::tolower(name[i]);
        }
    }
    
    return name;
}

int main() {
    Inventory inventory;

    // Loads the file data
    inventory.readFile("inventory.txt");
    
    // Menu option
    int choice;
    std::string line;
    do {
        std::cout << "\n************ Menu ************\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Delete Item\n";
        std::cout << "3. Search Item\n";
        std::cout << "4. Display Inventory\n";
        std::cout << "5. Exit\n";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1: {
                std::string name;
                int quantity;
                double price;
                do {
                    std::cout << "Enter item name: ";
                    std::getline(std::cin, line); // Read the whole line
                    if (!isValidName(line)) {
                        std::cout << "Invalid name. Please enter a valid name.\n";
                    }
                    
                } while (!isValidName(line));
                line = capitalizeName(line);
                std::cout << "Enter item quantity: ";
                std:: cin >> quantity;
                std::cout << "Enter item price: ";
                std:: cin >> price;
                std::cin.ignore(); // Clear the input buffer
                inventory.addItem(Item(line, quantity, price));
                inventory.writeFile("inventory.txt"); // Salve after add
                break;
            }
            case 2: {
                std::cout << "Enter item name to delete: ";
                std::getline(std::cin, line); // Read the whole line
                line = capitalizeName(line);
                std::cout << "--------------------\n";
                inventory.deleteItem(capitalizeName(line));
                inventory.writeFile("inventory.txt"); // Salve after delete
                break;
            }
            case 3: {
                std::cout << "--------------------\n";
                std::cout << "Enter item name to search: ";
                std::getline(std::cin, line); // Read the whole line
                line = capitalizeName(line);
                Item foundItem = inventory.searchItem(capitalizeName(line));
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

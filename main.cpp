#include "inventory.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <limits>
#include <regex>


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

// Capitalize Name Item
std::string capitalizeName(std::string name) {
    if (!name.empty()) {
        name[0] = std::toupper(name[0]);
        
        for (size_t i = 1; i < name.length(); i++) {
            name[i] = std::tolower(name[i]);
        }
    }
    
    return name;
}

// Verify if the string is a valid number 
bool isNumber(const std::string& str) {
    std::regex numberRegex(R"([+-]?\d+(\.\d*)?)");
    return std::regex_match(str, numberRegex);
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
                std::string quantityString;
                while (true) {
                    std::cout << "Enter item quantity: ";
                    std::getline(std::cin, quantityString);
                    if (std::all_of(quantityString.begin(), quantityString.end(), ::isdigit)) {
                        quantity = std::stoi(quantityString);
                        break;
                    } else {
                        std::cin.clear(); // Clear the error
                        std::cout << "Invalid quantity. Please enter an integer.\n";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer 
                    }
                }
                std::string priceString;
                while (true) {
                    std::cout << "Enter item price: ";
                    std::getline(std::cin, priceString);
                    if (isNumber(priceString)) {
                        std::stringstream ss(priceString);
                        ss >> price;
                        break; 
                    } else {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer 
                        std::cin.clear(); // Clear the error
                        std::cout << "Invalid price. Please enter a number.\n";
                    }
                }
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
                std::cout << "Exiting the system...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    
    // Salve the inventory file
    inventory.writeFile("inventory.txt");

    return 0;
}

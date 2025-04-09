#include "inventory.h"
#include "item.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 

void Inventory::readFile(std::string nameFile) {
    std::ifstream file(nameFile);
    if (file.fail()) {
        std::cerr << "Error opening file: " << nameFile << '\n';
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        int quantity;
        double price;

        if (ss >> name >> quantity >> price) {
            items.push_back(Item(name, quantity, price));
        } else {
            std::cerr << "Error reading line: " << line << '\n';
        }
    }

    file.close();
}

void Inventory::writeFile(std::string nameFile) {
    std::ofstream file(nameFile);
    if (file.fail()) {
        std::cerr << "Error opening file: " << nameFile << '\n';
        return;
    }

    for (const auto& item : items) {
        file << item.getName() << " " << item.getQuantity() << " " << item.getPrice() << '\n';
    }

    file.close();
}

void Inventory::displayInventory() const {
    for (const auto& item : items) {
        item.display();
        std::cout << "--------------------\n";
    }
}

// Add new item
void Inventory::addItem(Item item) {
    items.push_back(item);
}

// Delete item
void Inventory::deleteItem(std::string name) {
    for (auto i = items.begin(); i != items.end(); ++i) {
        if (i -> getName() == name) {
            items.erase(i);
            std::cout << name + " deleted successfully!";
            return;
        };
    }
    std::cout << "Item " << name << " not found.\n";
}

Item Inventory::searchItem(std::string name) {
    for (const auto& item : items) {
        if (item.getName() == name) {
            return item; // Returns the item found
        }  
    }

    // If the item is not found, displays the message in and returns an empty item
    std::cout << "Item not found.\n";
    return Item("", 0, 0.0); 
}
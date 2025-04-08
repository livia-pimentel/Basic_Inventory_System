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
#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <vector>
#include "item.h"

class Inventory {
    private:
        std::vector<Item> items;

    public: 
        // Methods to manage inventory
        void addItem(Item item);
        void deleteItem(std::string name);
        Item searchItem(std::string name);
        void displayInventory() const;

        // Methods for reading and writing in file
        void readFile(std::string nameFile);
        void writeFile(std::string nameFile);

};

#endif
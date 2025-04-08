#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item {

    // Attributes of the item
    private:
        std::string name;
        int quantity;
        double price;

    public:
        // Constructor - Initializes the attributes
        Item(std::string name, int quantity, double price);

        // Getters - Allow access to the attributes
        std::string getName() const;
        int getQuantity() const;
        double getPrice() const;

        // Setters - Allow modify the attributes
        void setName(std::string name);
        void setQuantity(int quantity);
        void setPrice(double price);

        // Display data of the item
        void display() const;
};

#endif
#include "item.h"
#include <iostream>

// Constructor 
Item::Item(std::string name, int quantity, double price): name(name), quantity(quantity), price(price){} // Declares the constructor of the class Item
// Initialization list

// Getters
std::string Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

double Item::getPrice() const {
    return price;
}

// Setters
void Item::setName(std::string name) {
    this -> name = name;
}

void Item::setQuantity(int quantity) {
    this -> quantity = quantity;
}

void Item::setPrice(double price) {
    this -> price = price;
}

void Item::display() const {
    std::cout << "Name: " << name << '\n';
    std::cout << "Quantity: " << quantity << '\n';
    std::cout << "Price: " << price << '\n';
}
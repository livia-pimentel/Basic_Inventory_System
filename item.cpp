#include "item.h"
#include <iostream>

// Constructor 
Item::Item(std::string name, int quantity, double price); // Declares the constructor of the class Item
    : name(name), quantity(quantity), price(price){} // Initialization list
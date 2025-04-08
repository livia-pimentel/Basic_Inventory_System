#include "inventory.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Inventory {
    private:
    std::vector<std::string> items;

    public:
        // Try to open the inventory file, if it does not exist will appear an error message
        void loadFile(std::string filename) {
            std::ifstream file(filename);
            if (file.fail()) {
                std::cerr << "Error opening file: " << filename << '\n';
                return;
            }
            
            std::string item;
            while (std::getline(file, item)) { // Read file line. Each read line is stored in the item variable that is added to the vector
                items.push_back(item);
            }
            
            file.close();
        }


}
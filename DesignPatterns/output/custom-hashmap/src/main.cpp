#include <iostream>
#include "HashMap.h"
#include "strategies/SeparateChaining.h"
#include "strategies/OpenAddressing.h"

int main() {
    // Create a HashMap with Separate Chaining strategy
    HashMap<int, std::string> separateChainingMap(10, new SeparateChaining<int, std::string>());
    
    separateChainingMap.insert(1, "One");
    separateChainingMap.insert(2, "Two");
    separateChainingMap.insert(1, "Updated One");

    std::cout << "Separate Chaining Map:" << std::endl;
    std::cout << "Key 1: " << *separateChainingMap.find(1) << std::endl;
    std::cout << "Key 2: " << *separateChainingMap.find(2) << std::endl;

    // Create a HashMap with Open Addressing strategy
    HashMap<int, std::string> openAddressingMap(10, new OpenAddressing<int, std::string>());
    
    openAddressingMap.insert(1, "One");
    openAddressingMap.insert(2, "Two");
    openAddressingMap.insert(1, "Updated One");

    std::cout << "Open Addressing Map:" << std::endl;
    std::cout << "Key 1: " << *openAddressingMap.find(1) << std::endl;
    std::cout << "Key 2: " << *openAddressingMap.find(2) << std::endl;

    return 0;
}
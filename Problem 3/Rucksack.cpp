#include "Rucksack.hpp"
#include <array>

Rucksack::Rucksack(const std::string& items) : 
    mFirstCompartment(items.substr(0, items.size() / 2)), 
    mSecondCompartment(items.substr(items.size() / 2, items.size() / 2))
{
    
}

int Rucksack::compareCompartments() 
{
    std::array<bool, 52> firstCompartmentItems = mFirstCompartment.getItems();
    std::array<bool, 52> secondCompartmentItems = mSecondCompartment.getItems();

    int priority = 0;
    for(int i = 0; i < 52; i++)
    {
        if(firstCompartmentItems[i] && secondCompartmentItems[i])
        {
            priority = i + 1;
        }
    }

    return priority;
}

std::array<bool, 52> Rucksack::getItems()
{
    std::array<bool, 52> firstCompartmentItems = mFirstCompartment.getItems();
    std::array<bool, 52> secondCompartmentItems = mSecondCompartment.getItems();
    
    std::array<bool, 52> backpackItems{};
    for(int i = 0; i < 52; i++)
    {
        backpackItems[i] = firstCompartmentItems[i] | secondCompartmentItems[i];
    }

    return backpackItems;
}
#include "Compartment.hpp"

Compartment::Compartment(const std::string& items)
{
    for(char id : items)
    {
        mItems.push_back(Item(id));
    }
}

std::array<bool, 52> Compartment::getItems()
{
    std::array<bool, 52> hasItems{};
    for(Item item : mItems)
    {
        hasItems[item.getItemValue() - 1] = true;
    }

    return hasItems;
}
#ifndef COMPARTMENT_HPP
#define COMPARTMENT_HPP

#include<string>
#include<vector>
#include<array>
#include "Item.hpp"

class Compartment
{
public:
    Compartment(const std::string& items);
    std::array<bool, 52> getItems();
private:
    std::vector<Item> mItems;
};

#endif
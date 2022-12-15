#ifndef RUCKSACK_HPP
#define RUCKSACK_HPP

#include "Compartment.hpp"
#include <array>

class Rucksack
{
public:
    Rucksack(const std::string& items);
    std::array<bool, 52> getItems();
    int compareCompartments();
private:
    Compartment mFirstCompartment;
    Compartment mSecondCompartment;
};

#endif
#ifndef GROUP_HPP
#define GROUP_HPP

#include <vector>
#include "Rucksack.hpp"

class Group 
{
public:
    Group(const std::vector<std::string>& members);
    int getBadge();
private:
    std::vector<Rucksack> mMembers;
};

#endif
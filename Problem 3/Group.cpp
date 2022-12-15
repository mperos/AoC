#include <array>
#include <iostream>
#include "Group.hpp"

Group::Group(const std::vector<std::string>& members)
{
    for(std::string member : members)
    {
        mMembers.push_back(Rucksack(member));
    }
}

int Group::getBadge()
{
    std::array<bool, 52> isBadge;
    std::fill(isBadge.begin(), isBadge.end(), true);
    for(Rucksack member : mMembers)
    {
        std::array<bool, 52> memberItems = member.getItems();
        for(int i = 0; i < 52; i++) 
        {
            isBadge[i] = isBadge[i] & memberItems[i];
        }
    }

    int value = 0;
    bool found = false;
    for(int i = 0; i < 52; i++)
    {
        if(isBadge[i] && found) 
        {
            return 0;
        }
        if(isBadge[i])
        {
            found = true;
            value = i + 1;
        }
    }

    return value;
}
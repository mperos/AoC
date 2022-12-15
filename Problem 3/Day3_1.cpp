#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "Rucksack.hpp"
#include "Group.hpp"

int main() 
{
    std::ifstream file("input.txt");
    std::string newline;

    int cnt = 0;
    int result1 = 0;
    int result2 = 0;
    std::vector<std::string> members;
    while(std::getline(file, newline))
    {
        // First part
        Rucksack rucksack(newline);
        result1 += rucksack.compareCompartments();

        // Second part
        cnt++;
        members.push_back(newline);
        if(cnt % 3 == 0) {
            Group group(members);
            result2 += group.getBadge();
            members.clear();
        }
    }

    std::cout << "First result: " << result1 << std::endl;
    std::cout << "Second result: " << result2 << std::endl;

    return 0;
}
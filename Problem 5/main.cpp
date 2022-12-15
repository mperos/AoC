#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "ShipyardManager.hpp"
#include "Shipyard.hpp"

// command, command.execute(params)
// how to make it do changes on this object?
// command should have the shipyard object

// (move crate) command has shipyard as its member variable and that command can be shipyardMaster member variable
// shipyard will consist of cratestacks (STACK) and will move crates around

// ShipyardManager will have two commands as member variables (command member variables will have a reference to shipyard
// and will operate on them, regarding which command the shipyard manager calls)

std::string allUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    std::ifstream file("input.txt");
    std::string newline;
    Shipyard shipyard;
    ShipyardManager shipyardManager(shipyard);

    // Creating the shipyard
    while(std::getline(file, newline))
    {
        if(newline == "") 
        { 
            break; 
        }
        else 
        {
            std::size_t found = newline.find_first_of(allUpper);
            while(found != std::string::npos)
            {
                Crate crate(newline[found]);
                int stackIndex = found / 4;
                if(shipyard.numberOfCrateStacks() <= stackIndex)
                {
                    for(int i = shipyard.numberOfCrateStacks(); i <= stackIndex; i++)
                    {
                        shipyard.addCrateStack();
                    }
                }
                shipyard.addCrateToCrateStackBottom(stackIndex, crate);          
                found = newline.find_first_of(allUpper, found + 1);
            }
        }
    }

    // Executing commands
    while(std::getline(file, newline))
    {
        std::vector<int> numbers;
        std::size_t found = newline.find(' ');
        while(found != std::string::npos)
        {
            found++;
            std::string number = "";
            for(int i = found; i < newline.size(); i++)
            {
                if('0' <= newline[i] && newline[i] <= '9')
                {
                    number += newline[i];
                }
                else
                {
                    break;
                }
            }
            if(number != "") 
            {
                numbers.push_back(std::stoi(number));
            }
            found = newline.find(' ',  found + 1);
        }
        
        shipyardManager.moveCrates(numbers[0], numbers[1] - 1, numbers[2] - 1);
        // shipyardManager.moveMultipleCrates(numbers[0], numbers[1] - 1, numbers[2] - 1);
    }

    

    std::cout << "Solution: " << std::endl;
    shipyard.showShipyardTop();

    return 0;
}
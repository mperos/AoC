#include<iostream>
#include<fstream>
#include<string>

#include "Assignment.hpp"

int main()
{
    std::ifstream file("input.txt");
    std::string newline;

    int overlap_cnt = 0;
    int contained_cnt = 0;
    while(std::getline(file, newline))
    {
        AssignmentPair pair(newline);
        if(pair.assignmentsContained()) 
        {
            contained_cnt++; 
        }
        if(pair.assignmentsOverlap())
        {
            overlap_cnt++;
        }
    }

    std::cout << "Number of contained: " << contained_cnt << std::endl;
    std::cout << "Number of overlapped: " << overlap_cnt << std::endl;
    return 0;
}
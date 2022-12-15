#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include<string>

class Assignment
{
public:
    Assignment(std::string assignment);
    int getStartId();
    int getEndId();
private:
    int mStartId;
    int mEndId;
};

class AssignmentPair
{
public:
    AssignmentPair(std::string assignmentPair);
    bool assignmentsOverlap();
    bool assignmentsContained();
private:
    Assignment mFirstAssignment;
    Assignment mSecondAssignment;
};

#endif
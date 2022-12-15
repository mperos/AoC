#include <iostream>
#include "Assignment.hpp"

Assignment::Assignment(std::string assignment)
{
    std::size_t found = assignment.find("-");
    this->mStartId = std::stoi(assignment.substr(0, found));
    this->mEndId = std::stoi(assignment.substr(found + 1, assignment.length() - (found + 1)));
}

int Assignment::getStartId()
{
    return this->mStartId;
}

int Assignment::getEndId()
{
    return this->mEndId;
}

AssignmentPair::AssignmentPair(std::string assignmentPair) :
    mFirstAssignment(assignmentPair.substr(0, assignmentPair.find(","))),
    mSecondAssignment(assignmentPair.substr(
        assignmentPair.find(",") + 1,
        assignmentPair.length() - (assignmentPair.find(",")  + 1)
    ))
{

}

bool AssignmentPair::assignmentsOverlap()
{
    bool isOverlapped = false;
    if((mFirstAssignment.getStartId() <= mSecondAssignment.getStartId()) &&
       (mSecondAssignment.getStartId() <= mFirstAssignment.getEndId()))
    {
        isOverlapped = true;
    }
    if((mSecondAssignment.getStartId() <= mFirstAssignment.getStartId()) &&
       (mFirstAssignment.getStartId() <= mSecondAssignment.getEndId()))
    {
        isOverlapped = true;
    }
    return isOverlapped;
}

bool AssignmentPair::assignmentsContained()
{
    bool isContained = false;
    if((mFirstAssignment.getStartId() <= mSecondAssignment.getStartId()) && 
       (mSecondAssignment.getEndId() <= mFirstAssignment.getEndId()))
    {
        isContained = true;
    }
    if((mSecondAssignment.getStartId() <= mFirstAssignment.getStartId()) &&
       (mFirstAssignment.getEndId() <= mSecondAssignment.getEndId()))
    {
        isContained = true;
    }
    
    return isContained;
}


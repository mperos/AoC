#include "Shipyard.hpp"
#include <iostream>

Crate::Crate(char crate)
{
    this->mCrate = crate;
}

char Crate::getCrate()
{
    return this->mCrate;
}

void CrateStack::addCrateToTop(const Crate& crate)
{
    mCrateStack.push_front(crate);
}

void CrateStack::addCrateToBottom(const Crate& crate)
{
    mCrateStack.push_back(crate);
}

void CrateStack::showCrateStack()
{
    for(int i = 0; i < mCrateStack.size(); i++)
    {
        std::cout << mCrateStack[i].getCrate() << " ";
    }
}

void CrateStack::showCrateStackTop()
{
    std::cout << mCrateStack.front().getCrate();
}

Crate CrateStack::pickUpCrate()
{
    // assert(mCrateStack.empty());
    Crate crate = this->mCrateStack.front();
    this->mCrateStack.pop_front();
    return crate;
}

void Shipyard::addCrateStack()
{
    mShipyard.push_back(CrateStack());
}

void Shipyard::addCrateToCrateStackBottom(int index, Crate crate)
{
    mShipyard[index].addCrateToBottom(crate);
}

void Shipyard::addCrateToCrateStackTop(int index, Crate crate)
{
    mShipyard[index].addCrateToTop(crate);
}

void Shipyard::showShipyard()
{
    for(int i = 0; i < mShipyard.size(); i++)
    {
        mShipyard[i].showCrateStack();
        std::cout << std::endl;
    }
}

void Shipyard::showShipyardTop()
{
    for(int i = 0; i < mShipyard.size(); i++)
    {
        mShipyard[i].showCrateStackTop();
    }
}

Crate Shipyard::pickUpCrateFromCrateStack(int index)
{
    return mShipyard[index].pickUpCrate();
}

int Shipyard::numberOfCrateStacks() 
{
    return mShipyard.size();
}
#ifndef SHIPYARD_HPP
#define SHIPYARD_HPP

#include<vector>
#include<deque>

class Crate
{
public:
    Crate(char crate);
    char getCrate();
private:
    char mCrate;
};

class CrateStack
{
public:
    void addCrateToTop(const Crate& crate);
    void addCrateToBottom(const Crate& crate);
    void showCrateStack();
    void showCrateStackTop();
    Crate pickUpCrate();
private:
    std::deque<Crate> mCrateStack;
};

class Shipyard
{
public:
    void addCrateStack();
    void addCrateToCrateStackBottom(int index, Crate crate);
    void addCrateToCrateStackTop(int index, Crate crate);
    void showShipyard();
    void showShipyardTop();
    int numberOfCrateStacks();
    Crate pickUpCrateFromCrateStack(int index);
private:
    std::vector<CrateStack> mShipyard;
};



#endif
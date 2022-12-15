#include<stack>
#include "Command.hpp"

MoveCommand::MoveCommand(Shipyard& shipyard) :
    mShipyard(shipyard)
{

}

void MoveCommand::execute(int amount, int startId, int endId)
{
    for(int i = 0; i < amount; i++)
    {
        Crate crate = mShipyard.pickUpCrateFromCrateStack(startId);
        mShipyard.addCrateToCrateStackTop(endId, crate);
    }
}

MoveMultipleCommand::MoveMultipleCommand(Shipyard& shipyard) :
    mShipyard(shipyard)
{

}

void MoveMultipleCommand::execute(int amount, int startId, int endId)
{
    std::stack<Crate> crates;
    for(int i = 0; i < amount; i++)
    {
        Crate crate = mShipyard.pickUpCrateFromCrateStack(startId);
        crates.push(crate);
    }

    while(!crates.empty())
    {
        Crate crate = crates.top();
        crates.pop();
        mShipyard.addCrateToCrateStackTop(endId, crate);
    }
}
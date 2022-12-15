#include "ShipyardManager.hpp"
#include<cstdlib>

ShipyardManager::ShipyardManager(Shipyard& shipyard)
{
    moveCommand = new MoveCommand(shipyard);
    moveMultipleCommand = new MoveMultipleCommand(shipyard);
}

ShipyardManager::~ShipyardManager()
{
    delete moveCommand;
    delete moveMultipleCommand;
}

void ShipyardManager::moveCrates(int amount, int startId, int endId)
{
    moveCommand->execute(amount, startId, endId);
}

void ShipyardManager::moveMultipleCrates(int amount, int startId, int endId)
{
    moveMultipleCommand->execute(amount, startId, endId);
}
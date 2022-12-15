#ifndef SHIPYARDMANAGER_HPP
#define SHIPYARDMANAGER_HPP

#include "Shipyard.hpp"
#include "Command.hpp"

class ShipyardManager
{
public:
    ShipyardManager(Shipyard& shipyard);
    ~ShipyardManager();
    void moveCrates(int amount, int startId, int endId);
    void moveMultipleCrates(int amount, int StartId, int endId);
private:
    Command* moveCommand;
    Command* moveMultipleCommand;
};

#endif
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Shipyard.hpp"

class Command
{
public:
    virtual ~Command() {};
    virtual void execute(int amount, int startId, int endId) = 0;
    virtual int checkCommand() { return 0; };
};

class MoveCommand : public Command
{
public:
    MoveCommand(Shipyard& shipyard);
    void execute(int amount, int startId, int endId) override;
    int checkCommand() { return 1; };
private:
    Shipyard& mShipyard;
};

class MoveMultipleCommand : public Command
{
public:
    MoveMultipleCommand(Shipyard& shipyard);
    void execute(int amount, int startId, int endId) override;
private:
    Shipyard& mShipyard;
};

#endif
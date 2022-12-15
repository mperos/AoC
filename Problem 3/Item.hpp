#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
public:
    Item(const char& id);
    int getItemValue();
private:
    char mId;
};

#endif
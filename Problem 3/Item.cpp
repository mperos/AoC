#include "Item.hpp"

Item::Item(const char& id) : mId(id) 
{

}

int Item::getItemValue()
{
    return ('a' <= mId && mId <= 'z') ? (mId - 'a' + 1) : (mId - 'A' + 27);
}
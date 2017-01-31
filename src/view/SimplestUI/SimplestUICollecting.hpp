#ifndef SIMPLESTUICOLLECTING_HPP
#define SIMPLESTUICOLLECTING_HPP

#include "../../controller/State.hpp"

class ItemList;

class SimplestUICollecting : public State
{
public:
	SimplestUICollecting(ItemList& itemList);

	virtual request Run();

private:
	ItemList* _itemList=0;
};

#endif

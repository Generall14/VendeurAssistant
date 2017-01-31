#ifndef SIMPLESTUIREMOVE_HPP
#define SIMPLESTUIREMOVE_HPP

#include "../../controller/State.hpp"

class ItemList;

class SimplestUIRemove : public State
{
public:
	SimplestUIRemove(ItemList& itemList);

	virtual request Run();

private:
	ItemList* _itemList=0;
};

#endif

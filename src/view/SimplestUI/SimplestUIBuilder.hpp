#ifndef SIMPLESTUIBUILDER_HPP
#define SIMPLESTUIBUILDER_HPP

#include "../../controller/StateBuilder.hpp"

class State;
class Item;
class ItemList;

class SimplestUIBuilder : public StateBuilder
{
public:
	SimplestUIBuilder();
	virtual ~SimplestUIBuilder(){}

	virtual void InitMenuSystem();
	virtual State* BuildMainMenu();
	virtual State* BuildCollectingState(ItemList&);
	virtual State* RemoveMenu(ItemList&);
	virtual State* AddMenu(Item&);
	virtual State* QuantityMenu(Item&);
	virtual State* SearchMenu(Item&);
};

#endif

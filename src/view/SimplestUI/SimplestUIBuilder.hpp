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
	virtual State* BuildCollectingState(ItemList&itemList);
	virtual State* BuildRemoveMenu(ItemList&itemList);
	virtual State* BuildAddMenu(Item& item);
	virtual State* BuildQuantityMenu(Item& item);
	virtual State* BuildSearchMenu(Item& item);
};

#endif

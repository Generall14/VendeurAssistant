#ifndef STATEBUILDER_HPP
#define STATEBUILDER_HPP

class State;
class Item;
class ItemList;

class StateBuilder
{
public:
	StateBuilder(){}
	virtual ~StateBuilder(){}

	virtual void InitMenuSystem() = 0;
	virtual State* BuildMainMenu() = 0;
	virtual State* BuildCollectingState(ItemList&) = 0;
	virtual State* RemoveMenu(ItemList&) = 0;
	virtual State* AddMenu(Item&) = 0;
	virtual State* QuantityMenu(Item&) = 0;
	virtual State* SearchMenu(Item&) = 0;
};

#endif

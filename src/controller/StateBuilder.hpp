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
	virtual State* BuildRemoveMenu(ItemList&) = 0;
	virtual State* BuildAddMenu(Item&) = 0;
	virtual State* BuildQuantityMenu(Item&) = 0;
	virtual State* BuildSearchMenu(Item&) = 0;
};

#endif

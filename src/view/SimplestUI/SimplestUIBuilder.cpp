#include "SimplestUIBuilder.hpp"

#include "../../controller/State.hpp"
#include "../../model/Item.hpp"
#include "../../model/ItemList.hpp"
#include "SimplestUIMainMenu.hpp"
#include "SimplestUICollecting.hpp"
#include "SimplestUIAdd.hpp"
#include "SimplestUIQuantity.hpp"
#include "SimplestUIRemove.hpp"
#include "SimplestUISearch.hpp"

SimplestUIBuilder::SimplestUIBuilder():
	StateBuilder()
{

}

void SimplestUIBuilder::InitMenuSystem()
{

}

State* SimplestUIBuilder::BuildMainMenu()
{
	return new SimplestUIMainMenu();
}

State* SimplestUIBuilder::BuildCollectingState(ItemList& itemList)
{
	return new SimplestUICollecting(itemList);
}

State* SimplestUIBuilder::BuildRemoveMenu(ItemList& itemList)
{
	return new SimplestUIRemove(itemList);
}

State* SimplestUIBuilder::BuildAddMenu(Item& item)
{
	return new SimplestUIAdd(item);
}

State* SimplestUIBuilder::BuildQuantityMenu(Item& item)
{
	return new SimplestUIQuantity(item);
}

State* SimplestUIBuilder::BuildSearchMenu(Item& item)
{
	return new SimplestUISearch(item);
}

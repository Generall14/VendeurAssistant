#include "SimplestUIBuilder.hpp"

#include "../../controller/State.hpp"
#include "../../model/Item.hpp"
#include "../../model/ItemList.hpp"
#include "SimplestUIMainMenu.hpp"

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

State* SimplestUIBuilder::BuildCollectingState(ItemList&)
{

}

State* SimplestUIBuilder::RemoveMenu(ItemList&)
{

}

State* SimplestUIBuilder::AddMenu(Item&)
{

}

State* SimplestUIBuilder::QuantityMenu(Item&)
{

}

State* SimplestUIBuilder::SearchMenu(Item&)
{

}

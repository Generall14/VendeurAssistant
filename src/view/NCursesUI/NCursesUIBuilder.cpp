#include "NCursesUIBuilder.hpp"

#include <ncurses.h>
#include "../../controller/State.hpp"
#include "../../model/Item.hpp"
#include "../../model/ItemList.hpp"
#include "NCursesUIMainMenu.hpp"
#include "NCursesUICollecting.hpp"
#include "NCursesUIAdd.hpp"

NCursesUIBuilder::NCursesUIBuilder():
	StateBuilder()
{

}

void NCursesUIBuilder::InitMenuSystem()
{
}

void NCursesUIBuilder::ClearMenuSystem()
{
}

State* NCursesUIBuilder::BuildMainMenu()
{
	return new NCursesUIMainMenu();
}

State* NCursesUIBuilder::BuildCollectingState(ItemList& itemList)
{
	return new NCursesUICollecting(itemList);
}

State* NCursesUIBuilder::BuildRemoveMenu(ItemList& itemList)
{
//	return new SimplestUIRemove(itemList);
}

State* NCursesUIBuilder::BuildAddMenu(Item& item)
{
	return new NCursesUIAdd(item);
}

State* NCursesUIBuilder::BuildQuantityMenu(Item& item)
{
//	return new SimplestUIQuantity(item);
}

State* NCursesUIBuilder::BuildSearchMenu(Item& item)
{
//	return new SimplestUISearch(item);
}

void NCursesUIBuilder::ShowMsg(std::string msg, std::string opt)
{
	int x, y;
	getmaxyx(stdscr, y, x);
	wclear(stdscr);
	box(stdscr, '|', '-');
	mvprintw(y/2, x/2-msg.size()/2, msg.c_str());
	mvprintw(y-2, 5, opt.c_str());
	refresh();
}

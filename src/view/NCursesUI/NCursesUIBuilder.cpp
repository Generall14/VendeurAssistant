#include "NCursesUIBuilder.hpp"

#include <ncurses.h>
#include "../../controller/State.hpp"
#include "../../model/Item.hpp"
#include "NCursesUIMainMenu.hpp"
#include "NCursesUICollecting.hpp"
#include "NCursesUIAdd.hpp"
#include "NCursesUIQuantity.hpp"
#include "NCursesUIRemove.hpp"
#include "NCursesUISearch.hpp"

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
	return new NCursesUIRemove(itemList);
}

State* NCursesUIBuilder::BuildAddMenu(Item& item)
{
	return new NCursesUIAdd(item);
}

State* NCursesUIBuilder::BuildQuantityMenu(Item& item)
{
	return new NCursesUIQuantity(item);
}

State* NCursesUIBuilder::BuildSearchMenu(Item& item)
{
	return new NCursesUISearch(item);
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

void NCursesUIBuilder::AddHeader(int y)
{
	int x, my;
	getmaxyx(stdscr, my, x);
	mvprintw(y, 5, "Nr.   Nazwa");
	mvprintw(y, x-45, "  Kod        Cena        Ilosc    Razem    ");
}

void NCursesUIBuilder::AddPosition(int y, ItemList::iIterator it, int c, bool sel)
{
	int x, my;
	getmaxyx(stdscr, my, x);
	char buf[40];
	sprintf(buf, "%i", c);
	mvprintw(y, 5, buf);
	mvprintw(y, 11, (*it).ProductItem().Name().c_str());
	sprintf(buf, "%.4i", (*it).ProductItem().Code());
	mvprintw(y, x-43, buf);
	sprintf(buf, "%.2f", (*it).ProductItem().Price());
	mvprintw(y, x-32, buf);
	sprintf(buf, "%.2f", (*it).Quantity());
	mvprintw(y, x-20, buf);
	sprintf(buf, "%.2f", (*it).Price());
	mvprintw(y, x-11, buf);
	if(!sel)
		return;
	mvprintw(y, 2, ">>");
	mvprintw(y, x-4, "<<");
}

void NCursesUIBuilder::AddPosition(int y, Assortment::aIterator it, bool sel)
{
	int x, my;
	getmaxyx(stdscr, my, x);
	char buf[40];
	mvprintw(y, 11, (*it).second.Name().c_str());
	sprintf(buf, "%.4i", (*it).second.Code());
	mvprintw(y, x-43, buf);
	if(!sel)
		return;
	mvprintw(y, 2, ">>");
	mvprintw(y, x-4, "<<");
}

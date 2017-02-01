#include "NCursesUICollecting.hpp"

#include "../../model/ItemList.hpp"
#include <iostream>
#include <ncurses.h>

NCursesUICollecting::NCursesUICollecting(ItemList &itemList):
	_itemList(&itemList)
{

}

NCursesUICollecting::request NCursesUICollecting::Run()
{
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	_itemList->AddItem(Item(Product("aaa", 666, 2.22), 6.66));
	request temp;
	initscr();
	while(666)
	{
		wclear(stdscr);
		std::string tempString = ">>>>>> VendeurAssistant <<<<<<";
		int x, y, i;
		getmaxyx(stdscr, y, x);
		refresh();
		box(stdscr, '|', '-');
		mvprintw(2, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Budowanie rachunku";
		mvprintw(3, x/2-tempString.size()/2, tempString.c_str());

		int dst = y-7-4-3-3;
		mvprintw(5, 3, "Aktualna lista zakupów:");
		mvprintw(6, 3, "Nr.   Nazwa");
		mvprintw(6, x-45, "  Kod        Cena        Ilosc    Razem    ");

		int c=0;
		char buf[40];
		for(auto it=_itemList->begin();it!=_itemList->end()&&c<=dst;++it, ++c)
		{
			sprintf(buf, "%i", c+1);
			mvprintw(7+c, 3, buf);
			mvprintw(7+c, 9, (*it).ProductItem().Name().c_str());
			sprintf(buf, "%.4i", (*it).ProductItem().Code());
			mvprintw(7+c, x-43, buf);
			sprintf(buf, "%.2f", (*it).ProductItem().Price());
			mvprintw(7+c, x-32, buf);
			sprintf(buf, "%.2f", (*it).Quantity());
			mvprintw(7+c, x-20, buf);
			sprintf(buf, "%.2f", (*it).Price());
			mvprintw(7+c, x-11, buf);
		}
		if(c<_itemList->Size())
		{
			sprintf(buf, "... Lacznie %i pozycji", _itemList->Size());
			mvprintw(8+c, 20, buf);
		}
		sprintf(buf, "Suma:    %.2f", _itemList->TotalPrice());
		mvprintw(9+c, x-20, buf);

		mvprintw(y-6, 5, "Co dalej?");
		mvprintw(y-5, 5, "Przegladaj/usun [p]");
		mvprintw(y-4, 5, "Dodaj pozycje [d]");
		mvprintw(y-3, 5, "Zakoncz [Esc]");
		mvprintw(y-2, 5, "?> ");
		refresh();
		char ch;
		ch=getchar();
		if(ch=='d')
		{
			temp = request::add;
			break;
		}
		if(ch==27)
		{
			temp = request::end;
			break;
		}
		if(ch=='p')
		{
			temp = request::remove;
			break;
		}
	}
	endwin();
	return temp;
}

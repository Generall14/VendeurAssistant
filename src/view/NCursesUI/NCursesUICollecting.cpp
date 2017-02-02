#include "NCursesUICollecting.hpp"

#include "../../model/ItemList.hpp"
#include "NCursesUIBuilder.hpp"
#include <iostream>
#include <ncurses.h>

NCursesUICollecting::NCursesUICollecting(ItemList &itemList):
	_itemList(&itemList)
{

}

NCursesUICollecting::request NCursesUICollecting::Run()
{
	int ii=666;
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
		mvprintw(5, 3, "Aktualna lista zakupow:");
		NCursesUIBuilder::AddHeader(6);

		int c=0;
		char buf[40];
		for(auto it=_itemList->begin();it!=_itemList->end()&&c<=dst;++it, ++c)
			NCursesUIBuilder::AddPosition(7+c, it, c+1);
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

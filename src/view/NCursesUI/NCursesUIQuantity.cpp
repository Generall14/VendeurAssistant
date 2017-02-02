#include "NCursesUIQuantity.hpp"

#include "../../model/Item.hpp"
#include "../../model/Assortment.hpp"
#include "../../model/Product.hpp"
#include "NCursesUIBuilder.hpp"
#include <iostream>
#include <string>
#include <ncurses.h>

NCursesUIQuantity::NCursesUIQuantity(Item &item):
	_item(&item)
{

}

NCursesUIQuantity::request NCursesUIQuantity::Run()
{
	request temp;
	initscr();
	noecho();
	char inp[8]="\0";
	int cp =0;
	bool fl = _item->ProductItem().Unit()==Product::weight;
	while(666)
	{
		wclear(stdscr);
		std::string tempString = ">>>>>> VendeurAssistant <<<<<<";
		int x, y;
		getmaxyx(stdscr, y, x);
		refresh();
		box(stdscr, '|', '-');
		mvprintw(2, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Wprowadzanie ilosci";
		mvprintw(3, x/2-tempString.size()/2, tempString.c_str());

		tempString = "Produkt: " + _item->ProductItem().Name();
		mvprintw(6, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Wprowadz ";
		if(fl)
			tempString += "wage [g]";
		else
			tempString += "ilosc [szt]";
		tempString += " produktu i wcisnij enter";
		mvprintw(7, x/2-tempString.size()/2, tempString.c_str());

		mvprintw(y-5, 5, "Co dalej?");
		mvprintw(y-4, 5, "Zatwierdź [Enter]");
		mvprintw(y-3, 5, "Cofnij [Esc]");
		mvprintw(y-2, 5, "?> ");
		mvprintw(y-2, 8, inp);

		refresh();
		char ch;
		ch=getchar();

		if(ch==27)
		{
			temp = request::back;
			break;
		}
		if((ch>47)&&(ch<58)&&(cp<6))
		{
			inp[cp]=ch;
			inp[++cp]=0;
		}
		if((ch==127||ch==8)&&(cp>0))
			inp[--cp]=0;
		if((ch==KEY_ENTER||ch=='\n'||ch=='\r')&&cp>0)
		{
			int id=-1;
			try
			{
				id = std::stoi(inp, nullptr);
			}
			catch(...)
			{
				NCursesUIBuilder::ShowMsg("Nieprawidlowa wartosc!", "Wcisnij dowolny klawisz aby kontynuowac...");
				getchar();
				continue;
			}
			if(id<=0)
			{
				NCursesUIBuilder::ShowMsg("Nieprawidlowa wartosc!", "Wcisnij dowolny klawisz aby kontynuowac...");
				getchar();
			}
			else
			{
				if(fl)
					_item->setQuantity(((float)id)/1000);
				else
					_item->setQuantity(id);
				temp = request::ok;
				break;
			}
		}
	}
	endwin();
	return temp;
}

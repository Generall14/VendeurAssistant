#include "NCursesUIAdd.hpp"

#include "../../model/Item.hpp"
#include "../../model/Assortment.hpp"
#include "../../model/Product.hpp"
#include "NCursesUIBuilder.hpp"
#include <iostream>
#include <string>
#include <ncurses.h>

NCursesUIAdd::NCursesUIAdd(Item &item):
	_item(&item)
{

}

NCursesUIAdd::request NCursesUIAdd::Run()
{
	request temp;
	initscr();
	noecho();
	char inp[6]="\0";
	int cp =0;
	while(666)
	{
		wclear(stdscr);
		std::string tempString = ">>>>>> VendeurAssistant <<<<<<";
		int x, y;
		getmaxyx(stdscr, y, x);
		refresh();
		box(stdscr, '|', '-');
		mvprintw(2, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Dodawanie produktu";
		mvprintw(3, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Wprowadz numer produktu i wcisnij enter";
		mvprintw(6, x/2-tempString.size()/2, tempString.c_str());

		mvprintw(y-6, 5, "Co dalej?");
		mvprintw(y-5, 5, "Szukaj [s]");
		mvprintw(y-4, 5, "Zatwierdź [Enter]");
		mvprintw(y-3, 5, "Anuluj [Esc]");
		mvprintw(y-2, 5, "?> ");
		mvprintw(y-2, 8, inp);

		refresh();
		char ch;
		ch=getchar();
		if(ch=='s')
		{
			temp = request::find;
			break;
		}
		if(ch==27)
		{
			temp = request::back;
			break;
		}
		if((ch>47)&&(ch<58)&&(cp<4))
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
			Product tProduct = Assortment::Instance()->getProduct(id);
			if(!tProduct.isValid())
			{
				NCursesUIBuilder::ShowMsg("Produkt o numerze " + std::to_string(id) + " nie istnieje w bazie danych!", "Wcisnij dowolny klawisz aby kontynuowac...");
				getchar();
			}
			else
			{
				_item->setProduct(tProduct);
				temp = request::ok;
				break;
			}
		}
	}
	endwin();
	return temp;
}

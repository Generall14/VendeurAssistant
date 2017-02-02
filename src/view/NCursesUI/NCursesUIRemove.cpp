#include "NCursesUIRemove.hpp"

#include "../../model/ItemList.hpp"
#include "../../model/Item.hpp"
#include "NCursesUIBuilder.hpp"
#include <list>
#include <iostream>
#include <ncurses.h>

NCursesUIRemove::NCursesUIRemove(ItemList &itemList):
	_itemList(&itemList)
{

}

NCursesUIRemove::request NCursesUIRemove::Run()
{
	request temp;
	initscr();
	int csel=0;
	while(666)
	{
		wclear(stdscr);
		std::string tempString = ">>>>>> VendeurAssistant <<<<<<";
		int x, y, i;
		getmaxyx(stdscr, y, x);
		refresh();
		box(stdscr, '|', '-');
		mvprintw(2, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Przegladanie rachunku / usuwanie pozycji";
		mvprintw(3, x/2-tempString.size()/2, tempString.c_str());

		tempString = "Zaznacz przyciskami [8]/[2] wybrany zakup i wcisnij enter aby usunac pozycje";
		mvprintw(5, x/2-tempString.size()/2, tempString.c_str());

		int dst = y-8-4-3-3;
		mvprintw(6, 3, "Aktualna lista zakupów:");
		NCursesUIBuilder::AddHeader(7);
		int c=0, sc=0;
		for(auto it=_itemList->begin();it!=_itemList->end()&&sc<=dst;++it, ++c)
		{
			if((csel>c)&&(dst<_itemList->Size())&&(c<_itemList->Size()-dst-1))
				continue;
			NCursesUIBuilder::AddPosition(8+sc, it, c+1, c==csel);
			sc++;
		}

		mvprintw(y-5, 5, "Co dalej?");
		mvprintw(y-4, 5, "Usun zaznaczona pozycje [Enter]");
		mvprintw(y-3, 5, "Cofnij [Esc]");
		mvprintw(y-2, 5, "?> ");
		refresh();

		char ch;
		ch=getchar();

		if((ch=='8')&&(csel>0))
			csel--;
		if((ch=='2')&&(csel<_itemList->Size()-1))
			csel++;

		if((ch==KEY_ENTER||ch=='\n'||ch=='\r')&&(_itemList->Size()>0))
		{
			auto it=_itemList->begin();
			for(int i=0;i<csel;++i)
				it++;
			NCursesUIBuilder::ShowMsg("Usunac " + (*it).ProductItem().Name() + " z listy?", "Potwierdz [t] lub wcisnij jakikolwiek inny przycisk aby anulowac");
			char tchar=getchar();
			if(tchar=='t')
			{
				_itemList->RemoveItem(*it);
				csel=0;
			}
		}
		if(ch==27)
		{
			temp = request::back;
			break;
		}
	}
	endwin();
	return temp;
}

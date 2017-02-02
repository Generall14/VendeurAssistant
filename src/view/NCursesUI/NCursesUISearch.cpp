#include "NCursesUISearch.hpp"

#include "../../model/Item.hpp"
#include "../../model/Assortment.hpp"
#include "../../model/Product.hpp"
#include "NCursesUIBuilder.hpp"
#include <iostream>
#include <string>
#include <ncurses.h>
#include <list>

NCursesUISearch::NCursesUISearch(Item &item):
	_item(&item)
{

}

NCursesUISearch::request NCursesUISearch::Run()
{
	request temp;
	initscr();
	int csel=0, rsel;
	std::list<Assortment::aIterator> flist;
	char inp[10]="\0";
	int cp =0;
	while(666)
	{
		rsel=-1;
		wclear(stdscr);
		std::string tempString = ">>>>>> VendeurAssistant <<<<<<";
		int x, y, i;
		getmaxyx(stdscr, y, x);
		refresh();
		box(stdscr, '|', '-');
		mvprintw(2, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Wyszukiwanie produktu";
		mvprintw(3, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Zaznacz przyciskami [8]/[2] wybrany zakup i wcisnij enter";
		mvprintw(5, x/2-tempString.size()/2, tempString.c_str());
		tempString = "Aby zawezic liste wpisz nazwe produktu";
		mvprintw(6, x/2-tempString.size()/2, tempString.c_str());

		int dst = y-8-4-3-3;
		int c=0, sc=0;
		for(auto it=Assortment::Instance()->begin();it!=Assortment::Instance()->end()&&sc<=dst;++it, ++c)
		{
			if((*it).second.Name().find(inp)!=std::string::npos)
			{
				NCursesUIBuilder::AddPosition(8+sc, it, sc==csel);
				if(sc==csel)
					rsel=c;
				sc++;
			}
		}

		mvprintw(y-5, 5, "Co dalej?");
		mvprintw(y-4, 5, "Usun zaznaczona pozycje [Enter]");
		mvprintw(y-3, 5, "Cofnij [Esc]");
		mvprintw(y-2, 5, "?> ");
		mvprintw(y-2, 8, inp);
		refresh();

		char ch;
		ch=getchar();
		if((ch=='8')&&(csel>0))
			csel--;
		if((ch=='2')&&(csel<Assortment::Instance()->Size()-1))
			csel++;
		if(((ch>='a')&&(ch<='z')||(ch>='A')&&(ch<='Z'))&&(cp<8))
		{
			inp[cp]=ch;
			inp[++cp]=0;
			csel=0;
		}
		if((ch==127||ch==8)&&(cp>0))
			inp[--cp]=0;

		if(ch==27)
		{
			temp = request::back;
			break;
		}
		if((ch==KEY_ENTER||ch=='\n'||ch=='\r')&&(rsel>=0))
		{
			auto it=Assortment::Instance()->begin();
			for(int i=0;i<rsel;++i)
				it++;
			Product tProduct = Assortment::Instance()->getProduct((*it).second.Code());
			_item->setProduct(tProduct);
			temp = request::ok;
			break;
		}
	}
	endwin();
	return temp;
}

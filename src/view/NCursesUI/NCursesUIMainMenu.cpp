#include "NCursesUIMainMenu.hpp"

#include <iostream>
#include <ncurses.h>

NCursesUIMainMenu::request NCursesUIMainMenu::Run()
{
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
		tempString = "Menu glowne";
		mvprintw(3, x/2-tempString.size()/2, tempString.c_str());
		mvprintw(y-5, 5, "Co dalej?");
		mvprintw(y-4, 5, "Nowy rachunek [n]");
		mvprintw(y-3, 5, "Zakoncz [Esc]");
		mvprintw(y-2, 5, "?> ");
		refresh();
		char ch;
		ch=getchar();
		if(ch=='n')
		{
			temp = request::create;
			break;
		}
		if(ch==27)
		{
			temp = request::end;
			break;
		}
	}
	endwin();
	return temp;
}

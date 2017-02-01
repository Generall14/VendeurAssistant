#include "SimplestUIMainMenu.hpp"

#include <iostream>

SimplestUIMainMenu::request SimplestUIMainMenu::Run()
{
	while(666)
	{
		std::cout << "\n\n>>>>>> VendeurAssistant <<<<<<\n\nCo dalej?\nNuwy rachunek [n]\nZakończ [z]\n> " << std::flush;
		char ch;
		std::cin >> ch;
		if(ch=='n')
			return request::create;
		if(ch=='z')
			return request::end;
	}
}

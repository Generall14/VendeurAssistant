#include "SimplestUICollecting.hpp"

#include "../../model/ItemList.hpp"
#include <iostream>

SimplestUICollecting::SimplestUICollecting(ItemList &itemList):
	_itemList(&itemList)
{

}

SimplestUICollecting::request SimplestUICollecting::Run()
{
	while(666)
	{
		std::cout << "\n\n>>>>>> Budowanie listy zakupów <<<<<<\n\n";
		std::cout << "Aktualna lista:\nLiczba pozycji " << _itemList->Size() << "\nCałkowita cena " << _itemList->TotalPrice() <<
					 "\nCo dalej?\nDodaj pozycje [d]\nPrzegladaj/usuń [p]\nZakończ [z]\n> " << std::flush;
		char ch;
		std::cin >> ch;
		if(ch=='d')
			return request::add;
		if(ch=='z')
		{
			std::cout << "Zapisywanie listy..." << std::endl;
			return request::end;
		}
		if(ch=='p')
			return request::remove;
	}
}

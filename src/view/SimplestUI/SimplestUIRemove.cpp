#include "SimplestUIRemove.hpp"

#include "../../model/ItemList.hpp"
#include "../../model/Item.hpp"
#include <list>
#include <iostream>

SimplestUIRemove::SimplestUIRemove(ItemList &itemList):
	_itemList(&itemList)
{

}

SimplestUIRemove::request SimplestUIRemove::Run()
{
	while(666)
	{
		std::cout << "\n\n>>>>>> Usuwanie pozycji <<<<<<\n\n";
		std::cout << "Aktualna lista:\n";
		int c=0;
		for(auto it=_itemList->begin();it!=_itemList->end();++it, ++c)
			std::cout << "[" << c << "]: " << (*it).ProductItem().Name() << "(" << (*it).ProductItem().Code() << ") * " << (*it).Quantity() << " = " << (*it).Price() << std::endl;
		std::cout << "\nCo dalej? Wpisz numer pozycji do usunięcia lub wybierz:\nPowrót [p]\n> " << std::flush;

		std::string ch;
		std::cin >> ch;
		if(ch[0]=='p')
			return request::back;
		int id=-1;
		try
		{
			id = std::stoi (ch, nullptr);
		}
		catch(...)
		{
			std::cout << "Nieprawidłowa wartość" << std::endl;
			continue;
		}

		if((id>=0)&&(id<_itemList->Size()))
		{
			auto it=_itemList->begin();
			for(int i=0;i<id;++i)
				it++;
			std::cout << "Usunąć " << (*it).ProductItem().Name() << "(" << (*it).ProductItem().Code() << ")? Potwierdź [t] lub wciśnij jakikolwiek inny przycisk aby anulować" << std::endl;
			char tchar;
			std::cin >> tchar;
			if(tchar=='t')
				_itemList->RemoveItem(*it);
		}
		else
			std::cout << "Nieprawidłowa wartość" << std::endl;
	}
}

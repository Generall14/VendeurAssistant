#include "SimplestUIAdd.hpp"

#include "../../model/Item.hpp"
#include "../../model/Assortment.hpp"
#include "../../model/Product.hpp"
#include <iostream>
#include <string>

SimplestUIAdd::SimplestUIAdd(Item &item):
	_item(&item)
{

}

SimplestUIAdd::request SimplestUIAdd::Run()
{
	while(666)
	{
		std::cout << "\n\n>>>>>> Dodawanie produktu <<<<<<\n\nCo dalej?\nPodaj numer produktu lub wciśnij:\nAnuluj [a]\nSzukaj [s]\n> " << std::flush;
		std::string ch;
		std::cin >> ch;
		if(ch[0]=='a')
			return request::back;
		if(ch[0]=='s')
			return request::find;
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

		Product tProduct = Assortment::Instance()->getProduct(id);
		if(!tProduct.isValid())
			std::cout << "Produkt o numerze " << id << " nie istnieje w bazie danych" << std::endl;
		else
		{
			_item->setProduct(tProduct);
			return request::ok;
		}
	}
}

#include "SimplestUIQuantity.hpp"

#include "../../model/Item.hpp"
#include "../../model/Assortment.hpp"
#include "../../model/Product.hpp"
#include <iostream>
#include <string>

SimplestUIQuantity::SimplestUIQuantity(Item &item):
	_item(&item)
{

}

SimplestUIQuantity::request SimplestUIQuantity::Run()
{
	while(666)
	{
		std::cout << "\n\n>>>>>> Wprowadzanie ilości <<<<<<\n\nCo dalej?\nPodaj ";
		if(_item->ProductItem().Unit()==Product::weight)
			std::cout << "masę";
		else
			std::cout << "ilość";

		std::cout << " dla produktu " << _item->ProductItem().Name() << "[" << _item->ProductItem().Code() << "] lub wciśnij:\nCofnij [c]\nAnuluj [a]\n> " << std::flush;
		std::string ch;
		std::cin >> ch;
		if(ch[0]=='a')
			return request::cancel;
		if(ch[0]=='c')
			return request::back;
		float qu= -1;
		try
		{
			qu = std::stof (ch, nullptr);
		}
		catch(...)
		{
			std::cout << "Nieprawidłowa wartość" << std::endl;
			continue;
		}

		if(qu<=0)
			std::cout << "Nieprawidłowa wartość" << std::endl;
		else
		{
			_item->setQuantity(qu);
			return request::ok;
		}
	}
}

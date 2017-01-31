#include "SimplestUISearch.hpp"

#include "../../model/Item.hpp"
#include "../../model/Assortment.hpp"
#include "../../model/Product.hpp"
#include <iostream>
#include <string>

SimplestUISearch::SimplestUISearch(Item &item):
	_item(&item)
{

}

SimplestUISearch::request SimplestUISearch::Run()
{
	std::cout << "\n\n>>>>>> Wyszukiwanie produktu <<<<<<\nW aktualnej wersji SimplestUI nie zaimplementowano wyszukiwania produktów\n" << std::flush;
	return request::back;
}

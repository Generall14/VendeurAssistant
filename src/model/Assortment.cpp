#include "Assortment.hpp"
#include "DataLoader.hpp"

#include <stdexcept>

Assortment* Assortment::_instance = 0;

void Assortment::LoadData(DataLoader &loader)
{
	loader.LoadData(this);
}

Assortment::aIterator Assortment::begin()
{
	return _mapa.begin();
}

Assortment::aIterator Assortment::end()
{
	return _mapa.end();
}

Product Assortment::getProduct(int id)
{
	try
	{
		Product temp = _mapa.at(id);
		return temp;
	}
	catch(std::out_of_range)
	{
		return Product();
	}
}

Assortment* Assortment::Instance()
{
	if(!_instance)
		_instance = new Assortment();
	return _instance;
}

void Assortment::addProduct(Product pr)
{
	if(pr.isValid())
		_mapa.insert(std::pair<int,Product>(pr.Code(), pr));
}

#include "Assortment.hpp"
#include "DataLoader.hpp"

#include <stdexcept>

Assortment::Assortment(DataLoader &loader)
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

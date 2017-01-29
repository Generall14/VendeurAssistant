#ifndef ASSORTMENT_HPP
#define ASSORTMENT_HPP

#include <map>
#include "Product.hpp"

class DataLoader;

class Assortment
{
	friend class DataLoaderXML;
public:
	Assortment(DataLoader &loader);

	Product getProduct(int id);

	typedef std::map<int, Product>::iterator aIterator;
	aIterator begin();
	aIterator end();

private:
	std::map<int, Product> _mapa;
};

#endif

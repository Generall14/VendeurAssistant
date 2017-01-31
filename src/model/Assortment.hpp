#ifndef ASSORTMENT_HPP
#define ASSORTMENT_HPP

#include <map>
#include "Product.hpp"

class DataLoader;

class Assortment
{
public:
	static Assortment* Instance();

	void LoadData(DataLoader &loader);
	Product getProduct(int id);
	void addProduct(Product pr);

	typedef std::map<int, Product>::iterator aIterator;
	aIterator begin();
	aIterator end();

private:
	static Assortment* _instance;
	std::map<int, Product> _mapa;

	Assortment(){}
};

#endif

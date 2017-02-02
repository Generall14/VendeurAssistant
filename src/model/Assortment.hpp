/**
 * @class Assortment
 * @brief Zbiór produktów.
 *
 * Reprezentuje zbiór dostępnych towarów, dzięki dziedziczeniu z wzorca Singleton możliwy jest dostęp do niej z dowolnego miejsca programu. Aby załadować
 * dane należy wywołać funkcję LoadData(...) z odpowiednim obiektem interfejsu DataLoader.
 */
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
	int Size() const;

	typedef std::map<int, Product>::iterator aIterator;
	aIterator begin();
	aIterator end();

private:
	static Assortment* _instance;
	std::map<int, Product> _mapa;

	Assortment(){}
};

#endif

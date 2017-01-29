#ifndef ITEM_HPP
#define ITEM_HPP

#include "Product.hpp"

class Item
{
public:
	Item(Product produkt, float ilosc);

	Product ProductItem() const;
	float Quantity() const;
	float Price() const;

	bool operator==(const Item &r);

private:
	Product _produkt;
	float _ilosc;
};

#endif

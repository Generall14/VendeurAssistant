#include "Item.hpp"

Item::Item(Product produkt, float ilosc):
	_produkt(produkt),
	_ilosc(ilosc)
{

}

Product Item::ProductItem() const
{
	return _produkt;
}

float Item::Quantity() const
{
	return _ilosc;
}

float Item::Price() const
{
	return _ilosc*_produkt.Price();
}

bool Item::operator==(const Item &r)
{
	if(_ilosc!=r.Quantity())
		return false;
	if(_produkt==r.ProductItem())
		return true;
	return false;
}

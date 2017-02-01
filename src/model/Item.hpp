/**
 * @class Item
 * @brief Pojedynczy zakup.
 *
 * Reprezentuje pojedynczą pozycję na liście zakupów, zawiera obiekt Product oraz zakupioną ilość. Klasa wykorzystywana w ItemList.
 */
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

	void setProduct(Product product);
	void setQuantity(float quantity);

	bool operator==(const Item &r);

private:
	Product _produkt;
	float _ilosc;
};

#endif

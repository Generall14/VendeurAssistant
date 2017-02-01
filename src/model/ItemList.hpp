/**
 * @class ItemList
 * @brief Lista zakupów.
 *
 * Zbiera obiekty Item w jednej liście jako rachunek klienta. Lista może być zapisana (wydrukowana) poprzez wywołanie metody SaveList() z odpowiednim obiektem
 * z interfejsem ListSaver.
 */
#ifndef ITEMLIST_HPP
#define ITEMLIST_HPP

#include <list>
#include "Item.hpp"

class ListSaver;

class ItemList
{
public:
	ItemList();

	typedef std::list<Item>::iterator iIterator;
	iIterator begin();
	iIterator end();

	void AddItem(Item item);
	void RemoveItem(Item item);
	int Size() const;
	float TotalPrice() const;
	void SaveList(ListSaver &saver);

private:
	std::list<Item> _lista;
};

#endif

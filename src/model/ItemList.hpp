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

#include "ItemList.hpp"
#include "ListSaver.hpp"

ItemList::ItemList()
{

}

ItemList::iIterator ItemList::begin()
{
	return _lista.begin();
}

ItemList::iIterator ItemList::end()
{
	return _lista.end();
}

void ItemList::AddItem(Item item)
{
	_lista.push_back(item);
}

void ItemList::RemoveItem(Item item)
{
	_lista.remove(item);
}

int ItemList::Size() const
{
	return _lista.size();
}

void ItemList::SaveList(ListSaver& saver)
{
	saver.SaveList(this);
}

float ItemList::TotalPrice() const
{
	float temp = 0;
	for(std::list<Item>::const_iterator it = _lista.begin();it!=_lista.end();++it)
		temp += it->Price();
	return temp;
}

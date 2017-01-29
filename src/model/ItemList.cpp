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

void ItemList::SaveList(ListSaver* saver) const
{
	saver->SaveList(this);
}

#ifndef LISTSAVER_HPP
#define LISTSAVER_HPP

class ItemList;

class ListSaver
{
public:
	ListSaver(){}
	virtual ~ListSaver(){}

	virtual void SaveList(const ItemList* lista) = 0;
};

#endif

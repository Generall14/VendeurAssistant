#ifndef LISTSAVER_HPP
#define LISTSAVER_HPP

class ItemList;

class ListSaver
{
public:
	ListSaver(){}
	virtual ~ListSaver(){}

	virtual void SaveList(ItemList* lista) = 0;
};

#endif

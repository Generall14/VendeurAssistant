/**
 * @class ListSaver
 * @brief Interfejs zapisywania ItemList.
 *
 * Obiekty dziedziczące dany interfejs wykorzystywane są w ItemList do zapisywania danych.
 */
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

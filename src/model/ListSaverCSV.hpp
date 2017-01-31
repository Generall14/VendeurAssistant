#ifndef LISTSAVERCSV_HPP
#define LISTSAVERCSV_HPP

#include <string>
#include "ListSaver.hpp"

class ItemList;

class ListSaverCSV : public ListSaver
{
public:
	ListSaverCSV(std::string prefix="log/bills/bill");
	virtual ~ListSaverCSV(){}

	virtual void SaveList(ItemList* lista);

private:
	std::string _prefix;
};

#endif

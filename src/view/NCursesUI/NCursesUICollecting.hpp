#ifndef NCURSESUICOLLECTING_HPP
#define NCURSESUICOLLECTING_HPP

#include "../../controller/State.hpp"

class ItemList;

class NCursesUICollecting : public State
{
public:
	NCursesUICollecting(ItemList& itemList);

	virtual request Run();

private:
	ItemList* _itemList=0;
};

#endif

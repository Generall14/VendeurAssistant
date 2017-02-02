#ifndef NCURSESUIREMOVE_HPP
#define NCURSESUIREMOVE_HPP

#include "../../controller/State.hpp"

class ItemList;

class NCursesUIRemove : public State
{
public:
	NCursesUIRemove(ItemList& itemList);

	virtual request Run();

private:
	ItemList* _itemList=0;
};

#endif

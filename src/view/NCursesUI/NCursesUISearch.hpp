#ifndef NCURSESUISEARCH_HPP
#define NCURSESUISEARCH_HPP

#include "../../controller/State.hpp"

class Item;

class NCursesUISearch : public State
{
public:
	NCursesUISearch(Item& item);

	virtual request Run();

private:
	Item* _item=0;
};

#endif

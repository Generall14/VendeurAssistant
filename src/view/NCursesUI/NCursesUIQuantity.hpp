#ifndef NCURSESUIQUANTITY_HPP
#define NCURSESUIQUANTITY_HPP

#include "../../controller/State.hpp"

class Item;

class NCursesUIQuantity : public State
{
public:
	NCursesUIQuantity(Item& item);

	virtual request Run();

private:
	Item* _item=0;
};

#endif

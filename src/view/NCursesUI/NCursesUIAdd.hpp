#ifndef NCURSESUIADD_HPP
#define NCURSESUIADD_HPP

#include "../../controller/State.hpp"

class Item;

class NCursesUIAdd : public State
{
public:
	NCursesUIAdd(Item& item);

	virtual request Run();

private:
	Item* _item=0;
};

#endif

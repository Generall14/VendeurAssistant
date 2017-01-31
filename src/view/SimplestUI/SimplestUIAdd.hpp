#ifndef SIMPLESTUIADD_HPP
#define SIMPLESTUIADD_HPP

#include "../../controller/State.hpp"

class Item;

class SimplestUIAdd : public State
{
public:
	SimplestUIAdd(Item& item);

	virtual request Run();

private:
	Item* _item=0;
};

#endif

#ifndef SIMPLESTUIQUANTITY_HPP
#define SIMPLESTUIQUANTITY_HPP

#include "../../controller/State.hpp"

class Item;

class SimplestUIQuantity : public State
{
public:
	SimplestUIQuantity(Item& item);

	virtual request Run();

private:
	Item* _item=0;
};

#endif

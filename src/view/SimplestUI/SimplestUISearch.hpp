#ifndef SIMPLESTUISEARCH_HPP
#define SIMPLESTUISEARCH_HPP

#include "../../controller/State.hpp"

class Item;

class SimplestUISearch : public State
{
public:
	SimplestUISearch(Item& item);

	virtual request Run();

private:
	Item* _item=0;
};

#endif

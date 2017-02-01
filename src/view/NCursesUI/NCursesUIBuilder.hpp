/**
 * @class NCursesUIBuilder
 * @brief Budowniczy dla UI typu NCursesUI.
 */
#ifndef NCURSESUIBUILDER_HPP
#define NCURSESUIBUILDER_HPP

#include "../../controller/StateBuilder.hpp"
#include <string>

class State;
class Item;
class ItemList;

class NCursesUIBuilder : public StateBuilder
{
public:
	NCursesUIBuilder();
	virtual ~NCursesUIBuilder(){}

	virtual void InitMenuSystem();
	virtual void ClearMenuSystem();
	virtual State* BuildMainMenu();
	virtual State* BuildCollectingState(ItemList&itemList);
	virtual State* BuildRemoveMenu(ItemList&itemList);
	virtual State* BuildAddMenu(Item& item);
	virtual State* BuildQuantityMenu(Item& item);
	virtual State* BuildSearchMenu(Item& item);

	static void ShowMsg(std::string msg, std::string opt="");
};

#endif

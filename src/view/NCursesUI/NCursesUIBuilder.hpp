/**
 * @class NCursesUIBuilder
 * @brief Budowniczy dla UI typu NCursesUI.
 */
#ifndef NCURSESUIBUILDER_HPP
#define NCURSESUIBUILDER_HPP

#include "../../controller/StateBuilder.hpp"
#include "../../model/ItemList.hpp"
#include "../../model/Assortment.hpp"
#include <string>

class State;
class Item;

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
	static void AddHeader(int y);
	static void AddPosition(int y, ItemList::iIterator it, int c, bool sel=false);
	static void AddPosition(int y, Assortment::aIterator it, bool sel=false);
};

#endif

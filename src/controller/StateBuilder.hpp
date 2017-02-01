/**
 * @class StateBuilder
 * @brief Interfejs budowania obiektów State.
 *
 * Wymusza metody budowania poszczególnych obiektów dla UI. Obiekty dziedziczące dany interfejs wykorzystywane są w MainStateMachine do generowania UI.
 */
#ifndef STATEBUILDER_HPP
#define STATEBUILDER_HPP

class State;
class Item;
class ItemList;

class StateBuilder
{
public:
	StateBuilder(){}
	virtual ~StateBuilder(){}

	virtual void InitMenuSystem() = 0;
	virtual void ClearMenuSystem() = 0;
	virtual State* BuildMainMenu() = 0;/**<Główne menu*/
	virtual State* BuildCollectingState(ItemList&) = 0;/**<Tworzenie rachunku*/
	virtual State* BuildRemoveMenu(ItemList&) = 0;/**<Przeglądanie i usuwanie elementów rachunku*/
	virtual State* BuildAddMenu(Item&) = 0;/**<Dodawanie nowego zakupu*/
	virtual State* BuildQuantityMenu(Item&) = 0;/**<Wprowadzanie ilości*/
	virtual State* BuildSearchMenu(Item&) = 0;/**<Wyszukiwanie produktu*/
};

#endif

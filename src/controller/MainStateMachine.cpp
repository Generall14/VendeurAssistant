#include "MainStateMachine.hpp"

#include <iostream>
#include "StateBuilder.hpp"
#include "State.hpp"
#include "../model/ItemList.hpp"
#include "../model/Assortment.hpp"
#include "../model/Item.hpp"

MainStateMachine::MainStateMachine(MainBuilder* builder):
	_builder(builder)
{
	Assortment::Instance()->LoadData(_builder->BuildDataLoader());
	_builder->BuildStateBuilder().InitMenuSystem();
}

MainStateMachine::~MainStateMachine()
{
	delete _builder;
}

void MainStateMachine::DoStateMachine()
{
	std::cout << "Entering main state machine" << std::endl;
	State* tState=0;
	State::request req;

	ItemList* currItemList=0;
	Item tempItem(Product(), -1);

	while(666)
	{
		switch (_currentState)
		{
		//===================== Main menu =============================
		case mainMenuState:
			std::cout << "MainStateMachine: Main menu" << std::endl;
			tState = _builder->BuildStateBuilder().BuildMainMenu();
			req = tState->Run();
			delete tState;
			tState = 0;
			if(req==State::create)
			{
				currItemList = new ItemList();
				_currentState = collectingState;
			}
			if(req==State::end)
				return;
			break;
		//===================== Collecting ============================
		case collectingState:
			std::cout << "MainStateMachine: Budowanie listy" << std::endl;
			tState = _builder->BuildStateBuilder().BuildCollectingState(*currItemList);
			req = tState->Run();
			delete tState;
			tState = 0;
			if(req==State::add)
				_currentState = addState;
			if(req==State::remove)
				_currentState = removeState;
			if(req==State::end)
			{
				currItemList->SaveList(_builder->BuildListSaver());
				delete currItemList;
				currItemList = 0;
				_currentState = mainMenuState;
			}
			break;
		//===================== Add item ==============================
		case addState:
			std::cout << "MainStateMachine: Dodawanie produktu" << std::endl;
			tempItem.setProduct(Product());
			tState = _builder->BuildStateBuilder().BuildAddMenu(tempItem);
			req = tState->Run();
			delete tState;
			tState = 0;
			if(req==State::back)
				_currentState = collectingState;
			if(req==State::find)
				_currentState = findState;
			if(req==State::ok)
				_currentState = quantityState;
			break;
		//===================== Set quantity ==========================
		case quantityState:
			std::cout << "MainStateMachine: Wprowadzanie ilości" << std::endl;
			tState = _builder->BuildStateBuilder().BuildQuantityMenu(tempItem);
			req = tState->Run();
			delete tState;
			tState = 0;
			if(req==State::back)
				_currentState = addState;
			if(req==State::cancel)
				_currentState = collectingState;
			if(req==State::ok)
			{
				std::cout << "==================================================" << std::endl;
				std::cout << tempItem.Quantity() << std::endl;
				std::cout << tempItem.ProductItem().isValid() << std::endl;
				if(tempItem.ProductItem().isValid()&&tempItem.Quantity()>0)
					currItemList->AddItem(tempItem);
				std::cout << currItemList->Size() << std::endl;
				_currentState = collectingState;
			}
			break;
		//===================== Remove elements =======================
		case removeState:
			std::cout << "MainStateMachine: Usuwanie pozycji" << std::endl;
			tState = _builder->BuildStateBuilder().BuildRemoveMenu(*currItemList);
			req = tState->Run();
			delete tState;
			tState = 0;
			if(req==State::back)
				_currentState = collectingState;
			break;
		//===================== Find product ==========================
		case findState:
			std::cout << "MainStateMachine: Wyszukiwanie pozycji" << std::endl;
			tState = _builder->BuildStateBuilder().BuildSearchMenu(tempItem);
			req = tState->Run();
			delete tState;
			tState = 0;
			if(req==State::back)
				_currentState = addState;
			if(req==State::ok)
				_currentState = quantityState;
			break;
		}
	}

	std::cout << "Leaving main state machine" << std::endl;
}

#include "MainStateMachine.hpp"

#include "../osrc/Log.hpp"
#include "StateBuilder.hpp"
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

State::request MainStateMachine::RunState(State* state)
{
	State::request req = state->Run();
	delete state;
	return req;
}

void MainStateMachine::DoStateMachine()
{
	Log::I()->S() << "Entering main state machine" << std::endl;
//	State* tState=0;
	State::request req;

	ItemList* currItemList=0;
	Item tempItem(Product(), -1);

	while(666)
	{
		switch (_currentState)
		{
		//===================== Main menu =============================
		case mainMenuState:
			Log::I()->S() << "MainStateMachine: Main menu" << std::endl;
			req = RunState(_builder->BuildStateBuilder().BuildMainMenu());
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
			Log::I()->S() << "MainStateMachine: Budowanie listy" << std::endl;
			req = RunState(_builder->BuildStateBuilder().BuildCollectingState(*currItemList));
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
			Log::I()->S() << "MainStateMachine: Dodawanie produktu" << std::endl;
			req = RunState(_builder->BuildStateBuilder().BuildAddMenu(tempItem));
			tempItem.setProduct(Product());
			if(req==State::back)
				_currentState = collectingState;
			if(req==State::find)
				_currentState = findState;
			if(req==State::ok)
				_currentState = quantityState;
			break;
		//===================== Set quantity ==========================
		case quantityState:
			Log::I()->S() << "MainStateMachine: Wprowadzanie ilości" << std::endl;
			req = RunState(_builder->BuildStateBuilder().BuildQuantityMenu(tempItem));
			if(req==State::back)
				_currentState = addState;
			if(req==State::cancel)
				_currentState = collectingState;
			if(req==State::ok)
			{
				if(tempItem.ProductItem().isValid()&&tempItem.Quantity()>0)
					currItemList->AddItem(tempItem);
				_currentState = collectingState;
			}
			break;
		//===================== Remove elements =======================
		case removeState:
			Log::I()->S() << "MainStateMachine: Usuwanie pozycji" << std::endl;
			req = RunState(_builder->BuildStateBuilder().BuildRemoveMenu(*currItemList));
			if(req==State::back)
				_currentState = collectingState;
			break;
		//===================== Find product ==========================
		case findState:
			Log::I()->S() << "MainStateMachine: Wyszukiwanie pozycji" << std::endl;
			req = RunState(_builder->BuildStateBuilder().BuildSearchMenu(tempItem));
			if(req==State::back)
				_currentState = addState;
			if(req==State::ok)
				_currentState = quantityState;
			break;
		}
	}

	_builder->BuildStateBuilder().ClearMenuSystem();

	Log::I()->S() << "Leaving main state machine" << std::endl;
}

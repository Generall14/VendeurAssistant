#include "MainStateMachine.hpp"

#include <iostream>
#include "StateBuilder.hpp"
#include "State.hpp"

MainStateMachine::MainStateMachine(MainBuilder* builder):
	_builder(builder)
{
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
			if(req==State::create)
				_currentState = collectingState;
			if(req==State::end)
				return;
			break;
		default:
			break;
		}
	}

	std::cout << "Leaving main state machine" << std::endl;
}

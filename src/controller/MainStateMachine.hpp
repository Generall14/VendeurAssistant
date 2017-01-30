#ifndef MAINSTATEMACHINE_HPP
#define MAINSTATEMACHINE_HPP

#include "MainBuilder.hpp"

class MainStateMachine
{
public:
	MainStateMachine(MainBuilder* builder = new MainBuilder());
	~MainStateMachine();

	void DoStateMachine();

private:
	enum state{mainMenuState, collectingState, removeState, addState, findState, quantityState};

	MainBuilder* _builder;
	state _currentState=mainMenuState;

};

#endif

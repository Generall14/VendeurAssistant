/**
 * @class MainStateMachine
 * @brief Główna klasa programu.
 *
 * Klasa zarządza pozostałymi obiektami, steruje UI za pomocą maszyny stanu. Program konfigurowany jest za pomocą obiektu implementującego MainBuilder
 * podawanego w konstruktorze.
 */
#ifndef MAINSTATEMACHINE_HPP
#define MAINSTATEMACHINE_HPP

#include "MainBuilder.hpp"
#include "State.hpp"

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

	State::request RunState(State* state);

};

#endif

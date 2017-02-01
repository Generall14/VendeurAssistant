/**
 * @class State
 * @brief Interfejs obiektów stanu.
 */
#ifndef STATE_HPP
#define STATE_HPP

class State
{
public:
	State(){}
	virtual ~State(){}

	enum request{create, end, add, remove, back, cancel, ok, find};

	virtual request Run() = 0;
};

#endif

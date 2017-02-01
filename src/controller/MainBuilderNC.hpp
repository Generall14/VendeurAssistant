/**
 * @class MainBuilderNC
 * @brief Główny budowniczy systemu dla NCourses UI.
 */
#ifndef MAINBUILDERNC_HPP
#define MAINBUILDERNC_HPP

#include <string>
#include "MainBuilder.hpp"
#include "../view/NCursesUI/NCursesUIBuilder.hpp"

class DataLoader;
class ListSaver;
class StateBuilder;

class MainBuilderNC : public MainBuilder
{
public:
	MainBuilderNC(std::string inputDataFile="data.xml");

protected:
	virtual void InitStateBuilder();
};

#endif

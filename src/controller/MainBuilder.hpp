/**
 * @class MainBuilder
 * @brief Główny budowniczy systemu.
 *
 * Zwraca wskaźniki do reprezentacji interfejsów DataLoader, ListSaver, StateBuilder. Konfigurowanie programu polega na zwracaniu wybranych implementacji wspomnianych
 * interfejsów.
 */
#ifndef MAINBUILDER_HPP
#define MAINBUILDER_HPP

#include <string>

class DataLoader;
class ListSaver;
class StateBuilder;

class MainBuilder
{
public:
	MainBuilder(std::string inputDataFile="data.xml");
	virtual ~MainBuilder();

	DataLoader& BuildDataLoader();
	ListSaver& BuildListSaver();
	StateBuilder& BuildStateBuilder();

protected:
	std::string file;
	DataLoader* _dataLoader=0;
	ListSaver* _listSaver=0;
	StateBuilder* _stateBuilder=0;

	virtual void InitDataLoader();
	virtual void InitListSaver();
	virtual void InitStateBuilder();
};

#endif

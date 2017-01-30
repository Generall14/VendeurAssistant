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

	virtual void Init();
};

#endif

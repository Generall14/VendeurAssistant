#include "MainBuilder.hpp"
#include "../model/DataLoader.hpp"
#include "../model/DataLoaderXML.hpp"
#include "../model/ListSaver.hpp"
#include "StateBuilder.hpp"
#include "../view/SimplestUI/SimplestUIBuilder.hpp"
#include "../model/ListSaverCSV.hpp"

MainBuilder::MainBuilder(std::string inputDataFile):
	file(inputDataFile)
{
	Init();
}

MainBuilder::~MainBuilder()
{
	delete _stateBuilder;
	delete _listSaver;
	delete _dataLoader;
}

DataLoader &MainBuilder::BuildDataLoader()
{
	return *_dataLoader;
}

ListSaver &MainBuilder::BuildListSaver()
{
	return *_listSaver;
}

StateBuilder &MainBuilder::BuildStateBuilder()
{
	return *_stateBuilder;
}

void MainBuilder::Init()
{
	_stateBuilder = new SimplestUIBuilder();
	_listSaver = new ListSaverCSV();
	_dataLoader = new DataLoaderXML(file);
}

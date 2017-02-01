#include "MainBuilder.hpp"
#include "../model/DataLoader.hpp"
#include "../model/DataLoaderXML.hpp"
#include "../model/ListSaver.hpp"
#include "StateBuilder.hpp"
#include "../view/SimplestUI/SimplestUIBuilder.hpp"
#include "../model/ListSaverCSV.hpp"
#include "../osrc/Log.hpp"

MainBuilder::MainBuilder(std::string inputDataFile):
	file(inputDataFile)
{
}

MainBuilder::~MainBuilder()
{
	delete _stateBuilder;
	delete _listSaver;
	delete _dataLoader;
}

DataLoader &MainBuilder::BuildDataLoader()
{
	if(!_dataLoader)
		InitDataLoader();
	return *_dataLoader;
}

ListSaver &MainBuilder::BuildListSaver()
{
	if(!_listSaver)
		InitListSaver();
	return *_listSaver;
}

StateBuilder &MainBuilder::BuildStateBuilder()
{
	if(!_stateBuilder)
		InitStateBuilder();
	return *_stateBuilder;
}

void MainBuilder::InitDataLoader()
{
	Log::I()->S() << "InitDataLoader: DataLoaderXML" << std::endl;
	_dataLoader = new DataLoaderXML(file);
}

void MainBuilder::InitListSaver()
{
	Log::I()->S() << "InitListSaver: ListSaverCSV" << std::endl;
	_listSaver = new ListSaverCSV();
}

void MainBuilder::InitStateBuilder()
{
	Log::I()->S() << "InitStateBuilder: SimplestUIBuilder" << std::endl;
	_stateBuilder = new SimplestUIBuilder();
}

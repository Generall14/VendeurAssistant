#include "MainBuilderNC.hpp"
#include "../osrc/Log.hpp"

MainBuilderNC::MainBuilderNC(std::string inputDataFile):
	MainBuilder(inputDataFile)
{

}

void MainBuilderNC::InitStateBuilder()
{
	Log::I()->S() << "InitStateBuilder: NCursesUIBuilder" << std::endl;
	_stateBuilder = new NCursesUIBuilder();
}

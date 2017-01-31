#include "Log.hpp"

Log* Log::_instance=0;

Log::Log(std::string adres)
{
	file.open(adres, std::fstream::out | std::fstream::trunc);
}

Log* Log::I()
{
	if(!_instance)
		_instance = new Log();
	return _instance;
}

std::ofstream& Log::S()
{
	return file;
}

void Log::Close()
{
	file.close();
}

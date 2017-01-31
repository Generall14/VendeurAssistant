#ifndef LOG_HPP
#define LOG_HPP

#include <fstream>
#include <string>

class Log
{
public:
	static Log* I();
	std::ofstream& S();

	void Close();

private:
	static Log* _instance;
	std::ofstream file;
	Log(std::string adres="log/lastLog.txt");
};

#endif

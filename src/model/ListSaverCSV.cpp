#include "ListSaverCSV.hpp"

#include <fstream>
#include <ctime>
#include "ItemList.hpp"
#include "Item.hpp"
#include "../osrc/Log.hpp"

ListSaverCSV::ListSaverCSV(std::string prefix):
	_prefix(prefix)
{

}

void ListSaverCSV::SaveList(ItemList* lista)
{
	time_t czas;
	struct tm* data;
	time(&czas);
	data = localtime(&czas);
	char buf[40];
	sprintf(buf, "%.4i-%.2i-%.2i_%.2i:%.2i:%.2i", data->tm_year+1900, data->tm_mon, data->tm_mday, data->tm_hour, data->tm_min, data->tm_sec);

	std::string filename(buf);
	filename.insert(0, _prefix+"_");
	filename += ".csv";

	std::ofstream file;
	file.open (filename, std::fstream::out | std::fstream::trunc);
	if(!file.is_open())
	{
		Log::I()->S() << "ListSaverSCV: Błąd otwierania pliku " << filename << std::endl;
		return;
	}

	file << "Rachunek z " << buf << "\r\n\r\n";
	file << ";Pozycja nr.;Nazwa produktu;Id produktu;Cena jednostkowa;Ilość;Cena całkowita\r\n";
	int c=0;
	for(auto it=lista->begin();it!=lista->end();++it, ++c)
		file << ";" << c << ";" << (*it).ProductItem().Name() << ";" << (*it).ProductItem().Code() << ";" << (*it).ProductItem().Price() << ";" <<
					 (*it).Quantity() << ";" << (*it).Price() << "\r\n";
	file << "\r\n;;;;;Suma:;" << lista->TotalPrice() << "\r\n";

	file.close();
}

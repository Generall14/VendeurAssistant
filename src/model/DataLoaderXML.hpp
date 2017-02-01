/**
 * @class DataLoaderXML
 * @brief Implementacja interfejsu DataLoader. Wczytuje dane z pliku xml.
 */
#ifndef DATALOADERXML_HPP
#define DATALOADERXML_HPP

#include <string>
#include "DataLoader.hpp"

class Assortment;

class DataLoaderXML : public DataLoader
{
public:
	DataLoaderXML(std::string adres);
	virtual ~DataLoaderXML(){}

	virtual void LoadData(Assortment* assortment);

private:
	std::string _adres;
};

#endif

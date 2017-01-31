#include "DataLoaderXML.hpp"
#include "../osrc/pugixml.hpp"
#include "Product.hpp"
#include "Assortment.hpp"
#include <iostream>

DataLoaderXML::DataLoaderXML(std::string adres):
	_adres(adres)
{

}

void DataLoaderXML::LoadData(Assortment *assortment)
{
	pugi::xml_document dok;
	pugi::xml_parse_result wynik = dok.load_file(_adres.c_str());
	if(!wynik)
	{
		std::cout << "nie można otworzyć pliku " << _adres << std::endl;
		return;
	}

	pugi::xml_node mainNode = dok.child("MasterSalesmanData");
	std::string tempDesc, tempUnit;
	int tempId;
	float tempPrice;
	Product::unit tempPUnit;
	for(pugi::xml_node_iterator it=mainNode.begin();it!=mainNode.end();++it)
	{
		tempDesc = "";
		tempUnit = "";
		tempId = -1;
		tempPrice = -1;
		tempPUnit = Product::item;

		tempDesc = it->attribute("desc").as_string();
		tempId = it->attribute("id").as_int();
		tempUnit = it->attribute("unit").as_string();
		tempPrice = it->attribute("price").as_float();

		if(!tempUnit.compare("weight"))
			tempPUnit = Product::weight;

		std::cout << "Odczytane dane " << tempDesc << " " << tempId << " " << tempPrice << " " << tempUnit << std::endl;
		Product temp(tempDesc, tempId, tempPrice, tempPUnit);
		if(!temp.isValid())
		{
			std::cout << "Nieprawidłowe parametry, odrzucam pozycje" << std::endl;
			continue;
		}

		assortment->addProduct(temp);
	}
}

#include "osrc/Log.hpp"
#include "controller/MainStateMachine.hpp"
#include "osrc/pugixml.hpp"
#include "model/DataLoaderXML.hpp"
#include "model/Assortment.hpp"

using namespace std;

int main()
{
	Log::I()->S() << "Start" << endl;

	MainStateMachine mst;
	mst.DoStateMachine();

	//Generowanie wzorca dla plików z danymi:
//	pugi::xml_document xmldoc;
//	pugi::xml_node mainNode = xmldoc.append_child("MasterSalesmanData");
//	for(int i=0;i<4;++i)
//	{
//		pugi::xml_node itemNode = mainNode.append_child("Item");
//		itemNode.append_attribute("id") = (i+6)*3;
//		itemNode.append_attribute("desc") = "produkt xxx";
//		itemNode.append_attribute("price") = 2.66;
//		itemNode.append_attribute("unit") = "item";
//	}
//	xmldoc.save_file("data.xml");

	Log::I()->S() << "Koniec" << endl;
	Log::I()->Close();
	return 0;
}

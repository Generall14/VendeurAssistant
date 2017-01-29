#include <iostream>
#include "model/Product.hpp"
#include "model/Item.hpp"
#include "model/DataLoaderXML.hpp"
#include "model/Assortment.hpp"
#include "model/ItemList.hpp"

using namespace std;

int main()
{
	cout << "Start" << endl;

	Product a("asd", 666, 2.56, Product::weight);
	Item it(a, 2.33);
	DataLoaderXML dl("asd");
	Assortment as(dl);
	ItemList il();

	cout << "Koniec" << endl;
	return 0;
}

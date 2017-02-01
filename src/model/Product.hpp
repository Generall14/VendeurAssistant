/**
 * @class Product
 * @brief Podstawowy produkt.
 *
 * Reprezentuje poszczególny rodzaj produktu. Przechowuje dane takie jak nazwa produktu, kod produktu, cena oraz jednostka (waga/sztuka). Wykorzystywana w klasach
 * Assortment oraz Item.
 */
#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product
{
public:
	enum unit{weight, item};												/**<Jednostki produktu*/

	Product(std::string nazwa, int kod, float cena, unit jednostka=item);
	Product();

	std::string Name() const;
	int Code() const;
	float Price() const;
	unit Unit() const;
	bool isValid() const;

	bool operator==(const Product &r);

private:
	int _kod;
	float _cena;
	std::string _nazwa;
	unit _jednostka;
};

#endif

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product
{
public:

	enum unit{weight, item};

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

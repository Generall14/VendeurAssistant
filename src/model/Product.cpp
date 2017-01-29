#include "Product.hpp"

Product::Product(std::string nazwa, int kod, float cena, unit jednostka):
	_kod(kod),
	_cena(cena),
	_nazwa(nazwa),
	_jednostka(jednostka)
{

}

Product::Product():
	Product("Nieprawidłowy produkt", -1, -1.0)
{

}

std::string Product::Name() const
{
	return _nazwa;
}

int Product::Code() const
{
	return _kod;
}

float Product::Price() const
{
	return _cena;
}

Product::unit Product::Unit() const
{
	return _jednostka;
}

bool Product::operator==(const Product &r)
{
	if(_kod!=r.Code())
		return false;
	if(_cena!=r.Price())
		return false;
	if(_nazwa.compare(r.Name()))
		return false;
	if(_jednostka!=r.Unit())
		return false;
	return true;
}

bool Product::isValid() const
{
	if((_cena>=0)&&(_kod>=0))
		return true;
	return false;
}

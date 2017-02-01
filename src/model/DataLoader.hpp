/**
 * @class DataLoader
 * @brief Interfejs wczytywania danych do Assortment.
 *
 * Obiekty dziedziczące dany interfejs wykorzystywane są w Assortment do wczytywania danych.
 */
#ifndef DATALOADER_HPP
#define DATALOADER_HPP

class Assortment;

class DataLoader
{
public:
	DataLoader(){}
	virtual ~DataLoader(){}

	virtual void LoadData(Assortment* assortment) = 0;
};

#endif

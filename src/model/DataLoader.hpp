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

#pragma once
#include "Currency.h"
#include <iostream>
#include <string>

class Euro : public Currency
{
protected:

public:
	//Constructor
	Euro();
	//Constructor to accept initialization values
	Euro(int wh, int fr);
	~Euro();

	//Getter Functions
	std::string getNote();
	int getWhole();
	int getFraction();
	std::string getCoin();

	//Mutator Functions
	void setWhole(int mo);
	void setFraction(int ce);

	//Overloaded operators
	Euro operator + (const Euro &);
	Euro operator - (const Euro &);
	bool operator > (const Euro &);
	bool operator < (const Euro &);
	bool operator == (const Euro &);

	friend std::ostream &operator << (std::ostream &, const Euro &);
};
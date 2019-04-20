#pragma once
#include "Currency.h"
#include <iostream>
#include <string>

class Yen : public Currency
{
protected:

public:
	//Constructor
	Yen();
	//Constructor to accept initialization values
	Yen(int wh, int fr);
	~Yen();

	//Getter Functions
	std::string getNote();
	int getWhole();
	int getFraction();
	std::string getCoin();

	//Mutator Functions
	void setWhole(int mo);
	void setFraction(int ce);

	//Overloaded operators
	Yen operator + (const Yen &);
	Yen operator - (const Yen &);
	bool operator > (const Yen &);
	bool operator < (const Yen &);
	bool operator == (const Yen &);

	friend std::ostream &operator << (std::ostream &, const Yen &);
};
#pragma once
#include "Currency.h"
#include <iostream>
#include <string>

class Rupee : public Currency
{
protected:

public:
	//Constructor
	Rupee();
	//Constructor to accept initialization values
	Rupee(int wh, int fr);
	~Rupee();

	//Getter Functions
	std::string getNote();
	int getWhole();
	int getFraction();
	std::string getCoin();

	//Mutator Functions
	void setWhole(int mo);
	void setFraction(int ce);

	//Overloaded operators
	Rupee operator + (const Rupee &);
	Rupee operator - (const Rupee &);
	bool operator > (const Rupee &);
	bool operator < (const Rupee &);
	bool operator == (const Rupee &);

	friend std::ostream &operator << (std::ostream &, const Rupee&);
};
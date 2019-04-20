#pragma once
#include "Currency.h"
#include <iostream>
#include <string>

class Yuan : public Currency
{
protected:

public:
	//Constructor
	Yuan();
	//Constructor to accept initialization values
	Yuan(int wh, int fr);
	~Yuan();

	//Getter Functions
	std::string getNote();
	int getWhole();
	int getFraction();
	std::string getCoin();

	//Mutator Functions
	void setWhole(int mo);
	void setFraction(int ce);

	//Overloaded operators
	Yuan operator + (const Yuan &);
	Yuan operator - (const Yuan &);
	bool operator > (const Yuan &);
	bool operator < (const Yuan &);
	bool operator == (const Yuan &);

	friend std::ostream &operator << (std::ostream &, const Yuan &);
};
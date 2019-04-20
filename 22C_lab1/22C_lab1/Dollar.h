#pragma once
#include "Currency.h"
#include <iostream>
#include <string>

class Dollar : public Currency
{
protected:

public:
	//Constructor
	Dollar();
	//Constructor to accept initialization values
	Dollar(int wh, int fr);
	//Destructor
	~Dollar();

	//Getter Functions
	std::string getNote();
	int getWhole();
	int getFraction();
	std::string getCoin();

	//Mutator Functions
	void setWhole(int mo);
	void setFraction(int ce);

	//Overloaded operators
	Dollar operator + (const Dollar &);
	Dollar operator - (const Dollar &);
	bool operator > (const Dollar &);
	bool operator < (const Dollar &);
	bool operator == (const Dollar &);

};